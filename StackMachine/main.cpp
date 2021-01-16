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
	char a = 'd';
	int ia;


	Wezel *glowa;
	glowa = nullptr;

	cout << "\nTest adresu: " << glowa << endl;
	while (a != 'q') {

		cout << "\nPodaj wartosc: ";
		cin >> a;
		ia = (int)a - 48;
		Wezel *nowy = new Wezel;

		if (0 <= ia && ia <= 9) {
			nowy->data = ia;         //  ia -> int z A,
			nowy->next = glowa;
			glowa = nowy;
			//cout << "\nTempData: " << nowy->data << "   TempAdres: " << nowy->next << "    GlowaAdres: " << glowa << endl;
		}
		else {
			switch (a)
			{
			case 'r': {
				int n;
				break;
			}
			case 'p':
				nowy = glowa;
				//cout << "\nData: " << temp->data << "   Adres: " << temp->next << "    GlowaData: " << glowa->data << "    GlowaAdres: " << glowa->next << endl;
				cout << "p - wypisanie stosu\n";
				while (nowy != nullptr) {
					cout << nowy->data << " ";
					nowy = nowy->next;
				}
				break;
			
			case 's': 
				if (glowa != nullptr && glowa->next != nullptr) {
					cout << "s - zamiana miejscami dwoch liczb na szczycie stosu";
					Wezel *temp = new Wezel;
					temp = glowa;
					glowa = glowa->next;
					temp->next = glowa->next;
					glowa->next = temp;
					delete temp;
				}
				break;
			
			case 'x': {
				if (glowa != nullptr) {
					cout << "x - usuniecie liczby z wierzchu stosu";
					Wezel *temp = new Wezel;
					temp = glowa;
					glowa = glowa->next;
					//delete temp;
				}
				break;
			}
			case '+': {
				if (glowa != nullptr && glowa->next != nullptr) {
					cout << "+ - zdjecie dwoch liczb ze stosu i wlozenie na stos ich sumy";
					int sum = 0;
					sum = sum + glowa->data + glowa->next->data;
					cout << sum;
					glowa = glowa->next;
					glowa->data = sum;
				}
				break;
			}
			case 'q': {
				cout << "Nastapi zakonczenie programu";
				break;
			}
			default:
				break;
			}
		}
		if (glowa == nullptr) {
			//cout << "\n**Lista jest pusta**\n";
		}
		else {
			//cout << "\nWartosc ostatniego elementu w liscie: " << glowa->data;
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