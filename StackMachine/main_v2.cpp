// PoProstu2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

struct Wezel {
	int data;
	struct Wezel *next;
};

int main()
{
	char a='d';
	int ia;


	Wezel *glowa;
	glowa = nullptr;
	

	Wezel *temp;

	cout << "\nTest adresu: " << glowa << endl;
	while (a != 'q') {

		cout << "\n\nPodaj wartosc: ";
		cin >> a;
		ia = (int)a - 48;
		Wezel nowy;

		if (0 <= ia && ia <= 9) {
			nowy.data = ia;			//	ia -> int z A,
			nowy.next = glowa;
			glowa = &nowy;
			cout << "Data: " << nowy.data << "   Adres: " << nowy.next << "    Glowa: " << glowa << endl;
		}

		else {
			switch (a)
			{
			case 'r':
				cout << "r - zdjecie ze stosu liczby n, przeniesienie liczby z wierzcholka stosu na n-te miejsce liczac od wierzcholka; 0 r oraz 1 r nic nie robi, 2 r jest tozsame z s, 3 r zamienia 3 2 1 na 2 1 3 itd. ";
				break;

			case 'p':
				cout << "p - wypisanie stosu\n";
				temp = glowa;
				while (temp != nullptr) {
					cout << temp->data << " " ;
					temp = nowy.next;
				}
				break;

			case 's':
				cout << "s - zamiana miejscami dwoch licz na szczyciestosu";
				break;

			case 'x':
				cout << "x - usuniecie liczby z wierzchu stosu";
				break;

			case '+':
				cout << "+ - zdjecie dwoch liczb ze stosu i wlozenie na stos ich sumy";
				break;

			case 'q':
				cout << "Nastapi zakonczenie programu";
				break;

			default:
				break;
			}
		}
		if (glowa == nullptr) {
			cout << "\n**Lista jest pusta**\n";
		}
		else {
			cout << "\nWartosc ostatniego elementu w liscie: " << glowa->data;
		}
		/*
		for (int j = 0; j < n; j++) {
			cout << "Wielkosc elementu " << j << ": " << stos[j] << endl;
		}

		int *wsk;
		//wsk = &stos[5];
		cout << "\n\nTest case:  " << *wsk << "  " << wsk;
	*/
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file