# CCIMP
**Cerveceros Codigo Image Manipulation Program** - Prosjektoppgave C++ HiOA 2015

### Gruppemedlemmer
* [Espen Zaal](https://github.com/lurer) - s198579
* [Lukas Larsed](https://github.com/ldlarsed) - s198599
* [Petter Lysne](https://github.com/petlys) - s198569


# Sluttrapport

## Om sluttrapporten
Det brukes ikke mye tid på å forklare alle aspektene ved programmet, men heller å forklare hvorfor programmet er implementert slik det er gjort, og hva som er spesielt med arkitekturen.

## Hva er vektlagt
Muligheter for "evig" utvidelse av funksjonalitet og høyere kompleksitet har vært viktig. Det har ikke vært viktig å "komme i mål", ettersom det ville være vanskelig å beregne. Samtidig skal alt som er implementert fungere.
For å få uttelling for kompleksitet og omfang har det også programmet blitt implementert på en slik måte som legger til rette for lav kobling mellom klasser og høy kohesjon. Programmer er derfor sydd sammen ved hjelp av lyttere (observer-pattern) og event-drevne metoder som "fyrer" i gang metoder i andre deler av programmet i det en metoden eksekveres i feks MainWindow. Mer om dette i kommentarene til diagrammene lenger ned.


## Viktige linker
* [prosjektbeskrivelse.md](prosjektbeskrivelse.md)

## Eksterne resurser
* Programikoner er hentet fra [Oxygen Icons prosjekt](https://github.com/pasnox/oxygen-icons-png)
* Til noen bildebehandlingsprosesser bruker [ImageMagick++ rammeverk](http://www.imagemagick.org/script/magick++.php)

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
Som nevnt i introduksjonen så er utgangspunktet for prosjektet at det skal gi uttelling for avansert arkitektur og prosjektets omfang. Helt konkret betyr det at det er veldig lav kobling mellom lagene i programmet, og at all kommunikasjon skjer via observer-interface og callback-interface.
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
2. 

![Oppdatering av bilde](http://cerveceroscodigo.github.io/CCIMP/img/diagram_update_image.png)


### Hvordan historikk og angremulighet fungerer
![Håndtering av historikk](http://cerveceroscodigo.github.io/CCIMP/img/diagram_history_redo_undo.png)
    