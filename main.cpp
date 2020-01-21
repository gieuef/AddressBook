#include <iostream>
#include <windows.h>
#include <fstream>
#include <conio.h>

using namespace std;

struct Osoba
{
    int id;
    string imie, nazwisko, numerTelefonu, email, adres;
};

int wczytajOsobyZPliku(Osoba osoby[])
{
    string imie, nazwisko, numerTelefonu, email, adres;
    string linia;
    int iloscOsob = 0;
    int nr_linii=1;


    fstream plik;
    plik.open("KsiazkaAdresowa.txt", ios::in);

    if(plik.good()==false)
        cout<<"Nie mozna otworzyc pliku!";

    while(getline(plik,linia))
    {
        switch(nr_linii)
        {
        case 1:
            osoby[iloscOsob].id = atoi(linia.c_str());;
            break;
        case 2:
            osoby[iloscOsob].imie = linia;
            break;
        case 3:
            osoby[iloscOsob].nazwisko = linia;
            break;
        case 4:
            osoby[iloscOsob].numerTelefonu = linia;
            break;
        case 5:
            osoby[iloscOsob].email = linia;
            break;
        case 6:
            osoby[iloscOsob].adres = linia;
            break;
        }

        if (nr_linii==6)
        {
            nr_linii=0;
            iloscOsob++;
        }
        nr_linii++;
    }

    plik.close();

    return iloscOsob;
}


int dodajOsobe(Osoba osoby[], int iloscOsob)
{
    string imie, nazwisko, numerTelefonu, email, adres;

    // Pobieram dane nowej osoby
    system("cls");
    cout << "Dodawanie osoby" << endl;
    cout << "Podaj imie uzytkownika: ";
    cin >> imie;
    cout << "Podaj nazwisko uzytkownika: ";
    cin >> nazwisko;
    cout << "Podaj numer telefonu uzytkownika: ";
    cin.sync(); // oprozniam bufor
    getline(cin, numerTelefonu); // wczytuje razem ze spacja
    cout << "Podaj email uzytkownika: ";
    cin >> email;
    cout << "Podaj adres uzytkownika: ";
    cin.sync();
    getline(cin, adres);

    // ustalam id osoby
    int osobaId = iloscOsob + 1;

    // dodaje osobe do tablicy
    osoby[iloscOsob].id = osobaId;
    osoby[iloscOsob].imie = imie;
    osoby[iloscOsob].nazwisko = nazwisko;
    osoby[iloscOsob].numerTelefonu = numerTelefonu;
    osoby[iloscOsob].email = email;
    osoby[iloscOsob].adres = adres;

    // dodaje osobe do pliku
    fstream plik;
    plik.open("KsiazkaAdresowa.txt", ios::out | ios::app);
    if (plik.good())
    {
        plik << osobaId << endl;
        plik << imie << endl;
        plik << nazwisko << endl;
        plik << numerTelefonu << endl;
        plik << email << endl;
        plik << adres << endl;

        plik.close();

        cout << "Osoba zostala dodana." << endl;
        Sleep(1000);
    }
    else
    {
        cout << "Nie mozna otworzyc pliku: KsiazkaAdresowa.txt" << endl;
    }
    iloscOsob++;
    return iloscOsob;
}

void wyswietlOsobyOTymSamymImieniu(Osoba osoby[], int iloscOsob)
{
    string imie;
    system("cls");
    cout << "Podaj imie : " << endl;
    cin >> imie;
    cout << endl;

    for (int i=0; i<iloscOsob; i++)
        if (osoby[i].imie == imie)
        {
            cout << osoby[i].id <<endl;
            cout << osoby[i].imie <<endl;
            cout << osoby[i].nazwisko <<endl;
            cout << osoby[i].numerTelefonu <<endl;
            cout << osoby[i].email <<endl;
            cout << osoby[i].adres <<endl <<endl;
        }

    getch();

}


void wyswietlOsobyOTymSamymNazwisku(Osoba osoby[], int iloscOsob)
{
    string nazwisko;
    system("cls");
    cout << "Podaj nazwisko : " << endl;
    cin >> nazwisko;
    cout << endl;

    for (int i=0; i<iloscOsob; i++)
        if (osoby[i].nazwisko == nazwisko)
        {
            cout << osoby[i].id <<endl;
            cout << osoby[i].imie <<endl;
            cout << osoby[i].nazwisko <<endl;
            cout << osoby[i].numerTelefonu <<endl;
            cout << osoby[i].email <<endl;
            cout << osoby[i].adres <<endl <<endl;
        }

    getch();
}

void wyswietlWszystkich(Osoba osoby[], int iloscOsob)
{

    system("cls");


    for (int i=0; i<iloscOsob; i++)
    {
        cout << osoby[i].id <<endl;
        cout << osoby[i].imie <<endl;
        cout << osoby[i].nazwisko <<endl;
        cout << osoby[i].numerTelefonu <<endl;
        cout << osoby[i].email <<endl;
        cout << osoby[i].adres <<endl;
    }

    getch();

}

int main()
{
    Osoba osoby[1000];
    int iloscOsob;
    char wybor;

    iloscOsob = wczytajOsobyZPliku(osoby);


    while (true)
    {
        system("cls");
        cout << "1. Dodaj osobe" << endl;
        cout << "2. Wyszukaj osoby o podanym imieniu" << endl;
        cout << "3. Wyszukaj osoby o podanym nazwisku" << endl;
        cout << "4. Wyswietl wszystkie osoby z ksiazki" << endl;
        cout << "9. Zakoncz program" << endl;
        cin >> wybor;

        if (wybor == '1')
        {
            iloscOsob = dodajOsobe(osoby, iloscOsob);
        }
        if (wybor == '2')
        {
            wyswietlOsobyOTymSamymImieniu(osoby,iloscOsob);
        }
        if (wybor == '3')
        {
            wyswietlOsobyOTymSamymNazwisku(osoby,iloscOsob);
        }
        if (wybor == '4')
        {
            wyswietlWszystkich(osoby,iloscOsob);
        }
        else if (wybor == '9')
        {
            exit(0);
        }
    }

    return 0;
}
