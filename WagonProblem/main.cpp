// WagonLista.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>

using namespace std;

struct Wezel {
	int data;
	struct Wezel *next;
};

int main() {
	int n, we, wy=0;
//	int bocznica = 0;
	Wezel *glowa;
	glowa = nullptr;

//	cout << "\nTest adresu: " << glowa << endl;

	cin >> n;



	for (int i = 0; i < (2*n) ;i++) {
		if(i < n) {
			cin >> we;
		}
		else {
			we = NULL;
		}
		

		if ((wy+1) == we && we != NULL) {
			wy = we;
//			cout << "Z wejscia na Wejscie" << endl;
		}
		else if(glowa != nullptr && (wy+1) == glowa->data) {
			wy = glowa->data;
			glowa->data = NULL;
			glowa = glowa->next;
//			cout << "Z bocznicy na Wyjscie;" << endl;
		}
		else if( we != NULL ){
			Wezel *nowy = new Wezel;
			nowy->data = we;         
			nowy->next = glowa;
			glowa = nowy;
//			cout << "\nNa bocznice" << endl;
//			cout << "nowyData: " << nowy->data << "   nowyAdres: " << nowy->next << "    Glowa: " << glowa << endl;
		}
	}
	if (glowa != nullptr) {
//		cout << "Bocznica: " << bocznica << endl;
		cout << "NIE";
	}
	else {
		cout << "TAK";
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