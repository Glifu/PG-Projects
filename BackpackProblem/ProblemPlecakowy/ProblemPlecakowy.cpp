// ProblemPlecakowy.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <queue>

using namespace std;

struct Przedmiot {
    double waga;           //Waga danego przedmiotu
    double cena;           //Cena danego przedmiotu
    double stosunek;        //Stosunek ceny do Wagi

    void liczStosunek() {
        stosunek = cena / waga;
    }
};



int main()
{
    int iloscAut;
    int iloscPrzedmiotow;
    queue <double> wyniki;
    cin >> iloscAut;

    for (int licznik = 0; licznik < iloscAut; licznik++) {
        double zarobek = 0;
        double udzwigAut = 0;
        Przedmiot A[15];

        zarobek = zarobek - 20;

        cin >> iloscPrzedmiotow;

        for (int i = 0; i < iloscPrzedmiotow; i++) {
            cin >> A[i].cena;
        }

        for (int i = 0; i < iloscPrzedmiotow; i++) {
            cin >> A[i].waga;
        }

        cin >> udzwigAut;

        for (int i = 0; i < iloscPrzedmiotow; i++) {
            if (A[i].waga > 100) {
                A[i].cena = A[i].cena - 5;
            }
            A[i].liczStosunek();
        }

        if (iloscPrzedmiotow > 1) {
            for (int i = iloscPrzedmiotow; i > 0; i--) {
                for (int j = 0; j < i - 1; j++) {
                    if (A[j].stosunek < A[j + 1].stosunek) {
                        swap(A[j], A[j + 1]);

                    }
                }
            }
        }

        for (int i = 0; i < iloscPrzedmiotow; i++) {
            if (udzwigAut - A[i].waga >= 0) {
                zarobek = zarobek + A[i].cena;
                udzwigAut = udzwigAut - A[i].waga;
            }
        }

        if (zarobek < 0) {
            zarobek = 0;
        }
        wyniki.push(zarobek);
    }
    for (int i = 0; i < iloscAut; i++) {
        cout << wyniki.front() << endl;
        wyniki.pop();
    }
}
