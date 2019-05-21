#include<iostream>
#include<typeinfo>
#include <fstream>
#include <ios>
#include <sstream>
#include <windows.h>

/*UWAGI DO PROJEKTU:
1.Wpisywanie danych dzia³a TYLKO dla wartoœci pojedynczych tj: tytul - 1 s³owo:
2.Edycja dziala tylko w tym samym uruchomieniu programu(zmieniany jest plik, wiec kolejne uruchomienie programu zepsuje uklad)
*/

using namespace std;
    const char *sciezka = "prace.txt";

class Praca{

    public:
        int id;
        string typPracy;
        string tytul;
        string nazwiskoAutora;
        string imieAutora;
        int rok;
        string nazwiskoPromotora;
        string imionaPromotora;
        string slowaKluczowe;
        string streszczenie;
        string nowa_praca;

        Praca() {
        id = 0;
        typPracy = "";
        tytul = "";
        nazwiskoAutora = "";
        imieAutora = "";
        rok = 0;
        nazwiskoPromotora = "";
        imionaPromotora = "";
        slowaKluczowe = "";
        streszczenie = "";
    }

    ~Praca()
    {

    }
};

class Biblioteka{

    public:

        int ilePrac;
        Praca prace [1000];

        Biblioteka()
        {
            ilePrac = 0;
        }
//------------ODCZYT Z PLIKU------------------

