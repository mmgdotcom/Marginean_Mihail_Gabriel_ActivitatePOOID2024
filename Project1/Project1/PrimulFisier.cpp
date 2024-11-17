//fisier creat pentru tema de la poo

//construim o clasa in care vom adauga la fiecare meditatie noi concepte

//Bibliotecile
//Intotdeauna incepem cu bibliotecile
#include <iostream> //prima biblioteca input output stream
#include <string>
using namespace std; //pentru a putea folosi variabila string

//invatam sa ne construim clase si sa lucram cu clase


//tipuri de date in cpp

//pentru valori numerice
//int - ocupa 4 octeti
//float - ocupa 4 octeti
//double - ocupa 8 octeti

//pentru siruri de caractere
//char - ocupa 1 octet

//pentru valori de tipul adevarat fals
//bool - ocupa 1 octet

//ce memorie ocupa un program?
//adunam cat ocupa fiecare variabila


//string - nu este tip de data - este de fapt o biblioteca care stocheaza siruri de caractere -> #include<string>
//nu ocupa o memorie standard
//memoria este calculata dupa formula 1 octet per caracter (inclusiv spatiul)
//string nume = "Mihai" -> 5 caractere x 1 octet = 5 octeti
//string nume = "Bogdan" -> 6 caractere x 1 octet = 6 octeti

//Clasa
//structura de data avansata
//Contine atribute si functii
//Atributele definesc structura clasei
//Functiile definesc comportamentul clasei

//O clasa poate fi orice obiect dfin realitate
//Caracterizeaza orice ne inconjoara din viata de zi cu zi
//Prin obiect intelegem orice ne inconjoara: o actiune, o cladire, o institutie, otara, un continent, o persoana, un doemniu economic etc.

//Cand alegem un obiect o sa trebuuiasca sa definim acel abiect din doua puncte de vedere
//1. Prin trasaturile lui (prin atributele lui) si il descriem
//Exexmplu:
//student
//int varsta;
//int grupa;
//char serie;
//int nrExameneSustinute;

//2. Prin actiunile pe care le face (prin functii)
//se duce la examen
//trece sau nu trece la examen
//isi plateste taxele
//etc.

//Clasa este formata din schelet si muschi
//schelet => atribute
//muschi => functii

//O clasa poata fi vazut ca o schema pe baza careia urmeaza sa ne cream obiectele


//Clasa angajat
//atribute
//string nume
//string prenume
//string companie
//int CNP
//float salariu
//bool lucreaazaFullTime

//pe baza acestei clase vom construi obiecte de tip angajat
//aceste obiecte vor prelua valori specifice pentru aceste atribute setate de mine

//Angajat_1
//nume: Ion
//prenume: Popescu
//CNP: 1980909876543
//salariu: 7000
//lucreazaFullTime: 1

//Angajat_2
//nume: Gheorghe
//prenume: Alexandra
//CNP: 1980909878948
//salariu: 10000
//lucreazaFullTime: 0


//exemplu de clasa care sa contina urmatoarele tipuri atribute: int, float, string, bool
//Monitor
//int nrButoane
//float diagonala
//string producator
//bool estePornit

//cum definim o clasa in cpp
//Pas 1: folosim cuvantul cheie class urmat de numele clasei care va fi intotdeauna la singular si cu litera mare
//Pas 2: deschidem acolade iar dupa acolada de inchidere trebuie sa avem mereu punct si virgula
//Pas 3: tot ce apartinme clasei (atribute si functii) se scrie in interiorul acoladei

/*
class Magazin
{
	string denumireMagazin;
	int nrAngajati;
	float suprafataMagazin;
	bool esteNonStop;
};
*/

//Obiectul
//Calasa este chema care caracterizeaza obiectul
//Pe baza acesteti scheme ne cream obiecte dand valori specifice atributelor
//In exemplele de mai sus Angajat_1 si Angajat_2 sunt obiecte
//Fiecare obiect va prelua o valoare pentru fiecare atribut in parte
//Nu lasam atribute necompletate in momentul in care ne cream obiectul


// Principiile POO-ului (sunt 4 la numar) - le mentionam pe masura ce le intalnim
//1. Abstractizarea - transpunerea din realitate in cod a trasaturilor unui obiect
//imi aleg un obiect din realitate iar acest magazin sa incerc sa l trnaspun in cod sursa prin trasaturile lui din realitate
//denumire, nr de angajati, metri patrati etc.
//trasaturile le transpun prin atribute
//2. Incapsularea - punerea atributelor in zona privata a clasei

