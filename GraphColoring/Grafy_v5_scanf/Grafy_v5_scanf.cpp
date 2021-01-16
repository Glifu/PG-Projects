// Grafy_v5_scanf.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>

using namespace std;


int main()
{

    int numberOfGraphs;
    int graphSize;
    int zeroCounter = 0, oneCounter = 0;;
    char dataHolder[300];
    bool nieCykl = false;


    scanf("%d", &numberOfGraphs);
    for (int i = 0; i < numberOfGraphs; i++) {
        zeroCounter = 0;
        oneCounter = 0;
        nieCykl = false;
        scanf("%d", &graphSize);
        fgets(dataHolder, graphSize * graphSize + 2, stdin);
        for (int i = 1; i < graphSize * graphSize + 1; i++) {
            if (dataHolder[i] == '0') {
                zeroCounter++;
            }
            else if (dataHolder[i] == '1') {
                oneCounter++;
            }
            if (i % graphSize == 0) {
                if (oneCounter != 2)
                    nieCykl = true;
                else {
                    oneCounter = 0;
                }
            }
        }
        if (zeroCounter == graphSize || ((nieCykl == false) && (graphSize % 2 != 0))) {
            printf("True\n");
        }
        else{
            printf("False\n");
        }
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