        void odczyt(const char *sciezka)
        {
            ifstream plik_o(sciezka);
            if (plik_o.is_open())
            {
                int i = 0;
                string wiersz;
                string s;
                while(!plik_o.eof()&& i<=ilePrac)
                {
                    getline(plik_o,wiersz);
                    if(wiersz =="") break;
                    istringstream iss(wiersz);
                    iss >> prace[i].id;

                    getline(plik_o,wiersz);
                    prace[i].typPracy = wiersz;

                    getline(plik_o,wiersz);
                    prace[i].tytul = wiersz;

                    getline(plik_o,wiersz);
                    prace[i].imieAutora = wiersz;

                    getline(plik_o,wiersz);
                    prace[i].nazwiskoAutora = wiersz;

                    getline(plik_o,wiersz);
                    istringstream ass(wiersz);
                    ass >> prace[i].rok;

                    getline(plik_o,wiersz);
                    prace[i].imionaPromotora = wiersz;

                    getline(plik_o,wiersz);
                    prace[i].nazwiskoPromotora = wiersz;

                    getline(plik_o,wiersz);
                    prace[i].slowaKluczowe = wiersz;

                    getline(plik_o,wiersz);
                    prace[i].streszczenie = wiersz;

                    ilePrac+=1;
                    ++i;
                }
            }else cout<<"error, blad wczytania"<<endl;
            plik_o.close();
        }
//-----------ZAPIS DO PLIKU-------------------------------------
        void zapis(const char *sciezka)
        {


        ofstream plik_z(sciezka, ios_base::app);
            int i =0;
            if (plik_z.is_open())
            {
                    prace[i].id=prace[i].id+1;
                    plik_z << prace[i].id<<endl;
                cout << "Podaj typ pracy: ";
                    cin >> prace[i].typPracy;
                    plik_z << prace[i].typPracy<<endl;
                cout << "Podaj tytul: ";
                    cin >> prace[i].tytul;
                    plik_z << prace[i].tytul<<endl;
                cout << "Podaj imie autora: ";
                    cin >> prace[i].imieAutora;
                    plik_z << prace[i].imieAutora<<endl;
                cout << "Podaj nazwisko autora: ";
                    cin >> prace[i].nazwiskoAutora;
                    plik_z << prace[i].nazwiskoAutora<<endl;
                cout << "Podaj rok: ";
                    cin >> prace[i].rok;
                    plik_z << prace[i].rok<<endl;
                cout << "Podaj imiona promotora: ";
                    cin >> prace[i].imionaPromotora;
                    plik_z << prace[i].imionaPromotora<<endl;
                cout << "Podaj nazwisko promotora: ";
                    cin >> prace[i].nazwiskoPromotora;
                    plik_z << prace[i].nazwiskoPromotora<<endl;
                cout << "Podaj slowa kluczowe: ";
                    cin >> prace[i].slowaKluczowe;
                    plik_z << prace[i].slowaKluczowe<<endl;
                cout << "Podaj streszczenie: ";
                    cin >> prace[i].streszczenie;
                    plik_z << prace[i].streszczenie<<endl;


                }
            else cout<<"Blad zapisu"<<endl;
            plik_z.close();
        }
//-------EDYCJA DANYCH----------------------------

void edytuj(const char *sciezka)
        {


        ofstream plik_z(sciezka);
            int i =0;
            if (plik_z.is_open())
            {
                    cout <<"Ktora prace chcesz zedytowac?\n>>";
                    cin >> i;
            if(i-1<0){cout<<"Nie ma takiej pracy!";} else{

            cout << "-------------------------------------------------\n";
            cout <<"ID: "<< prace[i-1].id<<endl;
            cout <<"Typ pracy: "<< prace[i-1].typPracy<<endl;
            cout <<"Tytul: "<< prace[i-1].tytul<<endl;
            cout <<"Autor: "<< prace[i-1].nazwiskoAutora;
            cout << prace[i-1].imieAutora<<endl;
            cout <<"Promotor: "<<prace[i-1].imionaPromotora;
            cout << prace[i-1].nazwiskoPromotora<<endl;
            cout <<"Rok: "<< prace[i-1].rok<<endl;
            cout <<"Slowa kluczowe: "<< prace[i-1].slowaKluczowe<<endl;
            cout <<"Streszczenie: "<< prace[i-1].streszczenie<<endl;
            cout << "-------------------------------------------------\n";
            int wybor =0;

            cout<< "Wybierz dan¹ do edycji: \n"<<"1.typ pracy\n2.tytul\n3.nazwiskoAutora\n4.imieAutora\n5.rok\n6.nazwiskoPromotora\n7.imionaPromotora\n8.imionaPromotora\n9.slowaKluczowe\n10.streszczenie\n>>";
            cin >> wybor;
            switch(wybor){
        case 1:
            cout << "Podaj typ pracy: ";
                cin >> prace[i-1].typPracy;
                plik_z << prace[i-1].typPracy<<endl;
            break;
        case 2:
            cout << "Podaj tytul: ";
                cin >> prace[i-1].tytul;
                plik_z << prace[i-1].tytul<<endl;
            break;
        case 3:
            cout << "Podaj imie autora: ";
                cin >> prace[i-1].imieAutora;
                plik_z << prace[i-1].imieAutora<<endl;
            break;
        case 4:
            cout << "Podaj nazwisko autora: ";
                cin >> prace[i-1].nazwiskoAutora;
                plik_z << prace[i-1].nazwiskoAutora<<endl;
            break;
        case 5:
            cout << "Podaj rok: ";
                cin >> prace[i-1].rok;
                plik_z << prace[i-1].rok<<endl;
            break;
        case 6:
            cout << "Podaj imiona promotora: ";
                cin >> prace[i-1].imionaPromotora;
                plik_z << prace[i-1].imionaPromotora<<endl;
            break;
        case 7:
            cout << "Podaj nazwisko promotora: ";
                cin >> prace[i-1].nazwiskoPromotora;
                plik_z << prace[i-1].nazwiskoPromotora<<endl;
            break;
        case 8:
            cout << "Podaj slowa kluczowe: ";
                cin >> prace[i-1].slowaKluczowe;
                plik_z << prace[i-1].slowaKluczowe<<endl;
            break;
        case 9:
            cout << "Podaj streszczenie: ";
                cin >> prace[i-1].streszczenie;
                plik_z << prace[i-1].streszczenie<<endl;
            break;
        default:
            break;

            }
         }
        }
            else cout<<"Blad zapisu"<<endl;
            plik_z.close();
        }
//-------WYSZUKIWANIE DANYCH----------------------
void wyszukiwanie(const char *sciezka)
        {
            ifstream plik_o(sciezka);
            if (plik_o.is_open())
            {
                string *tekst;
                int wybor = 0;
                string szukanaFraza;
                int szukajRok=0;
                int szukajId=0;
                string wiersz;
                string s;
                cout << "Wyszukaj po:\n1.id\n2.typie pracy\n3.tytule\n4.imieniu autora\n5.nazwisku autora\n6.roku\n7.imieniu promotora\n8.nazwisku promotora\n9.slowach kluczowych\n10.streszczeniu\n>>";
                int i = 0;
                cin >> wybor;
            switch(wybor){

                case 1:
                    system("cls");
            cout << "Podaj id pracy: ";
                cin >> szukajId;
                for(int i = 0;i<ilePrac;i++){
                    if(prace[i].id == szukajId){
            cout << prace[i].id<<" "<< prace[i].typPracy<<" "<< prace[i].nazwiskoAutora<<" "<<prace[i].imieAutora<<" "<< prace[i].tytul<<" "<<prace[i].rok<<endl;
                    }else{cout<<" ";}
                }
            break;

                case 2:
                    system("cls");
            cout << "Podaj typ pracy: ";
            cin >> szukanaFraza;
            for(int i = 0;i<ilePrac;i++){
           if(prace[i].typPracy.find(szukanaFraza)!=-1){
            cout << prace[i].id<<" "<< prace[i].typPracy<<" "<< prace[i].nazwiskoAutora<<" "<<prace[i].imieAutora<<" "<< prace[i].tytul<<" "<<prace[i].rok<<endl;
            }else{cout <<"\nNie znaleziono frazy w pracy\n";}
            }


            break;

                case 3:
                    system("cls");
            cout << "Podaj tytul: ";
            cin >> szukanaFraza;
            for(int i = 0;i<ilePrac;i++){
           if(prace[i].tytul.find(szukanaFraza)!=-1){
            cout << prace[i].id<<" "<< prace[i].typPracy<<" "<< prace[i].nazwiskoAutora<<" "<<prace[i].imieAutora<<" "<< prace[i].tytul<<" "<<prace[i].rok<<endl;
            }else{cout <<"\nNie znaleziono frazy w pracy\n";}
            }

            break;

                case 4:
                    system("cls");
            cout << "Podaj imie autora: ";
            cin >> szukanaFraza;
            for(int i = 0;i<ilePrac;i++){
           if(prace[i].imieAutora.find(szukanaFraza)!=-1){
            cout << prace[i].id<<" "<< prace[i].typPracy<<" "<< prace[i].nazwiskoAutora<<" "<<prace[i].imieAutora<<" "<< prace[i].tytul<<" "<<prace[i].rok<<endl;
            }else{cout <<"\nNie znaleziono frazy w pracy\n";}
            }


            break;

                case 5:
                    system("cls");
            cout << "Podaj nazwisko autora: ";
            cin >> szukanaFraza;
            for(int i = 0;i<ilePrac;i++){
           if(prace[i].nazwiskoAutora.find(szukanaFraza)!=-1){
            cout << prace[i].id<<" "<< prace[i].typPracy<<" "<< prace[i].nazwiskoAutora<<" "<<prace[i].imieAutora<<" "<< prace[i].tytul<<" "<<prace[i].rok<<endl;
            }else{cout <<"\nNie znaleziono frazy w pracy\n";}
            }

            break;

                case 6:
                    system("cls");
            cout << "Podaj rok: ";
            cin >> szukajRok;
            for(int i = 0;i<ilePrac;i++){
           if(szukajRok==prace[i].rok){
            cout << prace[i].id<<" "<< prace[i].typPracy<<" "<< prace[i].nazwiskoAutora<<" "<<prace[i].imieAutora<<" "<< prace[i].tytul<<" "<<prace[i].rok<<endl;
            }else{cout <<"\nNie znaleziono frazy w pracy\n";}
            }
            break;

                case 7:
                    system("cls");
            cout << "Podaj imie promotora: ";
            cin >> szukanaFraza;
            for(int i = 0;i<ilePrac;i++){
           if(prace[i].imionaPromotora.find(szukanaFraza)!=-1){
            cout << prace[i].id<<" "<< prace[i].typPracy<<" "<< prace[i].nazwiskoAutora<<" "<<prace[i].imieAutora<<" "<< prace[i].tytul<<" "<<prace[i].rok<<endl;
            }else{cout <<"\nNie znaleziono frazy w pracy\n";}
            }

            break;

                case 8:
                    system("cls");
            cout << "Podaj nazwisko promotora: ";
            cin >> szukanaFraza;
            for(int i = 0;i<ilePrac;i++){
           if(prace[i].nazwiskoPromotora.find(szukanaFraza)!=-1){
            cout << prace[i].id<<" "<< prace[i].typPracy<<" "<< prace[i].nazwiskoAutora<<" "<<prace[i].imieAutora<<" "<< prace[i].tytul<<" "<<prace[i].rok<<endl;
            }else{cout <<"\nNie znaleziono frazy w pracy\n";}
            }

            break;

                case 9:
                    system("cls");
            cout << "Podaj slowo kluczowe: ";
            cin >> szukanaFraza;
            for(int i = 0;i<ilePrac;i++){
           if(prace[i].slowaKluczowe.find(szukanaFraza)!=-1){
            cout << prace[i].id<<" "<< prace[i].typPracy<<" "<< prace[i].nazwiskoAutora<<" "<<prace[i].imieAutora<<" "<< prace[i].tytul<<" "<<prace[i].rok<<endl;
            }else{cout <<"\nNie znaleziono frazy w pracy\n";}
            }

            break;

                case 10:
                    system("cls");
            cout << "Podaj streszczenie: ";
            cin >> szukanaFraza;
            for(int i = 0;i<ilePrac;i++){
           if(prace[i].streszczenie.find(szukanaFraza)!=-1){
            cout << prace[i].id<<" "<< prace[i].typPracy<<" "<< prace[i].nazwiskoAutora<<" "<<prace[i].imieAutora<<" "<< prace[i].tytul<<" "<<prace[i].rok<<endl;
            }else{cout <<"\nNie znaleziono frazy w pracy\n";}
            }
            break;
        default:
            system("cls");
            cout << "Nie ma takiej opcji!\n";
            break;
                }
                while(!plik_o.eof()&& i<=ilePrac)
                {
                    getline(plik_o,wiersz);
                    if(wiersz =="") break;

                }
            }
        }
//-------LICZENIE PRAC----------

void liczbaPrac(const char *sciezka)
        {
            int iloscPrac = 0;
            int iloscMgr = 0;
            int iloscLic = 0;
            int wybor=0;
            int wybor2=0;
            ifstream plik_o(sciezka);
            if (plik_o.is_open())
            {
                                    system("cls");

                cout << "1.Wypisz ilosc prac\n2.Wypisz ilosc prac poszczegolnych typow\n3.\nDostepne w pakiecie PREMIUM\n(Nie udalo sie zrobic)\n4.\nDostepne w pakiecie PREMIUM\n(Nie udalo sie zrobic)\n";
                cin >> wybor;
                switch(wybor){
            case 1:
            for(int i = 0 ; i<ilePrac;i++){
            iloscPrac++;
            }
            system("cls");
            cout<< "\nLiczba prac: "<<iloscPrac<<endl;
                break;
            case 2:
                                    system("cls");

                cout<<"1.Wypisz ilosc prac magisterskich\n2.Wypisz ilosc prac licencjackich\n>>";
                cin >> wybor2;
                switch(wybor2){
            case 1:

                for(int i =0; i < ilePrac;i++){
                    if(prace[i].typPracy=="mgr"){
                        iloscMgr++;
                    }
                }
                system("cls");
                cout<<"Prac magisterskich: "<<iloscMgr;
                break;
            case 2:
                for(int i =0; i < ilePrac;i++){
                    if(prace[i].typPracy=="lic"){
                        iloscLic++;
                    }
                }
                system("cls");
                cout<<"Prac licencjackich: "<<iloscLic;
                break;
            default:
                                    system("cls");

                cout<<"Nie ma takiej opcji!";
                break;
                }
                break;
            default:
                cout<< "Opcja niedostepna!\n";
                }
            }
        }
//-------WYPISANIE DANYCH NA EKRAN----------------

