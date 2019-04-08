# 3 užduotis. Duomenų apdorojimas. Klasės.
## Programos tikslas
Programa nuskaito mokinio vardą, pavardę,egzamino įvertinimą ir -make namų darbų įvertinimus, tuomet, paskaičiavusi galutinį studento pažymį, programa lentelėje išveda visų studentų galutinius pažymius, vardus ir pavardes.  
**Nuo v0.4 programos tikslas yra ir patikrinti kaip sparčiai programa gali atlikti šią užduotį ir kaip jos sparta priklauso nuo pradinių duomenų failo dydžio**  
## Makefile komandos  
-make vector: sukuria failą `vector.exe`.  
-make deque: sukuria failą `deque.exe`.  
-make list: sukuria failą `list.exe`.  
-make generavimas: sukuria failą `generavimas.exe` ir sugeneruoja 5 mokinių failus (nuo 100 iki 1 000 000 eilučių).
-make funkcijos: sukurią failą `function.o`.   
-make valymas: ištrina programų paleidimo failus `*.exe` ir visus failus programos sukurtus šailus su pabaiga `.o` arba `.txt` išskyrus `Laiku_suvestine.txt`.   
## Programos paleidimas   
-Įjungti terminalą (komandinę eilutę) ir įvesti komandą `make vector/make list/make deque`.   
-Tuomet, parašyti komandą `./vector` arba atitinkamą kito konteinerio programos pavadinimą (arba paleisti sukurtą failą `vector.exe`).  
**Windows operacinėje sistemoje šios komandos neveikia, reikia naudoti `g++ -o programa 2_uzduotis_vektoriai.cpp function.cpp`**  
## Išvedimo pavyzdys
```shell
Vardas Pavardė  Galutinis
-------------------------
Matas  Čenys    8.86
```
## Programos naudojimas
Norint, kad programa nuskaitytų duomenis iš failo, reikia papildyti prie programos prisegtą failą „kursiokai.txt“. Pirmoji failo eilute yra skirta stulpelių aprašymams, todėl į ją negalima įrašyti duomenų, o nuo antrosios eilutės galima įrašinėti duomenis.  
**Pradėjus laiko matavimus ir optimizavimus, sukurti 5 tekstiniai pradinių duomenų failai mokiniai1.txt, mokiniai2.txt ir t.t.**  
Tekstinio failo pavyzdys:  
```shell
Matas    Cenys     8     9     6     9
Kasparas  Bražėnas   9    5     8     10
```
## Programos veikimo rezultatai
### Versijos 1.1 veikimo rezultatai  
```shell
**Struct:**
---------------------------------------------------    
10000 eiluciu failo apdorojimo laikas = 0.17057 s.    
100000 eiluciu failo apdorojimo laikas = 1.65955 s.   
---------------------------------------------------    
10000 eiluciu failo apdorojimo laikas = 0.182659 s.  
100000 eiluciu failo apdorojimo laikas = 1.66203 s.  
---------------------------------------------------  
10000 eiluciu failo apdorojimo laikas = 0.173914 s.  
100000 eiluciu failo apdorojimo laikas = 1.65689 s.  
---------------------------------------------------  
**Class:**  
---------------------------------------------------  
10000 eiluciu failo apdorojimo laikas = 0.172632 s.  
100000 eiluciu failo apdorojimo laikas = 1.736 s.  
---------------------------------------------------  
10000 eiluciu failo apdorojimo laikas = 0.170187 s.  
100000 eiluciu failo apdorojimo laikas = 1.75452 s.  
---------------------------------------------------  
10000 eiluciu failo apdorojimo laikas = 0.173026 s.  
100000 eiluciu failo apdorojimo laikas = 1.77342 s.  
---------------------------------------------------  
**Optimizavimo rezultatai**  
**Struct:**  
---------------------------------------------------  
**01**  
---------------------------------------------------  
10000 eiluciu failo apdorojimo laikas = 0.167648 s.  
100000 eiluciu failo apdorojimo laikas = 1.64327 s.  
---------------------------------------------------  
10000 eiluciu failo apdorojimo laikas = 0.191989 s.  
100000 eiluciu failo apdorojimo laikas = 1.66021 s.  
---------------------------------------------------  
10000 eiluciu failo apdorojimo laikas = 0.166067 s.  
100000 eiluciu failo apdorojimo laikas = 1.66755 s.  
**02**  
---------------------------------------------------  
10000 eiluciu failo apdorojimo laikas = 0.17096 s.  
100000 eiluciu failo apdorojimo laikas = 1.63202 s.  
---------------------------------------------------  
10000 eiluciu failo apdorojimo laikas = 0.158909 s.  
100000 eiluciu failo apdorojimo laikas = 1.62691 s.  
---------------------------------------------------  
10000 eiluciu failo apdorojimo laikas = 0.170676 s.  
100000 eiluciu failo apdorojimo laikas = 1.65504 s.  
---------------------------------------------------  
**03**  
---------------------------------------------------  
10000 eiluciu failo apdorojimo laikas = 0.17028 s.  
100000 eiluciu failo apdorojimo laikas = 1.62924 s.  
---------------------------------------------------  
10000 eiluciu failo apdorojimo laikas = 0.202848 s.  
100000 eiluciu failo apdorojimo laikas = 1.64458 s.  
---------------------------------------------------  
**Class:**  
---------------------------------------------------  
**01**  
---------------------------------------------------   
10000 eiluciu failo apdorojimo laikas = 0.172318 s.  
100000 eiluciu failo apdorojimo laikas = 1.76161 s.  
---------------------------------------------------  
10000 eiluciu failo apdorojimo laikas = 0.172647 s.  
100000 eiluciu failo apdorojimo laikas = 1.74858 s.  
---------------------------------------------------  
10000 eiluciu failo apdorojimo laikas = 0.170494 s.  
100000 eiluciu failo apdorojimo laikas = 1.75529 s.  
---------------------------------------------------  
**02**  
---------------------------------------------------   
10000 eiluciu failo apdorojimo laikas = 0.177178 s.  
100000 eiluciu failo apdorojimo laikas = 1.77536 s.  
---------------------------------------------------  
10000 eiluciu failo apdorojimo laikas = 0.170797 s.  
100000 eiluciu failo apdorojimo laikas = 1.77995 s.  
---------------------------------------------------  
10000 eiluciu failo apdorojimo laikas = 0.172713 s.  
100000 eiluciu failo apdorojimo laikas = 1.79458 s.  
---------------------------------------------------  
**03**  
---------------------------------------------------  
10000 eiluciu failo apdorojimo laikas = 0.175401 s.  
100000 eiluciu failo apdorojimo laikas = 1.7884 s.  
---------------------------------------------------  
10000 eiluciu failo apdorojimo laikas = 0.171749 s.  
100000 eiluciu failo apdorojimo laikas = 1.80754 s.  
---------------------------------------------------  
10000 eiluciu failo apdorojimo laikas = 0.174725 s.  
100000 eiluciu failo apdorojimo laikas = 1.76869 s.  
---------------------------------------------------  
```
### Galutinės versijos laikų rezultatai  
Pavaizduoti kiekvieno konteinerio trijų bandymų laikai su abiem strategijom. Rodomi tik milijoninio failo (mokiniai5.txt) laikai. Kad galimybės būtų lygios, galutiniai balai visais atvejais skaičiuoti pagal vidurkį.  
```shell
---------------------------------------------   
Vector:   
  1 Strategija:   38.8972   39.2304   35.9571   
  2 Strategija:   41.9406   33.3813   33.7042   
---------------------------------------------   
Deque:   
  1 Strategija:   18.0645   22.1575   20.0984   
  2 Strategija:   75.0542   62.1517   63.9163   
---------------------------------------------  
List:  
  1 Strategija:   25.4527   25.4963   21.9871   
  2 Strategija:   24.3178   27.3881   26.744   
---------------------------------------------  
```
**Vidutiniai laikai:**  
```shell
-----------------------  
Vector:  
  1 Strategija: 38.0282  
  2 Strategija: 36.3420  
-----------------------  
Deque:  
  1 Strategija: 20.1068  
  2 Strategija: 67.0407  
-----------------------  
List:  
  1 Strategija: 24.3120  
  2 Strategija: 26.1500  
-----------------------
```
### v1.0  
Esant vienodoms sąlygoms, List išliko pats greičiausias, tačiau reikia pripažinti, kad Vector tikrai buvo galima optimizuoti, o ir studentų rūšiavimo principas šiek tiek skyrėsi nuo dėstytojo siūlyto (studentai iš pradžių išrikiuoti mažėjančiai pagal pažymius, o tuomet išskirstyti į gerus ir blogus), todėl kiek sunkiau pasakyti, kuris konteineris turėjo būti greičiausias. Tenka pripažinti, kad Vector greitis šiek tiek nuvylė, tačiau dėl lėtumo visiškai kaltinu optimizaciją (Vector greitį tikrai galima padidinti, o laiką sumažinti dar bent 10 sekundžių, tačiau man nepavyko sugalvoti kaip dar optimizuoti programą, taip pat šiek tiek trūko žinių), tačiau sužavėjo jo laikų pastovumas kintant strategijoms, todėl manau, kad Vector yra atlaidesnis programuotojo klaidoms ir patirties ar žinių trūkumui. Nustebino Deque veikimas: 1 strategijoje sumušęs visus rekordus, 2 strategijoje parodė patį blogiausią laiką (tačiau Deque buvo skirta mažiausiai laiko, o kuriant šią versiją jis buvo ir mažiausiai optimizuotas, todėl kodas išliko toks kaip ir v0.5 ir jame nebuvo naudojamos naujos funkcijos, tokios kaip copy, ar iteratoriai). List parodė geriausius pastovius laikus ir vidutiniškai buvo greičiausias iš visų konteinerių. Tai pasiekti jam padėjo optimizavimas (Visos Vector pritaikytos funkcijos buvo pritaikytos ir List, norint pamatyti kiek labai tai pagreitintų ir jo darbą), nes Vector ir List kodai yra labai panašūs ir buvo labiausiai tvarkomi kuriant v1.0.  
### v0.5
Tikrintos programos turėjo tiek pat eilučių ir duomenų (100, 1 000, 10 000, 100 000, 1 000 000), tačiau buvo naudoti trys skirtingi konteineriai, failai nebebuvo generuojami, o duomenų atrinkimui sukurta atskira funkcija. Eilučių skaičiui esant ne didesniam nei 10 000, programų veikimo laikai buvo labai panašūs (nebuvo galima pastebėti, kad kažkuris konteineris dirbtų ženkliai greičiau nei kitas, o ir vienas konteineris kartais netgi aplenkdavo kitą), tačiau didėjant eilučių skaičiui vis labiau ryškėjo list konteinerio pranašumai prieš vector ir deque (kurie atliko užduotį labai panašiais laikais, nors vector dažnai aplenkdavo deque, net jeigu ir skirtumas nebudavo labai didelis), kuris su 1 000 000 eilučių failą įveikė 3 kartus greičiau nei vector ar deque. Taip pat verta paminėti ir list rikiavimo komandos list::sort pranašumą prieš std::sort, kuris buvo naudotas vector ir deque rikiavimui, nes list::sort buvo viena iš priežasčių padėjusių list'ui taip stipriai aplenkti vector ir deque paskutinėje iteracijoje.
Taip pat verta paminėti, kad šioje versijoje buvo pastebėta ir sutvarkyta atminties naudojimo problema (neefektyviai naudojama atmintis, nereikalingos informacijos saugojimas), kuri sumažino programos veikimo laiką maždaug 20% (list atveju, programos sulėtėjimas buvo dar didesnis, kurio dėka problema ir buvo pastebėta).
### v0.4
Tikrintos programos turėjo po 100, 1 000, 10 000, 100 000, 1 000 000 eilučių ir 10 namų darbų pažymių. Studentų skirstymas buvo neteisingas ir buvo pataisytas versijoje v0.5 (iki v0.5 studentai buvo išskirstomi prieš pat išvedimą if'u patikrinant jų galutinį pažymį). Taip parašyta programa, eilučių skaičiui padidėjus 10 kartų, sulėtėdavo apytiksliai 10 (paskutinės dvi iteracijos sulėtėdavo netgi šiek tiek daugiau nei 10 kartų). daugiausiai laiko užimdavo failų sugeneravimas ir išvedimas (kadangi atrinkimas į gerus ir blogus buvo atliekamas išvedant duomenis).
## Versijų istorija
### [v1.0.1]() - (2019-03-27)
**Pridėta**  
-Failų generavimo failai generavimas.cpp ir generating.cpp.  
**Koreguota**  
-makefile pridėta komanda failų generavimui.  
-Papildytas README.md
### [v1.0](https://github.com/MatasC/Objektinis-programavimas/releases/tag/uzd2_v1.0) - (2019-03-23)  
**Koreguota**  
-Visų konteinerių main funkcijos, taip pat ir papildomos funkcijos.  
-Pataisymai ir papildymai header faile.  
-README.md failo papildymas su laikų suvestine ir v1.0 veikimo įvertinimu.
### [v0.5](https://github.com/MatasC/Objektinis-programavimas/releases/tag/uzd2_v0.5) - (2019-03-12)  
**Pridėta**  
-duomenų failai.  
**1 000 000 eilučių failo neleido įkelti git'as dėl dydžio apribojimų, todėl prieš paleidžiant programą reikia sugeneruoti dar vieną failą arba sumažinti for iteracijų skaičių**  
**Koreguota**  
-Išskaidytas function.cpp failas (sukurti list.cpp, deque.cpp, vector.cpp) tam, kad būtų lengviau atskirti, kuri funkcija yra skirta kuriam konteineriui.  
-Pataisytas makefile tam, kad veiktų su naujai perdarytu function.cpp failu (sukuria tris skirtingus .exe failus trims konteineriams).  
-**Stipriai pakeista duomenų saugojimo struktūra siekiant sumažinti programos atminties naudojimą.**  
-Pridėta funkcija, kuri išskirsto studentus į gerus ir blogus.  
-**Dauguma funkcijų perrašytos siekiant sumažinti atminties naudojimą.**  
-**Išvalyta visa iteracijos metu nereikalinga informacija (po galutinio skaičiavimo ištrinami namų darbų pažymiai, nebeskaičiuojami galutiniai ir pagal medianą ir pagal vidurkį, o tik pagal pasirinktą kriterijų)**  
-Panaikintas duomenų failų generavimas programos veikimo metu.  
### v0.4.1 - (2019-03-02)  
**Koreguota**  
-Pataisyti medianos ir vidurkio duomenų tipai (buvo int, pakeisti į double). Ši klaida buvo nuo v0.1, tačiau tik šioje versijoje buvo pataisyta.
### [v0.4](https://github.com/MatasC/Objektinis-programavimas/releases/tag/uzd2_v0.4) - (2019-03-02)
**Koreguota**  
-function.cpp patobulintos funkcijos, kad programa galėtų sugeneruoti pradinių duomenų failą ir sutvarkytus duomenis, pagal nurodytą kriterijų, išspausdintų į du naujus failus (`blogi.txt` ir `geri.txt`).  
-function.h pridėta `<chrono>` biblioteka, taip pat pataisyta duomenų saugojimo struktūra (mediana ir vidurkis buvo int tipo).  
Pagrindinėje programoje pridėtos komandos, kurios paskaičiuoja, kaip greitai programa sukūrė pradinių duomenų failą ir kaip greitai ji apdorojo ir išvedė duomenis į naujus tekstinius failus.  
-Programos spartos duomenys yra išvedami į tekstinį failą (jame pažymėta kiek laiko buvo kuriamas atitinkamo dydžio failas ir per kiek laiko jis buvo apdorotas).  
-README.md papildymas (v0.4 aprašymas, programos tikslo ir paleidimo patikslinimai, nuorodos į versijas 0.3 ir 0.4).  
### [v0.3](https://github.com/MatasC/Objektinis-programavimas/releases/tag/uzd2_v0.3) - (2019-02-24)  
**Pridėta**  
-makefile patogesniam programos paleidimui ir naudojimui.  
-header failas, kuriame yra laikomos visų funkcijų deklaracijos ir struktūros aprašymas.  
-function.cpp failas, kuriame laikomi visų funkcijų aprašymai.  
**Koreguota**  
-Programa papildyta  įvesties apsaugomis (pvz. programa nutraukia darbą jei neranda tinkamo .txt failo, galutinį mokinio pažymį padaro 0, jeigu nėra įvesti namų darbų įvertinimai).  
-Patobulinta duomenų saugojimo struktūra.
-Papildytas README.md failas (paleidimo instrukcija, v0.3 aprašymas).
### [v0.2](https://github.com/MatasC/Objektinis-programavimas/releases/tag/0.2) - (2019-02-17)  
**Pridėta**  
-Tekstinis failas studentų duomenims įvesti kursiokai.txt  
**Koreguota**  
-Programoje pridėta galimybė nuskaityti mokinių duomenis iš tekstinio failo.  
-Pridėtas mokinių rūšiavimas pagal vardą (jei vardai vienodi, tai pagal pavardę) prieš spausdinimą.  
-Patobulintas duomenų įvedimas ranka taip, kad duomenys vistiek būtų išrikiuoti prieš spasudinant.  
-Papildytas README.md failas.  
### [v0.1](https://github.com/MatasC/Objektinis-programavimas/releases/tag/0.1) - (2019-02-16)  
**Pridėta**    
-Sukurtas README.md failas  
-Pridėta programos versija atlikta su C masyvais.  
-pridėta programos versija su vector tipo C++ konteineriais.  
**Koreguota**  
-README.md pridėtas trumpas programos aprašymas.  
-pridėta funkcija atsitiktinai sugeneruoti mokinio pažymius (naudojant C++11 standarto generavimo funkcijas).  
-versijoje su vector konteineriais pridėta struktūra mokinių duomenims saugoti (taip pat vector tipo).  
-Pridėta galimybė galutinį balą skaičiuoti naudojant medianą, vietoje vidurkio.  
