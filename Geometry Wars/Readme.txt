		
			Elemente de grafica pe calculator 
				    Tema 1
				Geometry Wars 

Constanda Raluca, 332CC

	1. Cerinta
	Tema consta in realizarea unui joc 2D de tipul Geometry Wars in care 
exista un jucator principal si mai multi inamici pe care trebuie sa ii extermine.
Jucatorul acumuleaza puncte in functie de numarul de atacuri, pana la epuizarea
celor 3 vieti.
	
	2. Utilizare
	Tema se ruleaza din Visual Studio, versiunea 2012, pe Windows. 
	
	2.1 Fisiere
	Pentru implementarea temei am pormit de la scheletul de cod al laboratorului
2, mai precis prima parte a acestuia. Astfel, este nevoie de Framework-ul ce contine
clasele pentru desenarea diverselor forme geometrice, transformarile si afisarea 
acestora si pentru impartirea ferestrei de lucru in 2 cadre diferite.

	2.2 Tastatura
	Pentru controlul jucatorului se utilizeaza tastele astfe:
		* sageti stanga - dreapta pentru rotatii (ca in enunt)
		* sageata inainte pentru miscarea inainte a jucatorului
		* tasta SPACE pentru aruncarea cu proiectile
		* tasta in jos pentru activarea sau dezactivarea armei
	
	2.3 Interfata grafica 
	Interfata grafica este intuitiva, dupa modelul celei din enunt
	
	3. Implementare
	Am implementat tema pe Windows in Visual Studio 2012, folosind framework-ul 
laboratorului 2. 
	
	3.1 Schema generala
	La deschiderea programului pe fereastra de joc apare in centru jucatorul
inconjurat de 30 de inamici. La impuscarea unui jucator apare un altul pe o pozitie 
aleator aleasa. 
	
	3.2 Diagrama Clase

--> Clasa Opponent + ----> Clasa Opponent2Squares
		   + ----> Clasa OpponentDiamond
		   + ----> Clasa OpponentPlane
		   + ----> Clasa OpponentStar
		   + ----> Clasa OpponentTetris

--> Clasa Object2D + ----> Clasa Player
		   + ----> Clasa Bullet 

-- Functie main
-- Framework lab2

	4. Testare
	Am testat aplicatia jucandu-ma efectiv si incercat toate posibilele variante
de joc.

	5. Probleme aparute
	Am imtampinat o problema la folosirea functiilor din Framework si anume din 
Transform2D. Pentru miscari ale diferitelor obiecte (miscarile player-ului, miscarile 
adversarilor) aveam nevoie de matrici de transformare diferite, insa matricea de 
transformari era declarata static si miscarile deveneau haotice. Solutia pe care am 
gasit-o a fost ca la fiecare miscare a adversarilor si a gloantelor sa salvez intr-o
matrice auxiliara matricea de transfer (a Player-ului) si sa o reactualizez la finalul
miscarii.

	6. Continut arhiva
	* main.cpp -> Sursa principala a aplicatiei. 
	* Player.cpp -> Clasa pentru desenarea, rotirea si miscarea jucatorului. Mai
contine si alte cateva functii ajutatoar pentru activarea/dezactivarea armei si pentru
transmitera anumitor variabile private
	* Player.h -> Fisierul header pentru functiile declarate mai sus
	* Opponent.cpp -> Clasa de baza a claselor pentru inamici. 
	* Opponent.h -> Fisierul header pentru functiile declarate mai sus. Contine 
ferestrele de vizualizare si 2 metode virtuale implementate de clasele copii si o 
variabila protected pentru centrul obiectului (de desenat).
	Urmeaza 5 clase care extind clasa Opponent, cate una pentru fiecare tip de 
advrsar. Fiecare dintre acestea implementeaza functiile de desenare si de stergere a 
obiectului precum si functie de miscare. Variabilele private sunt in functie de necesitatile
si forma obiectului. (Obiecte din framework extinse din Object2D)
	* Opponent2Squares.cpp -> Clasa pentru adversarul in forma a 2 patrate portocalii.
	* Opponent2Squares.h -> Header-ul corespunzator  	
	* OpponentDiamond.cpp -> Clasa pentru adversarul ce contine in patrat si in altul 
interior de culoare galben.
	* OpponentDiamond.h -> Header-ul corespunzator  
	* OpponentPlane.cpp -> Clasa pentru adversarul in forma unui avion albastru.
	* OpponentPlane.h -> Header-ul corespunzator  
	* OpponentTetris.cpp -> Clasa pentru adversarul in forma unei piese de tetris.
	* OpponentTetris.h -> Header-ul corespunzator  
	* OpponentStar.cpp ->  Clasa pentru adversarul in forma unei stele. 
	* OpponentStar.h -> Header-ul corespunzator

	*Bullet.cpp -> Clasa pentru desenarea, stergerea si miscarea unui glont.   
	*Bullet.h -> Header-ul corespunzator

	In arhiva mai exista si fisierele necesare fremework-ului (folderul dependente si 
Framework).

	7. Functionalitat
	Continului jocului respecta toate cerintele din enunt.
	* Functionalitati standard
	-> Jucatorul se roteste si se misca in directia indicata de simbolul din mijloc 
(in fata acestuia) impreuna cu arma daca aceasta este activata.
	-> Daca arma este activata viteza lui de deplasare este mai mica, iar daca arma
se desactiveaza viteza revine la valoarea initiala.
	-> Nici jucatorul si nici un alt adversar nu iese din spatiul de joc
	-> Adversarii au formele din enunt si prezinta o miscare aleatoare
	-> Scorul este afisat in partea de sus a ecranului in pozitie centrala iar numarul 
vietilor ramase este indicat in dreptul simbolului jucatorului in coltul din dreapta sus.
	-> Daca un inamic atinge corpul jucatorului acesta dispare iar jucatorul pierde o viata.
	-> Punctajul difera de la un inamic la altul.	

	* Functionalitati bonus
	-> Atacul se realizeaza cu ajutorul unor gloante care ies din varful armei jucatorului.
Numai aceate gloante pot neutraliza inamicii. 

	* Functionalitati suplimentare
	-> Jocul se incheie cand numarul de vieti ajunge la 0.
	-> La fiecare neutralizare a unui adversar apare un altul de o forma si o pozitie aleatoare.
	-> Se pot apasa mai multe taste simultan.(Ex. se poate muta/roti adversarul si in acelasi 
timp se pot trage gloante.)