//Prima functie pe care o invatam: constructorul
class Magazin
{
	//zonele de acces dintr-o clasa:
	//cand nu este setata zona de acces explicit, aceasta va fi setata automat drept private
	//public:tot ceea ce plasam in zona publica a clasei va putea fi accesat atat in interiorul clasei cat si din exteriorul clasei de oricine oriunde
	//private: este fix opusul zonei public - va putea fi accesata doar din interiorul clasei - ceea ce este in exteriorul clasei nu are acces in zona private
	//protected:
	//exista o conventie care trebuie respectata la POO
	//atributele trebuie puse intotdeauna in zona privata
	//restul se scrie in zona publica
private:
	string denumireMagazin;
	int nrAngajati;
	float suprafataMagazin;
	bool esteNonStop;
	const int CUI;
	static int clasaCAENPrincipala; //47 pentru toate magazinele

public:
	//constructorul
	//este o metoda speciala care se foloseste pentru a construi obiecte pe baza atributelor din clasa
	//pentru fiecare obiect in parte acest constructor va aloca cate o valoare pentru fiecare atribut

	//regula de scriere a unui constructor:
	/*
	numeClasa(in paranteza trecem parametrii constructorului)
	{
		intre acolade initializam fiecare atribut in parte
		this->numeAtribut = valoare; (scriem asa pentru fiecare atribut)
	}
	*/

	//tipuri de constructori
	//1. Constructori fara parametrii
	//2. Constructori cu un parametru
	//3. Constructori cu 2 parametrii
	//...
	//4. Constructori cu toti parametrii (numarul maxim de parametrii)

	//constructorul fara parametrii - il folosesc atunci cand nu cunoastem informatii despre obiectul nostru
	Magazin() :CUI(0) //nu trec nimic in paranteza pentru ca este constructor fara paramentrii deci atributele sunt practic necunoscute
	{
		//chiar daca sunt necunoscute atributele nu pot fi lasate neinitializate
		//dar le vom initializa cu valori default
		//valorile de tip string vor fi initializate cu "anonim" sau "necunoscuta"
		//pentru valorile numerice initializam cu zero
		//pentru valorile cu bool putem initializa fie cu false (0) fie cu true(1)
		this->denumireMagazin = "Necunoscuta";
		this->nrAngajati = 0;
		this->suprafataMagazin = 0;
		this->esteNonStop = 1;
		//:CUI(0) echivalent cu this->CUI = 0; dar pentru ca este constant se initializeaza imediat dupa paranteze
	}

	//constructorul cu un parametru - va contine in lista de prametrii un singur atribut
	//pot sa creez atatia constructori cu un parametru cate atribute am.
	//=> 4 atribute => 4 constructori cu 1 parametru
	//=> pot avea un singur constructor fara parametrii
	//=> pot avea un singur constructor cu toti parametrii
	Magazin(string denumireMagazin) :CUI(0)
	{
		this->denumireMagazin = denumireMagazin;
		this->nrAngajati = 0;
		this->suprafataMagazin = 0;
		this->esteNonStop = 1;
	}

	//constructorul cu doi parametrii
	Magazin(string denumireMagazin, int nrAngajati) :CUI(0)
	{
		this->denumireMagazin = denumireMagazin;
		this->nrAngajati = nrAngajati;
		this->suprafataMagazin = 0;
		this->esteNonStop = 1;
	}

	//constructorul cu trei parametrii
	Magazin(string denumireMagazin, int nrAngajati, float esteNonStop) :CUI(0)
	{
		this->denumireMagazin = denumireMagazin;
		this->nrAngajati = nrAngajati;
		this->suprafataMagazin = 0;
		this->esteNonStop = esteNonStop;
	}

	//constructorul cu toti parametrii
	Magazin(string denumireMagazin, int nrAngajati, float suprafataMagazin, bool esteNonStop, int CUI) :CUI(CUI)
	{
		//nu este corect sa scriu this->denumireMagazin = "Lidl"; pentru ca toate magazinele pe care mi le-as fi creat in void Main ()
		//pe baza acestui constructor ar fi avut aceste valori pe care mi le-am setat aici
		//de aceea folosim lista de parametrii
		//acesti parametrii dau posibilitatea utilizatorului sa dea valori specifice acestor atribute in void Main()
		this->denumireMagazin = denumireMagazin;
		this->nrAngajati = nrAngajati;
		this->suprafataMagazin = suprafataMagazin;
		this->esteNonStop = esteNonStop;
		//:CUI(CUI) echivalent this->CUI = CUI;
	}

