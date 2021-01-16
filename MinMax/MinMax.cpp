#include <iostream>

using namespace std;

struct przedzial
{
	short int poczatek;
	short int koniec;
};

void minmax(int poczatek, int koniec, int *tablica, int min, int max);

int main()
{
	int wielkosc;
	cin >> wielkosc;
	int *ciag;
	ciag = new int[wielkosc];

	for (int i = 0; i < wielkosc; i++) {
		cin >> ciag[i];
	}
	int iloscZ;//ilosc wczytywanych par
	cin >> iloscZ;
	przedzial *zapytanie;
	zapytanie = new przedzial[iloscZ]; // tablica wczytywanych par
	for (int i = 0; i < iloscZ; i++) {
		cin >> zapytanie[i].poczatek;
		cin >> zapytanie[i].koniec;
	}
	int min = NULL;
	int max = NULL;
	for (int i = 0; i < iloscZ; i++) {
		minmax(zapytanie[i].poczatek, zapytanie[i].koniec, ciag, min, max);
	}
	//cout << "\n" << ciag[5];
	//cout << "Test : " << 1 % 2;
	delete[] ciag;
	delete[] zapytanie;
}

void minmax(int poczatek, int koniec, int *tablica, int min, int max){
	min = tablica[poczatek];
	max = tablica[poczatek];
	while (poczatek < koniec+1) {
		if (max < tablica[poczatek]) {
			max = tablica[poczatek];
		}
		if (min > tablica[poczatek]) {
			min = tablica[poczatek];
		}
		poczatek++;
		//return minmax(poczatek + 1, koniec, tablica, min, max);
	}
	cout << min << " " << max << endl;
}