        void wypisz(){
        for(int i = 0 ; i < ilePrac ; i++)
        {
            cout << "-------------------------------------------------\n";
            cout <<"ID: "<< prace[i].id<<endl;
            cout <<"Typ pracy: "<< prace[i].typPracy<<endl;
            cout <<"Tytul: "<< prace[i].tytul<<endl;
            cout <<"Autor: "<< prace[i].nazwiskoAutora;
            cout << prace[i].imieAutora<<endl;
            cout <<"Promotor: "<<prace[i].imionaPromotora;
            cout << prace[i].nazwiskoPromotora<<endl;
            cout <<"Rok: "<< prace[i].rok<<endl;
            cout <<"Slowa kluczowe: "<< prace[i].slowaKluczowe<<endl;
            cout <<"Streszczenie: "<< prace[i].streszczenie<<endl;
            cout << "-------------------------------------------------\n";
        }
        }
        void wypiszSkrocone(){
        for(int i = 0 ; i < ilePrac ; i++)
        {
            cout << "-------------------------------------------------\n";
            cout << prace[i].id<<" "<< prace[i].typPracy<<" "<< prace[i].nazwiskoAutora<<" "<<prace[i].imieAutora<<" "<< prace[i].tytul<<" "<<prace[i].rok<<endl;
            cout << "-------------------------------------------------\n";
        }
        }
};