	/*
	Metode accesor: getteri si setteri
	Au rolul de a reda accesul catre zona privata a clasei pe care in mod normal nu o putem accesa
	Getteri : redau accesul catre zona privata a clasei cu scopul de a afisa pe consola atributele(get = ia atributul si il afiseaza)
	Setteri : redau accesul catre zona privata a clasei cu scopul de a modifica atributele(set = seteaza atributul, adica il modifica)
	Metodele accesor au scopul de a reda accesul catre atributele din zona privata a clasei, care in mod normal nu pot fi afisate / modificate
	deoarece ele sunt plasate in zona private a clasei insa metodele accesor vor rezolva aceste doua probleme.

	=> getteri se folosesc pentru afisarea pe ecran a atributelor
	Getteri vor folosi instructiunea return care este singura instructiune care perminte compilatorului
	afisarea rezultatului dorit pe ecran deoarece au scopul de a afisa pe ecran atributele.
	Tipul returnat al metodei trebuie sa coincida mereu cu tipul atributului din instructiunea return.

	Regula:
	tipDataAtribut getNumeAtribut(nu trecem nimic in paranteza)
		{
			return this -> numeAtribut;
		}
	*/
	string getdenumireMagazin() {
		return this->denumireMagazin;
	}

	int getnrAngajati() {
		return this->nrAngajati;
	}

	float getsuprafataMagazin() {
		return this->suprafataMagazin;
	}

	bool getesteNonStop() {
		return this->esteNonStop;
	}

	int getCUI() {
		return this->CUI;
	}

	/*
	Setteri
	Sunt folositi pentru a modifica valoarea atributelor atunci cand ne hotaram sa schombam vechile valori
	void setNumeAtribut(tipAtribut numeParametru) {
		this->numeAtribut = numeParametru;
	}

	Toate metodele care nu folosesc instructiunea return (adica toate metodele care nu vor avea ca scop afisarea unei valori
	vor fi de tip void (folosim atunci cand nu vrem sa afisam nimic pe ecran).
	*/

	void setdenumireMagazin(string denumireNouaMagazin) {
		this->denumireMagazin = denumireNouaMagazin;
	}

	void setnrAngajati(int nrAngajatiNou) {
		this->nrAngajati = nrAngajatiNou;
	}

	void setsuprafataMagazin(float suprafataNouaMagazin) {
		this->suprafataMagazin = suprafataNouaMagazin;
	}

	void setesteNonStop(bool esteNouNonStop) {
		this->esteNonStop = esteNouNonStop;
	}

};

/*
//exemplu mai bun ca sa intelegem de ce atributele se pun in zona private si nu public
class CardBancar
{
public:
	string numeDetinator;
	string nrCard;
	string dataExpirare;
	int cvv;
	float soldCont;
};
*/

