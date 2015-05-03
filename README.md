# CCIMP
**Cerveceros Codigo Image Manipulation Program** - Prosjektoppgave C++ HiOA 2015

### Gruppemedlemmer
* [Espen Zaal](https://github.com/lurer) - s198579
* [Lukas Larsed](https://github.com/ldlarsed) - s198599
* [Petter Lysne](https://github.com/petlys) - s198569

# Sluttrapport

## Innholdsfortegnelse

* [Introduksjon](#kap1)
* [Installasjon](#kap2)
* [Arkitektur og design](#kap3)
* [Om arbeidet, og utfordringene](#kap4)
* [Mangler](#kap5)


<a id="kap1"></a>
## Introduksjon 

### Om sluttrapporten
Sluttrapporten forsøker å gi oversikt over strukturen av programmet ved hjelp av en type flytdiagrammer, som forklarer hvordan kommunikasjonen fungerer mellom de ulike lagene i programmet. Det kommer også noen punkter om hvordan arbeidet har gått, hvilke utfordringer det har vært jobbet mest med, samt en egen vurdering av prosjektet og hva som kunne vært gjort annerledes.

### Hva er vektlagt
Muligheter for "evig" utvidelse av funksjonalitet og høyere kompleksitet har vært viktig. Det har ikke vært viktig å "komme i mål", ettersom det ville være vanskelig å beregne. Samtidig skal alt som er implementert fungere.
For å få uttelling for kompleksitet og omfang har også programmet blitt implementert på en slik måte som legger til rette for lav kobling mellom klasser og høy kohesjon. Programmer er derfor sydd sammen ved hjelp av lyttere (observer-pattern) og event-drevne metoder som "fyrer" i gang metoder i andre deler av programmet i det en metoden eksekveres i feks MainWindow. Mer om dette i kommentarene til diagrammene lenger ned.


### Viktige linker
* [prosjektbeskrivelse.md](prosjektbeskrivelse.md)
* [Klassediagram](http://cerveceroscodigo.github.io/CCIMP/img/diagram_class.png)
* [Dokumentasjon for kildekode](http://cerveceroscodigo.github.io/CCIMP/doc/)

### Eksterne resurser
* Programikoner er hentet fra [Oxygen Icons prosjekt](https://github.com/pasnox/oxygen-icons-png)
* Biblioteket brukt for bildebehandling [ImageMagick++ rammeverk](http://www.imagemagick.org/script/magick++.php). ImageMagick++ er en del av ImageMagick pakken som innholder terminalbaserte bildeediteringsverktøy. 


<a id="kap2"></a>
## Installasjon 

### Binærer
Det finnes ferdige binærer kompilert for x86_64 arkitekur tilgjengelige for Linux og MAC OSX. Disse er tilgjengelige under [releases](https://github.com/CervecerosCodigo/CCIMP/releases).


### Kompilering

#### Generelt
For å kompilere CCIMP fra kildekoder trenger du følgende verktøy. 

1. **GNU GCC C++** kompilator.
2. [**Qt 5** utviklingsmiljø](https://www.qt.io/download-open-source/) med Qt Creator.
3. **ImageMagick++** bilbiotek.

Hvis du har installert alle nødvendige pakker og avhengigheter åpnes prosjektet i Qt Creator fra `CCIMP.pro` filen. 

#### ImageMagick
Ettersom CCIMP er dynamisk linket med ImageMagick++ må den være installert på systemet ditt før kompilering. Kompilering av CCIMP ble med fremgang gjennomført på Ubuntu 14.10, Fedora 21 og MAC OSX Yosemite. Etter at ImageMagick++ bibliotek er installert kommer `qmake` å forsøke linke delte bilbiotek fra den søkvei som er definiert i [CCIMP.pro](https://github.com/CervecerosCodigo/CCIMP/blob/master/src/ccimp.pro) filen. Dersom du støtter på eventuelle problem med delte bilbiotek kontrollerer hvis CCIMP.pro er linket til riktig søkvei og versjon som stemmer overens ImageMagick++ installasjon på din maskin.

##### Linux
Hvis ImageMagick installeres via repo til din distrubisjon kan søkvei til bibliotekene være annerledes. Dersom du ønsker å bruke development pakker for ditt system (Fedora: `ImageMagick-c++-devel`, Ubuntu: `libmagick++-dev`) må du konfigurere om [CCIMP.pro](https://github.com/CervecerosCodigo/CCIMP/blob/master/src/ccimp.pro) slik at den overensstemmer med søkveien til bilbiotekene på ditt system. 

Vi **anbefaler sterkt** at ImageMagick kompileres fra kildekode ettersom søkveien for installasjonen blir densamme for alle Linux system.

Før kompilering
I tillegg til `GNU GCC C++` kommer du også å behøve [`GNU libtool`](http://www.gnu.org/software/libtool/), den installerer du enklest gjennom repository for din distribusjon. Dette gjør enklest på følgende måte:

Ubuntu/Debian
```
$ sudo apt-get update
$ sudo apt-get install libltdl-dev
```

Fedora
```
# yum install libtool-ltdl-devel
```

Deretter følg følgende tilnærmingsmåte for å sette opp ImageMagick på ditt system:

```
1. wget http://www.imagemagick.org/download/ImageMagick.tar.gz
2. tar xfvz ./ImageMagick.tar.gz
3. cd ImageMagick/
4. ./configure --enable-shared --with-modules
5. make 
6. sudo make install 
7. sudo ldconfig /usr/local/lib
```

Det er ytterst viktig at konfigurering kjøres med flagger `--enable-shared --with-modules` ettersom automake vil da sette opp kompilering og installasjon av delte `*.so` bilbiotek.

##### MAC OSX
[CCIMP.pro](https://github.com/CervecerosCodigo/CCIMP/blob/master/src/ccimp.pro) er konfigurert for [Mac Port versjon](https://www.macports.org/ports.php?by=name&substr=ImageMagick) som innholder development bilbiotek.

    
    
<a id="kap3"></a>
## Arkitektur og design 

### Hvorfor er designet som det er
Som nevnt i introduksjonen så er utgangspunktet for prosjektet at det skal gi uttelling for avansert arkitektur og for prosjektets omfang. Helt konkret betyr det at det er veldig lav kobling mellom lagene i programmet, og at all kommunikasjon skjer via observer-interface og callback-interface.
Det er laget tre diagrammer som hver for seg skal illustrere hvordan den ulike kommunikasjonen skjer. 


### Instansiering og registrering av verktøy
Dette diagrammet skisserer hvordan programmet starter opp, og hvordan man instansierer verktøyene og hvordan de blir registrert. 
Hvert punkt i denne liten korresponderer med de røde punktene i diagrammet.

1. Klassen `build_tools` oppretter alle verktøyene, og i det verktøyet blir instansiert så registreres det automatisk via `controller_iface`. Dette skjer i klassen `tool` sin konstruktør. `tool`-instansen har nå gjennom å arve `image_tool` en parameter-instans som sier noe om hvilke type parametere verktøyet vil benytte seg av i brukergrensesnittet. Feks så vil Contrast-verktøyet ha behov for en `slider` som man kan justere dynamisk.
2. Klassen `controller` er et bindeledd i programmet, men brukes aldri i sin konkrete form. Den implementerer interfacet `controller_iface` som har en `registrer_tool(image_tool* t)`-metode. Denne bruker switch-case for å finne rett set-metode i `MainWindow`. Hver `image_tool` har en enum-variabel (`TOOLIDENT`), som leses av og som det testes på i switch-case.
3. `Controller` registrerer som sagt `image_tool` i `MainWindow` ved å kalle på rett set-metode.
4. Hvert verktøy i `MainWindow` er implementert i form av egen klasse, som arver den abstrakte klassen `ccimp_dialog`. Det er denne superklassen som lagrer `image_tool` og som brukes i det man velger å utføre endring på et bilde.

Det finnes altså ingen direkte kontakt mellom `tools` i helt "nede" i programmet og `controller` og heller ikke opp til `MainWindow`. Etter at alt er instansiert så finnes det heller ingen tilgang til noe av det som ligger "under `controller`, annet enn gjennom den instansen av `image_tool` som finnes i hver dialog-vindu. I det man trykker på en knapp i verktøylinjen til høyre i programmet så settes rett `image_tool` via interfacet `event_listener`, ned via `controller` og ned til `image_wrapper`, som utfører `image_tool` sin `execute()`-metode. Dette kommer det mer om senere.
![Bygging og instansiering](http://cerveceroscodigo.github.io/CCIMP/img/diagram_build_tools.png)


### Prosessen som utføres ved endring av et bilde
Dette diagrammet tar for seg prosessen som utføres hver gang man endrer et bilde ved å bruke et av verktøyene i `MainWindow`. I det man åpner et bilde via utforskeren på i venstre del av programmet, eller via Open-funksjonen så sendes `QImage`-referansen ned til `image_wrapper` via interfacet `event_listener`. Det er altså `image_wrapper` som holder utfører alle operasjoner på bildet, og som returnerer det endrede bildet til `MainWindow`. 

1. Hvert dialog-vindu eller implementasjon av verktøy som man kan klikke på og bruke i `MainWindow` har via arv fra `ccimp_dialog` en `image_tool` og en parameter-instans. Ved editering vil innholdet i den aktuelle parameter-instansen endres, og den rette metoden kjøres i `MainWindow`.
2. `MainWindow` bruker sin instans av `event_listener`-interface til å kommunisere nedover i systemet, og bruker `event_listen->update_image()` for å utføre jobben med å editere bildet.
3. `Controller` som implementerer `event_listener`-interfacet har bare ""pass-through"-metoder ned til `image_wrapper`.
4. `image_wrapper` utfører oppdateringen av bildet ved å kjøre `current_tool->execute(Image* omg)`. `current_tool` ble satt i det verktøyet ble åpnet i `MainWindow` og i det selve utførelsen av det rette verktøyet blir gjort så benyttes parameter-verdiene som ble satt i `slideren`.
5. Resulatet av editeringen sendes så opp til `MainWindow` via `callback->callback_image_edited(QImage*)`. 

![Oppdatering av bilde](http://cerveceroscodigo.github.io/CCIMP/img/diagram_update_image.png)


### Hvordan historikk og angremulighet fungerer

Èn av hovedgrunnene til at arkitekturen er så omfattende som den er, er fordi alle moduler og klasser skal være så løst koblet som mulig, og gi fleksibilitet og dermed en bedre håndtering av historikk og angremulighet. 
Avhengig av hvilke verktøy man velger å bruke i `MainWindow` så vil det være opp til tre mulige konsekvenser som blir utført. Diagrammet bruker `blur_dialog` som eksempel.
Man har i det eksempelet tre utfall:

* Change
* OK
* Cancel


**Change -`image_update()`**
Dette er utfallet av midlertidige endringer. Altså i det man arbeider med et verktøy, før man velger å enten bekrefte eller avbryte. Alle `image_update()` tar utgangspunktet i at `img_ptr_current*` som ligger i `image_wrapper`er den rette versjonen av bildet som vises på skjermen. Arbeidet skjer på en kopi av denne versjonen, i en variabel kalt `img_ptr_edit*`. 

**OK - `image_finished()`**
I det man trykker OK for å bekrefter at man er ferdig med editeringen, i det verktøyet i alle fall, så sendes en forespørsel til `image_wrapper` at den nå skal sette `img_ptr_current` lik `img_ptr_edit`. Dette vil gjøre status klart for neste verktøy, om det skulle være aktuelt.

**Cancel - `image_canceled()`**
I det man jobber med et verktøy, men ønsker å avbryte så kan man gjøre det ved å trykke på Cancel. Dette medfører et kall til `image_wrapper` som vil sette `img_ptr_edit` lik `img_ptr_current`. Det vil si at mange angrer endringene gjort i `img_ptr_edit`, altså i det verktøyet man jobber med for øyeblikket. Dette er ikke det samme som "undo".

**Undo og Redo**
I det man klikker på et verktøy i `MainWindow` og man sender den aktuelle `image_tool` til `image_wrapper` så legges også en kopi av det aktuelle bildet som vises på skjermen inn i `undo_vector`. Algoritmene for undo, redo er lettere å inspisere i koden i `image_wrapper` enn å forklare, men kommunikasjonen mellom `MainWindow` og `image_wrapper` er som ved de andre punktene.



![Håndtering av historikk](http://cerveceroscodigo.github.io/CCIMP/img/diagram_history_redo_undo.png)



<a id="kap4"></a>
## Om arbeidet, og utfordringene 

* Det utpekte seg flere utfordringer underveis og som tok mye tid. Spesielt i begynnelsen. Man skal lære seg Qt og hvordan man benytter seg av de ulike modulene det medfører. Det gjaldt spesielt hvordan Qt og Qwidgets sammen med Slots og Signals ikke egner seg så godt til arv og generiske fremgangsmåter.
* Videre har det vært utfordrende å finne ut om det skulle brukes 3. parts programvare eller ikke. I utgangspunktet skulle programmet lages i noe mindre skala, men med forsøk på egne filter-algoritmer, men da ingen i gruppen visste noe som helst om hvordan å løper gjennom pixler og behandle dem så ble det forsøkt med først ett eksternt bibliotek, som ikke førte frem, og så med det andre, som er i bruk.
* Arkitekturen av programmet var også gjenstand for mye tenking og eksperimentering. Kravet til gruppen var at det skulle være modulerbart og ta høyde for historikk. Det ble gjort flere forsøk på å komme frem til et design før det nåværende designet ble akseptert.


<a id="kap5"></a>
## Mangler, bugs og svakheter i design 

### Mangler

* Opprinnelig ble det bestemt at programmet skulle støtte arkfaner, slik at hvert bilde man åpnet ble åpnet i en ny arkfane, og at hver arkfane hadde sin egen historikk, slik som dagens "en-bildes-løsning" har. `Controller` ville da hatt en viktigere rolle, med av alle `image_wrapper`-objektene, men det ikke var tid til å finne ut hvordan arkfaner brukes ble det ikke ferdigstillt. Dette er dog et mindre prosjekt hvis man skulle ønske å gå videre med utviklingen. Arkitekturen har i vedlig stor grad tatt høyde for denne utvidelsen. 
* Et annet viktig mål som var satt, men som åpenbart ville være vanskelig å få til var å tilpasse programmet slik at man kunne utviklet 3. parts bildebehandlingsfiltre, som plugins, og koblet dem inn i programmet dynamisk. Dette kunne man oppnådd ved ågi tilgang til de rette interface og header-filer, men som det nevnes mer om i punktet om svakheter i designet så var det andre utfordringer som var med på å stoppe denne funksjonaliteten. 

### Bugs

De aller fleste bugs er luket ut. Det ligger en liste med `Issues` i [git-repoet](https://github.com/CervecerosCodigo/CCIMP/issues) som lister kort de gjenstående bugs.

### Svakheter i design

* Om en tenker at komplekst design er en svakhet så kan dette være et reelt punkt. Det har for noen vært ganske vanskelig i noen tilfeller å forholde seg til hvor det enkelte metodekall ender opp, og hvordan alt henger sammen. For et så lite program så kan det diskuteres om det kunne vært gjort på en enkelere og mer oversiktelig måte, men ved å ta de nødvendige steg for å holde abstraksjonen høy nok, så har også det gitt større fleksibilitet og fremtidig utvidbarhet. Det er først når man får flere uavhengige moduler at kraften til et komplekst design kommer til sin rett. Dog må det være komplekst fordi det skal løse en oppgave, ikke bare for kompleksitetens skyld. Det har vært gruppens mål å lage noe som krever kompleksitet, for å få uttelling på dette.
* Qt tilbyr Slots og Signals som gjør det lett å koble sammen events og triggere. Dette er likevel en fallgruve, da man må koble ferdigdefinerte signals til slots, og muligheten for å opprette gui-komponenter med tilhørende eventer og triggere ble redusert kraftig. Om man skulle implementert plugin-funksjonalitet av nye filtre så måtte også tilhørende GUI-komponenter kunne opprettes dynamisk. Hvordan det skulle vært gjort med bruk av slots og signals ble ikke klart og denne planen ble derfor ikke gjennomført. Alternativet hadde vært å bruke egendefinerte observer/event-patterns for alle slike "listen for events" i GUI, men tiden ble for knapp for det. Dette medførte at man endte opp med en Switch/Case i `Controller`, som nok ikke er særlig dynamsik, og tilsvarende enum `TOOLIDENT` som identifiserer hvert verktøy, og som switch/case switsjer på. Dette er som skulle vært unngått om man hadde fått begynt på nytt.
* `MainWindow` er også veldig overfylt med metoder og slots. Alle set-metodene til knappene/verktøyene, samt alle "on_button_clicked"-metoder kunne vært flyttet ut i en egen klasse, ettersom dette strengt tatt ikke kommuniserer med mer enn tre metoder i `MainWindow`. Hadde gruppen hatt 2 dager til så hadde dette blit gjort. 


    
