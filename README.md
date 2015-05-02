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

**Instansiering og registrering av verktøy**

![Bygging og instansiering](http://cerveceroscodigo.github.io/CCIMP/img/diagram_build_tools.png)

**Prosessen som utføres ved endring av et bilde**
![Oppdatering av bilde](http://cerveceroscodigo.github.io/CCIMP/img/diagram_update_image.png)

**Hvordan historikk og angremulighet fungerer**
![Håndtering av historikk](http://cerveceroscodigo.github.io/CCIMP/img/diagram_history_redo_undo.png)
    