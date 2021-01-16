// ProblemPlecakowyV2.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>

using namespace std;


int plecaki(int n, int waga[], int wartosc[], int c, int i) {

    int wInc, wExc;
    if (i == n || waga[i] <= 0) {
        return 0;
    }
    if (waga[i] <= c) {
        wInc = plecaki(n, waga, wartosc, c - waga[i], i + 1) + wartosc[i];
        wExc = plecaki(n, waga, wartosc, c, i + 1);
        if (wInc > wExc) {
            return wInc;
        }
        else {
            return wExc;
        }
    }
    else {
        wExc = plecaki(n, waga, wartosc, c, i + 1);
        return wExc;
    }
};



int main()
{

    int iloscAut;
    scanf("%d", &iloscAut);

    for (int a = 0; a < iloscAut; a++) {
        int iloscPrzedmiotow;
        scanf("%d", &iloscPrzedmiotow);
        int zarobek = -20;
        int pojemnosc=1;

        int waga[15];
        int cena[15];
        int stosunek[15];

        for (int i = 0; i < iloscPrzedmiotow; i++) {
            scanf("%d", &cena[i]);
        }
        for (int i = 0; i < iloscPrzedmiotow; i++) {
            scanf("%d", &waga[i]);
            if (waga[i] > 100) {
                cena[i] = cena[i] - 5;
            }
            if (waga[i] == 0 || cena[i] == 0) {
                stosunek[i] = 0;
            }
            else {
                stosunek[i] = waga[i] / cena[i];
            }

        }
        scanf("%d", &pojemnosc);

        for (int i = 0; i < iloscPrzedmiotow; i++) {
            int temp;
            if (waga[i] > pojemnosc) {

                temp = waga[i];
                waga[i] = waga[iloscPrzedmiotow - 1];
                waga[iloscPrzedmiotow - 1] = temp;

                temp = cena[i];
                cena[i] = cena[iloscPrzedmiotow - 1];
                cena[iloscPrzedmiotow - 1] = temp;

                temp = stosunek[i];
                stosunek[i] = stosunek[iloscPrzedmiotow - 1];
                stosunek[iloscPrzedmiotow - 1] = temp;

                iloscPrzedmiotow = iloscPrzedmiotow - 1;
            }
        }

        //Bubble Sort
        if (iloscPrzedmiotow < 0) {
            for (int i = iloscPrzedmiotow; i > 0; i--) {
                int temp;
                for (int j = 0; j < i - 1; j++) {
                    if (stosunek[j] < stosunek[j + 1]) {
                        temp = waga[j];
                        waga[i] = waga[j + 1];
                        waga[j + 1] = temp;

                        temp = cena[j];
                        cena[j] = cena[j + 1];
                        cena[j + 1] = temp;

                        temp = stosunek[j];
                        stosunek[j] = stosunek[j + 1];
                        stosunek[j + 1] = temp;

                        iloscPrzedmiotow = iloscPrzedmiotow - 1;
                    }
                }
            }
        }

        zarobek = zarobek + plecaki(iloscPrzedmiotow, waga, cena, pojemnosc, 0);

        if (zarobek < 0) { 
            zarobek = 0; 
        }
        printf( "%d\n" ,zarobek);
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
