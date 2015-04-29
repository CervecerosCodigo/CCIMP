# CCIMP
**Cerveceros Codigo Image Manipulation Program** - Prosjektoppgave C++ HiOA 2015

## Gruppemedlemmer
* [Espen Zaal](https://github.com/lurer)
* [Lukas Larsed](https://github.com/ldlarsed)
* [Petter Lysne](https://github.com/petlys)

## Viktige linker
* [prosjektbeskrivelse.md](prosjektbeskrivelse.md)

##Eksterne resurser
* Programikoner er hentet fra [Oxygen Icons prosjekt](https://github.com/pasnox/oxygen-icons-png)
* Til noen bildebehandlingsprosesser bruker [ImageMagick++ rammeverk](http://www.imagemagick.org/script/magick++.php)

##Kompilering
CCIMP krever følgende bilbiotek for å kompileres.

1. [**Qt5**](https://www.qt.io/download-open-source/)
2. **ImageMagick++**
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
    * Installer `ImageMagick` pakke via Mac Ports eller Homebrew. Sørg for at det følger med `development` pakker.   * Sørg for at `macx` konfigurasjon i `CCIMP.pro` filen peker til riktig plass på platelagret.
