// Sekta.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <list>

using namespace std;






struct listaCykliczna {
    int data;
    struct listaCykliczna* nastepnik;
};

void selekcjaSekty(int k, listaCykliczna* lista, int coDrugi, listaCykliczna* poprzednik = nullptr) {
    int usunietaWartosc;
    if (coDrugi % 2 == 1) {     // && k=!0
        usunietaWartosc = lista->data;
        poprzednik->nastepnik = lista->nastepnik;
        //usuniecie elementu z listy
        if (k == 1 || k == 0) {
            cout << usunietaWartosc << endl;
        }
    }
    poprzednik = lista;
    //Niezaleznie co sie dzieje idziemy do kolejnego elementu
    if (k != 0) {
        if (coDrugi % 2 == 1) {
            coDrugi++;
            selekcjaSekty(k - 1, lista->nastepnik, coDrugi, poprzednik);
        }
        else {
            coDrugi++;
            selekcjaSekty(k, lista->nastepnik, coDrugi, poprzednik);
        }
    }

};

int main()
{
    int iloscWejsc;
    int iloscOsob;
    int zgadywanaPozycja;


    cin >> iloscWejsc;
    for (int l = 0; l < iloscWejsc; l++) {
        cin >> iloscOsob >> zgadywanaPozycja;

        // Inichjalizacja//
        listaCykliczna* glowa = new listaCykliczna;
        listaCykliczna* poczatek = new listaCykliczna;
        glowa->data = 1;
        glowa->nastepnik = glowa;

        poczatek = glowa;


        if (zgadywanaPozycja < 0) {                                 //konwersja ujemnej pozycji
            zgadywanaPozycja = (iloscOsob + 1) + zgadywanaPozycja;
        }

        for (int i = 2; i <= iloscOsob; i++) {                       //zapelnienie kolejki
            listaCykliczna* nowy = new listaCykliczna;
            nowy->data = i;
            nowy->nastepnik = poczatek;
            glowa->nastepnik = nowy;
            glowa = nowy;
        }


        selekcjaSekty(zgadywanaPozycja, poczatek, 0);

        for (int i = 0; i < iloscOsob; i++) {
            delete poczatek;
            listaCykliczna* temp = new listaCykliczna;
            temp = poczatek;
            poczatek = poczatek->nastepnik;
            delete temp;
        }
        delete poczatek;

    }
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
