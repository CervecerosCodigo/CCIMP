# CCIMP
**Cerveceros Codigo Image Manipulation Program** - Prosjektoppgave C++ HiOA 2015

### Gruppemedlemmer
* [Espen Zaal](https://github.com/lurer) - s198579
* [Lukas Larsed](https://github.com/ldlarsed) - s198599
* [Petter Lysne](https://github.com/petlys) - s198569


# Sluttrapport

## Om sluttrapporten
Sluttrapporten forsøker å gi oversikt over strukturen av programmet ved hjelp av en slags flytdiagrammer, som forklarer hvordan kommunikasjonen fungerer mellom de ulike lagene i programmet. Det kommer også noen punkter om hvordan arbeidet har gått, hvilke utfordringer det har vært jobbet mest med, samt en egen vurdering av prosjektet og hva som kunne vært gjort annerledes.

## Hva er vektlagt
Muligheter for "evig" utvidelse av funksjonalitet og høyere kompleksitet har vært viktig. Det har ikke vært viktig å "komme i mål", ettersom det ville være vanskelig å beregne. Samtidig skal alt som er implementert fungere.
For å få uttelling for kompleksitet og omfang har også programmet blitt implementert på en slik måte som legger til rette for lav kobling mellom klasser og høy kohesjon. Programmer er derfor sydd sammen ved hjelp av lyttere (observer-pattern) og event-drevne metoder som "fyrer" i gang metoder i andre deler av programmet i det en metoden eksekveres i feks MainWindow. Mer om dette i kommentarene til diagrammene lenger ned.


## Viktige linker
* [prosjektbeskrivelse.md](prosjektbeskrivelse.md)

## Eksterne resurser
* Programikoner er hentet fra [Oxygen Icons prosjekt](https://github.com/pasnox/oxygen-icons-png)
* Biblioteket brukt for bildebehandling [ImageMagick++ rammeverk](http://www.imagemagick.org/script/magick++.php)

## Kompilering
CCIMP krever følgende bilbiotek for å kompileres.

1. **gnu gcc-c++**  Sørg for at gnu `libtool-ltdl-devel` (eller en liknende versjon av pakken) er tilgjengelig, den er nødvendig for å kompilere ImageMagick++.
2. [**Qt5**](https://www.qt.io/download-open-source/)
3. **ImageMagick++**
  * Linux
    * Det anbefales at biblioteket kompileres fra kilde hvilket vil gjøre den kompatibel med `CCIMP.pro` konfigurasjonen for qmake uavhengig av distribusjon. 
    * Seineste versjon av ImageMagick++ er tilgjengelig [her.](http://www.imagemagick.org/download/ImageMagick.tar.gz)
    * For at delte bibliotek skla gjøres tilgjengelige må konfigurasjonen kjøres med flagger `--enable-shared --with-modules` kompilering og installasjon må gjøres i følgende trinn:
    
      ```
      1. ./configure --enable-shared --with-modules
      2. make 
      3. sudo make install 
      4. sudo ldconfig /usr/local/lib
      ```
 
  * MAC O$X
    * Installer `ImageMagick` pakke via Mac Ports eller Homebrew. Sørg for at det følger med `development` pakker.   
    * Sørg for at `macx` konfigurasjon i `CCIMP.pro` filen peker til riktig plass på platelagret.

    
    
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


## Om arbeidet, og utfordringene

Det utpekte seg flere utfordringer underveis og som tok mye tid. Spesielt i begynnelsen. Man skal lære seg Qt og hvordan man benytter seg av de ulike modulene det medfører. Det gjaldt spesielt hvordan Qt og Qwidgets sammen med Slots og Signals ikke egner seg så godt til arv og generiske fremgangsmåter.
Videre har det vært utfordrende å finne ut om det skulle brukes 3. parts programvare eller ikke. I utgangspunktet skulle programmet lages i noe mindre skala, men med forsøk på egne filter-algoritmer, men da ingen i gruppen visste noe som helst om hvordan å løper gjennom pixler og behandle dem så ble det forsøkt med først ett eksternt bibliotek, som ikke førte frem, og så med det andre, som er i bruk.
Arkitekturen av programmet var også gjenstand for mye tenking og eksperimentering. Kravet til gruppen var at det skulle være modulerbart og ta høyde for historikk. Det ble gjort flere forsøk på å komme frem til et design før det nåværende designet ble akseptert.


## Mangler og bugs

### Mangler

Opprinnelig ble det bestemt at programmet skulle støtte arkfaner, slik at hvert bilde man åpnet ble åpnet i en ny arkfane, og at hver arkfane hadde sin egen historikk, slik som dagens "en-bildes-løsning" har. `Controller` ville da hatt en viktigere rolle, med av alle `image_wrapper`-objektene, men d det ikke var tid til å finne ut hvordan arkfaner brukes ble det ikke ferdigstillt. Dette er dog et mindre prosjekt hvis man skulle ønske å gå videre med utviklingen. Arkitekturen har i vedlig stor grad tatt høyde for denne utvidelsen. 


    