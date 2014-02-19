			
			Elemente de grafica pe calculator 
				    Tema 2
				Crazy Driver  

Constanda Raluca, 332CC

	1.Cerinta
	Tema consta in realizarea unui joc 3D de curse auto cu obstacole, varianta simplificata
cu 3 benzi si obiecte simpliste.

	2.Utilitare
	Tema se ruleaza din Visual Studio, versiunea 2012, pe Windows.
	
	2.1 Fisiere
	Pentru implementarea temei am pormit de la scheletul de cod al laboratorului
3, mai precis partea de grafica 3D. Astfel, este nevoie de Framework-ul ce contine
clasele pentru desenarea diverselor forme geometrice, transformarile si afisarea 
acestora in diferite perspective.

	2.2 Tastatura
	Pentru controlul masinii se utilizeaza tastele astfe:
		* sageti stanga - dreapta pentru rotatii (intoarcere stanga dreapta pentru schimbare
banda de mers)
		* sageata inainte pentru miscarea inainte a jucatorului si pentru accelerare
		* tasta in jos pentru reducerea vitezei de mers

	2.3 Interfata grafica 
	Interfata grafica este intuitiva, dupa modelul celei din enunt.

	3. Implementare
	Am implementat tema pe Windows in Visual Studio 2012, folosind framework-ul 
laboratorului 3.

	3.1 Schema generala
	La deschiderea programului pe fereastra de joc apare in centru masina pe banda din mijloc.
In pozitie initiala masina are o vitaza constanta mica si obstacolele apar una cate una in mod aleator.

	3.2 Diagrama Clase

--> Clasa Container+ ----> Clasa Parallelepiped
		   + ----> Clasa Car
		   + ----> Clasa Road
		   + ----> Clasa Pyramid

--> Clasa Snow 

-- Functie main
-- Framework lab3

	4. Testare
	Am testat aplicatia jucandu-ma efectiv si incercat toate posibilele variante de joc.
	
	5. Probleme aparute
	Am intampinat cateva probleme la intelegerea jocului (a ceea ce se doreste de la acest joc).
Am sper ca am reusit sa indeplinesc toate cerintele din enunt ale jocului.
	
	6. Continut arhiva
	* main.cpp -> Sursa principala a aplicatiei. 
	* Car.cpp -> Clasa pentru desenarea, rotirea si miscarea masinii. Mai
contine si alte cateva functii ajutatoare pentru transmitera anumitor variabile private
	* Car.h -> Fisierul header pentru functiile declarate mai sus
	* Road.cpp -> Clasa care deseneaza soseaua, ca parte de jos a unui cub.
	* Road.h -> Fisierul header pentru clasa de mai sus
	* Container.cpp -> Clasa de baza a claselor pentru obiecte 3d. 
	* Container.h -> Fisierul header pentru functiile declarate mai sus. Contine 
ferestrele de vizualizare si 2 metode virtuale implementate de clasele copii si o 
variabila protected pentru centrul obiectului (de desenat).
	Am mai implementat 2 clase pentru obiecte 3d speciale:
	* Parallelepiped.cpp -> Clasa care deseneaza un paralelipiped dupa punct si
dimensiuni primite in constructor.
	* Parallelepiped.h ->  Fisierul header pentru clasa de mai sus
	* Pyramid.cpp -> Clasa care deseneaza o piramida dupa punct si
dimensiuni primite in constructor.
	* Pyramid.h ->  Fisierul header pentru clasa de mai sus

	* Snow.cpp -> Clasa care deseneaza un fulg de zapada sub forma unui cerculet 
albastru.
	* Snow.h -> Fisierul header pentru clasa de mai sus

	7. Functionalitati
	Continului jocului respecta toate cerintele din enunt.
	-> Masina poate trece de pe o banda pe alta prin rotire stanga / dreapta
si miscare inainte
	-> La pozitionarea pe o banda si accelerare, masina isi mareste viteza
	-> Pentru a crea iluzia de viteza la accelerare masina are o usoara miscare sus jos
asemeni unui drum deluros (sau cu gropi).
	-> La apasarea pe butonul de franare viteza masinii scade.
	-> Obstacolele vin din fata in mod aleator.
	-> Vitezele lor de apropiere depind de viteza masinii.
	-> Scorul, si distanta ramasa se calculeaza in functie de viteza masinii. La o 
viteza mai mare distanta scade mai repede si scorul creste mai repede.
	-> Numarul de vieti scade la contactul cu unul dintre obstacole.
	-> Scorul, timpul scurs, distanta ramasa si numarul de vieti sunt afisate in 
partile laterale ale ecranului.
	-> Obstacolele le-am retinut in 2 vectori (unul pentru paralelipipede si altul 
pentru piramide)	

	* Functionalitati bonus
	-> Ca un bonul pentru acest joc, am adaugat iluzia unor fulgi de nea care apar din 
partea de sus a ecranului si care au o coborare lenta pe directia stanga jos.
	-> Acestia intra in ton cu fundalul bleu. :)

 