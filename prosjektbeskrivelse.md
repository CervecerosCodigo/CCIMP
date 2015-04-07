#Prosjektbeskrivelse

##Om programmet 
CCIMP (Cerveceros Codigo Image Manipulation Program) skal gi mulighet å editere pixelgrafikk med hjelp av innstiksfiltre utviklet av CCIMP communityen. Programmet er i grunn og bunn en gui som har støtte for å lese inn og lagre bildefiler. Programmet kan sender fra seg en stream med rgb verdier for hver piksel i bildet. Streamen med bilder sendes deretter til en av de mulige filtre og sendes tilbake til programmets lerett som viser den endrede versjonen av bildet. Samme operasjon gjentas dersom brukeren valger å bruke et annet filter etterpå. Alle operasjoner som gjøres av filtrene blir lagret internt i en vektor slik at brukeren får mulighet til å benytte seg av “ångre” eller “gjør om” operasjon. 

Programmet blir i stor utstrekking skalerbart ettersom filtrene som inngår er helt separate fra gui eller logikken i programmet. Dersom filtrene utvikles etter en fordefiniert mal kan disse deretter kompileres til et bilbiotek som skal være mulig å lese inn i CCIMP som et nytt filter. Det er tenkt at hvert filter skal bidre med både algoritme for den bildebehandlig som den skal gjøre og en gui komponent lagt i kopatimbelt qt versjon som skal gi mulighet til å kontrollere filteret. 

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

##Valgt teknologi
* C++ og GNU g++
* Qt5 rammeverk
* Qt Creator (kompileres med qmake)

##Versjonsoppfølgnig
Til versjonoppfølgning brukes det git som hostes på github under følgende adresse: [https://github.com/CervecerosCodigo/CCIMP](https://github.com/CervecerosCodigo/CCIMP)
Repositoryen er satt som private med tilgang til for kun prosjektmedlemmer og lærer. 

##Arbeidsfordeling


##Tidsplan
