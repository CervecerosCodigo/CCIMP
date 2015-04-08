#Prosjektbeskrivelse

##Om programmet 
CCIMP (Cerveceros Codigo Image Manipulation Program) skal gi mulighet å editere pixelgrafikk med hjelp av innstiksfiltre utviklet av CCIMP communityen. Programmet er i grunn og bunn en gui som har støtte for å lese inn og lagre bildefiler. 
Fokus på god separering av funksjonalitet, og mulighet for "undo/redo"-funksjonalitet er viktig. 
Programmet er delt opp slik at hvert filter/verktøy finnes i tre versjoner i form av Commands; Execute, Undo og Redo. Commands har en set-metode som setter et bilde inn på det relevantet filteret og behandles, før en returnerer det nye bildet til controller og deretter GUI. Controller har en liste over alle Commands som er tilgjenglig for valg i GUI. Man kan ha flere bilder åpne som "tabs", og hvert av dem har sin egen historikk. Det vil si vectorer med undo og redo-kommandoer.

Programmet blir i stor utstrekking skalerbart ettersom filtrene som inngår er helt separate fra gui eller logikken i programmet. Dersom filtrene utvikles etter en fordefiniert mal kan disse deretter kompileres til et bilbiotek som skal være mulig å lese inn i CCIMP som et nytt filter. Det er tenkt at hvert filter skal bidra med både algoritme for den bildebehandlig som den skal gjøre og en gui komponent lagt i kopatimbelt qt versjon som skal gi mulighet til å kontrollere filteret. 

##Suksesskriterier
###Må oppfylles
Programmet starter, alle deler av GUI er implementert. Det er mulig å lese inn og lagre et bilde på samme eller ny plassering. Det implementert minimum tre fristående filtre som er innkludert på forhånd i programmet. 
###Ekstra 1
Flere filtre som kan benyttes i programmet. Filtrene i dette stadiet er begrenset til ren bildebehandling.
###Esktra 2
Ekstra funksjonalitet som går ut på andre filtre som kan vise programmets versitalitet som feks filtre som kan benyttes til å lagre krypterte medlinger i programmet (se gjerne avsnitt om brukerhistorer).

##Avgrensninger


##User stories
###Implemeteres
* Som bruker ønsker jeg å editere pixelgrafikk. 
* Som bruker ønsker jeg å åpne å lagre bilder.
* Som bruker ønsker jeg å benytte meg av eksterne bildefiltre.
* Som bruker ønsker jeg å angre eller gjøre om endringer i et åpent bilde.
* Som bruker ønsker jeg å zoome inn og ut av et bilde.
* Som bruker ønsker jeg å panorere bilde dersom det fyller opp over 100% av tilgjengelig lerett.
* Som bruker ønsker jeg å ha mulighet å bleddre i filstrukturen på maskinen slik at det filtreres på kund godkjente bildefiler.
###Optional (dersom vi får tid)
* Som bruker ønsker jeg å bruke filtre på batcher av filer.
* Som utvikler ønsker jeg å implementere bruke av andre typer av filtre som gir annen type av funksjonalitet enn kun ren bildebehandling, feks. et filter som kan lagre en kryptert melding i et bilde. 
* Som utvikler ønsker jeg å implementere egne måter å komprimere bilder på, feks egen implementasjon av Huffmann komprimering som lagrer den komprimerte dasta i et eget filformat.

##GUI mockup

**Mockup 1**
![Mockup 1](http://cerveceroscodigo.github.io/CCIMP/img/mockup1.jpg)

**Mockup 2**
![Mockup 2](http://cerveceroscodigo.github.io/CCIMP/img/mockup2.jpg)
Mockupen er oprettet direkte i Qt creator.

##Klassediagram
Her følger et forslag til klassediagram. Det er ikke tatt hensyn til GUI eller relaterte klasser av QT her, men bare fokus på det strukturelle som har med "model" og "controller". Det er ikke tatt standpunkt til hvilke funksjoner vi trenger for alle klasser, og en god del endringer kan bli gjort her. Det er en del å lære om hvordan å behandle bilder.
All funksjonaliteten til QT, om hvordan å vise en filstruktur, og generelt hva som skal til for å få GUI til å fungere er noe som også vil kreve en del klasser. 
Sist må det nevnes at UML-diagrammet ikke er godt egnet for å vise Template-parametere og all den informasjonen vi gjerne vil ha med. Det er heller ikke tatt med bruk av pekere/referanser ol.
**Klassediagram**
![Klassediagram](http://cerveceroscodigo.github.io/CCIMP/img/klassediargram_forslag.jpg)

##Valgt teknologi
* C++ og GNU g++
* Qt5 rammeverk
* Qt Creator (kompileres med qmake)

##Versjonsoppfølgnig
Til versjonoppfølgning brukes det git som hostes på github under følgende adresse: [https://github.com/CervecerosCodigo/CCIMP](https://github.com/CervecerosCodigo/CCIMP)
Repositoryen er satt som private med tilgang til for kun prosjektmedlemmer og lærer. 

##Arbeidsfordeling


##Tidsplan