/*
Atributele particulare ale unui clase: constante si clasice

Atributele constante: au o valoare constanta, ramane aceeasi intotdeauna.
Ne gandim la caracteristicile care raman intotdeauna aceeasi.
Nu poate fi lasat neinitializat in constructor.
Suntem obligati sa le intiaializam in toti constructorii, altfel primi eroare.
Atributele normale, daca sunt lasate neinitializate, nu genereaza erori dar vor primi niste valori aberante.
=> initializam toate atributele in constructori.
=> cand avem atribut constant nu mai putem sa avem constructor fara parametrii.
=> atributele constante se intiailizeaza in exteriorul acoladelor constructorului, adica in lista de initializari a constractorului
=> atributele constante nu primesc un setter pentru ca ele nu isi pot modifica valoarea initiala

const + tip atribut (int, float etc.) + denumire atribut

Exemple:
const int CNP (pentru clasa student/persoana/angajat etc.)
const string culoareOchi
const int CUI (pentru clasa companie)


Atributele statice: diferite total de celelalte atribute prin faptul ca ele nu descriu obiectele in sine ci descriu intreaga clasa.
Preiau o valoare pentru intreaga clasa.
Descriu clasa per total.
Valoarea atributului static trebuie sa defineasca toate obiectele definite in clasa.
Se defineste o singura data pentru toata clasa pentru toate obiectele.
Reprezinta o variabila gliobala care se aplica pentru toata clasa.

static + tip atribut + denumire atribut

Exemple:
static int nrRotiMasina (toate masinile pentru familie au 4 roti)
static int TVA (acelasi tva pentru toate magazinele alimentare)
static int taxaRestanta (toti studentii platesc aceeasi taxa pentru restanta)

Particularitati:
- nu se initializeaza absolut deloc in constructori pentru ca nu preiau o valoare specifica pentru fiecare obiect in parte
- se initializeaza o singura data in afara clasei: tipul de data al atribututlui static + nume clasa+ operatorul de rezolutie + numele atributului = valoare



Pointeri
Se declara cu ajutorul caracterului '*'.
Adresa de memorie este un cod hexazecimal format din 8 caractere (cifre[0-9]/litere[a-f]) prin care compilatorul identifica fiecare atribut din codul nostru.
Extragerea adreselor de memorie: prin plasarea semnului '&' in fata atributului respectiv
Exemplu: cout << "Adresa de memorie a atributului denumireMagazin pentru obiectul m3: " << &(m3.getdenumireMagazin) << endl; (atributul trebuie sa fie public ca sa mearga)

Pointerii sunt tot variabile cum sunt si variabilele in, float, double, bool si char diferenta fiind ca pointerii nu stocheaza valori
ci stocheaza adrese de memorie.

Diferenta dintre o variabila normala si una de tip pointer
string numeStudent = "Ana";
string* numeStudentPointer = "Ana"; //aici vom primi eroare

=> Vrem sa dam valoare atunci folosim variabilele simple.
=> Vrem sa dam adresa de memorie atunci folosim pointeri.

Pointerii nu pot fi intializati cu valori pentru ca ei stocheaza adrese de memorie.

string* numeStudentPointer = &(numeStudent); //acum pointerul este intializat cu adresa de memorie e variabilei numeStudent

Cu pointerii putem sa facem doua operatii:
1. Extragerea adeselor de memorie
2. Deferentiere


*/

//:: se numeste operator de rezolutie

//aici initializez atributul static
int Magazin::clasaCAENPrincipala = 47;

class Autobuz {

private:
	static int nrAutobuze;
	const int idAutobuz;
	int capacitate;
	int nrPersoaneImbarcate;
	char* producator;

public:

};

int Autobuz::nrAutobuze = 0;