int main()
{

    const char *sciezka = "prace.txt";

    Biblioteka *bibl = new Biblioteka();


       int opcja;
        bibl->odczyt(sciezka);

        do{

    cout << "Wybierz opcje:\n1.Wyswietlanie listy prac w formacie skroconym\n2.Wyswietlanie listy prac w formacie pelnym\n3.Dodawanie prac do biblioteki\n4.Edycja danych o pracy\n5.Wyszukiwanie prac na podstawie wybranego kryterium\n6.Funkcje dodatkowe\n7.Wyjscie z programu\n\n>>";
    cin >> opcja;
    switch(opcja) {
        case 1:
            system("cls");
            cout << "Lista prac:\n";
            bibl -> wypiszSkrocone();
            cout << endl;

            break;
        case 2:
            system("cls");
            cout << "Lista prac:\n";
            bibl -> wypisz();
            cout << endl;
            break;
        case 3:
            system("cls");
            cout << "Zapis:\n";
            bibl ->zapis(sciezka);
            cout << endl;
            break;
        case 4:
            system("cls");
            cout << "Edycja:\n";
            bibl ->edytuj(sciezka);
            cout << endl;
            break;
        case 5:
            system("cls");
            cout << "Wyszukiwanie:\n";
            bibl ->wyszukiwanie(sciezka);
            cout << endl;
            break;
        case 6:
            system("cls");
            cout << "Opcje dodatkowe:\n";
            bibl->liczbaPrac(sciezka);
            cout << endl;
            break;
        case 7:
            system("cls");
            cout << "Program zakonczy dzialanie...\n";
            break;
        default:
            system("cls");
            cout << "To nie jest poprawna opcja!\n\n";
            break;
        }
}while(opcja!=7);

    delete [] sciezka;

    return 0;

}