void main()
{
	//aici vom testa tot ce se afla in clasa noastra, toate functiile, vom construi obiecte, vom distruge obiecte etc.

	//obiectele se construiesc in void main cu ajutorul constructorilor

	//regula: numeClasa, numeObiect(intre paranteza dam valori pentru atribute)

	Magazin	m1("Lidl", 100, 350.5, 0, 12345677);
	//putem sa folosim doar getterii care ne intereseaza, nu e obligatoriu sa ii afisam pe toti
	cout << "Afisez atributele obiectului m1" << endl;
	cout << m1.getdenumireMagazin() << endl;
	cout << m1.getnrAngajati() << endl;
	cout << m1.getsuprafataMagazin() << endl;
	cout << m1.getesteNonStop() << endl;
	cout << m1.getCUI() << endl;
	cout << endl << endl;

	cout << "Afisez atributele obiectului m2" << endl;
	Magazin	m2("Altex", 80, 150.99, 1, 12345678);
	cout << m2.getdenumireMagazin() << endl;
	cout << m2.getnrAngajati() << endl;
	cout << m2.getsuprafataMagazin() << endl;
	cout << m2.getesteNonStop() << endl;
	cout << m2.getCUI() << endl;
	cout << endl << endl;

	cout << "Afisez atributele obiectului m3" << endl;
	Magazin m3; //nu punem () ca o sa avem eroare
	cout << m3.getdenumireMagazin() << endl;
	cout << m3.getnrAngajati() << endl;
	cout << m3.getsuprafataMagazin() << endl;
	cout << m3.getesteNonStop() << endl;
	cout << m3.getCUI() << endl;
	cout << endl << endl;

	cout << "Afisez atributele obiectului m4" << endl;
	Magazin m4;
	cout << m4.getdenumireMagazin() << endl;
	cout << m4.getnrAngajati() << endl;
	cout << m4.getsuprafataMagazin() << endl;
	cout << m4.getesteNonStop() << endl;
	cout << m4.getCUI() << endl;
	cout << endl << endl;

	cout << "Afisez atributele obiectului m5" << endl;
	Magazin m5("H&M");
	cout << m5.getdenumireMagazin() << endl;
	cout << m5.getnrAngajati() << endl;
	cout << m5.getsuprafataMagazin() << endl;
	cout << m5.getesteNonStop() << endl;
	cout << m5.getCUI() << endl;
	cout << endl << endl;

	cout << "Afisez atributele obiectului m6" << endl;
	Magazin m6("Zara", 28);
	cout << m6.getdenumireMagazin() << endl;
	cout << m6.getnrAngajati() << endl;
	cout << m6.getsuprafataMagazin() << endl;
	cout << m6.getesteNonStop() << endl;
	cout << m6.getCUI() << endl;
	cout << endl << endl;

	cout << "Afisez atributele obiectului m7" << endl;
	Magazin m7("Dedeman", 76, 0); //nu scriem intre ghilimele cuvinte separate prin spatiu ca mai trebuie sa adaugam ceva in cod ca sa mearga
	cout << m7.getdenumireMagazin() << endl;
	cout << m7.getnrAngajati() << endl;
	cout << m7.getsuprafataMagazin() << endl;
	cout << m7.getesteNonStop() << endl;
	cout << m7.getCUI() << endl;
	cout << endl << endl;

	m3.setdenumireMagazin("Zara");
	m3.setnrAngajati(18);
	m3.setsuprafataMagazin(107.2);
	m3.setesteNonStop(1);

	cout << "Afisez atributele obiectului m3 dupa ce le-am modificat" << endl;
	cout << m3.getdenumireMagazin() << endl;
	cout << m3.getnrAngajati() << endl;
	cout << m3.getsuprafataMagazin() << endl;
	cout << m3.getesteNonStop() << endl;
	cout << m3.getCUI() << endl;
	cout << endl << endl;

	//cout << "Adresa de memorie a atributului denumireMagazin pentru obiectul m3: " << &(m3.getdenumireMagazin) << endl;

	//cum declaram si initializam un pointer cu o adresa de memorie
	string numeStudent = "Ana";
	string* numeStudentPointer = &(numeStudent);
	cout << "Pointer-ul numeStudentPointer: " << numeStudentPointer << endl;
	cout << endl;

	/*
		CardBancar c1;
		c1.numeDetinator = "Daria";
		c1.nrCard = "54585485485486625";
		c1.dataExpirare = "31.12.2027";
		c1.cvv = 123;
		c1.soldCont = 200000;

		cout << c1.numeDetinator << endl;
		cout << c1.nrCard << endl;
		cout << c1.dataExpirare << endl;
		cout << c1.cvv << endl;
		cout << c1.soldCont << endl;

		c1.soldCont = 0;

		cout << c1.numeDetinator << endl;
		cout << c1.nrCard << endl;
		cout << c1.dataExpirare << endl;
		cout << c1.cvv << endl;
		cout << c1.soldCont << endl;
	*/
}



/*
Sa se defineasca clasa Autobuz care are campurile:
� nrAutobuze � intreg static � contorizeaza automat numarul de autobuze create;
� idAutobuz - intreg constant - id-ul unic al autobuzului
� capacitate � intreg � numarul de persoane care pot fi imbarcate in autobuz pe locuri;
� nrPersoaneImbarcate � intreg � numarul de persoane aflate in autobuz. Nu poate fi mai mare decat capacitatea autobuzului;
� producator � char* - numele producatorului autobuzului.

Atributele clasei se definesc in zona privata a clasei

Sa se defineasca pentru clasa Autobuz constructor fara parametri, constructor cu parametri si destructor. Constructorul cu parametri contine validari pentru parametrii primiti.

Sa se defineasca pentru clasa Autobuz constructorul de copiere si metode accesor(get si set) pentru doua atribute la alegere. Testati in functia main().

Sa se supraincarce pentru clasa Autobuz operatorul= (de atribuire) fara a genera memory leaks si Sa nu permita auto-atribuirea. Testati in functia main().

Sa se supraincarce operatorul << pentru afisarea obiectelor de tipul Autobuz. Elementele sunt afisate pe aceeasi linie despartite prin punct si virgula si spatiu (; ). Testati in functia main().

Sa se defineasca metoda getNumarLocuriLibere() care calculeaza si returneaza numarul de locuri libere ramase in autobuz. Testati in functia main().

Sa se supraincarce operator de cast la int care determina numarul de persoane urcate deja in autobuz. Testati in functia main().

Sa se supraincarce operator> care va compara doua autobuze dupa capacitatea acestora. Testati in functia main().

Temele copiate sau create cu ChatGPT vor fi anulate iar lista cu persoanele respective va fi trimisa catre decanat.

Incarcati fisierul CPP pana joi, 21 noiembrie, ora 23:00.
*/













/*
Valori nutritionale crispy strips
Glucide: 30.21
Proteine: 34.08
Grasimi: 16.32
*/
