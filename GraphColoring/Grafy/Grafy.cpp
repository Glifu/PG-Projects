// Grafy.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>

using namespace std;


int main()
{
    //Data Holder
    int graphSize = 0;
    char inputData;

    //For input
    int numberOfInputs;

    //For output
    int graphGradeCounter = 0;

    cin >> numberOfInputs;

    std::ios::sync_with_stdio(false);

    for (int programCyclces = 0; programCyclces < numberOfInputs; programCyclces++) {

        bool czyCykl = true;
        bool czyPelny = true;
        bool czyNieParzysty = true;
        cin >> graphSize;
        if (graphSize % 2 == 0) {
            czyNieParzysty = false;
        }
        int graphLongSize = graphSize * graphSize;
        for (int i = 0; i < graphLongSize; i++) {
            if (i % graphSize == 0) {
                graphGradeCounter = 0;
            }
            cin >> inputData;
            //cout << " | div: " << i / graphSize << " |  mod: " << i % graphSize << endl;
            if ( /*((i/graphSize) <= (i % graphSize)) &&*/ inputData == '1') {
                graphGradeCounter = graphGradeCounter + 1;
            }
            if ((i % graphSize) == (graphSize - 1)) {                                           // Jesli przedostatni element
                if (graphGradeCounter != graphSize - 1) {                                       // Oraz stopien wierzcholka rowny ilosci wierzcholkow -1 :  nie jest to Graf Pelny.
                    czyPelny = false;

                }
                if (graphGradeCounter != 2) {                                                    // Oraz stopien wierzcholka mniejszy niz 2 to:  nie jest to cykl.
                    czyCykl = false;
                    if (czyPelny == false) {
                        cin.ignore(graphLongSize - i);
                        goto TestowaEtykieta;
                    }
                }
            }
            //if (i%graphSize == graphSize-1) {
            //    cout << i << " |  Czy jest cyklem: " << czyCykl << "  Czy jest Pelny: " << czyPelny << " Czy jest nieparzysty: " << graphSize % 2 << endl;
            //}
        }
        TestowaEtykieta:
        if ((czyCykl == 1 && czyNieParzysty == 1) || czyPelny == 1) {
            cout << "True\n";
        }
        else {
            cout << "False\n";
        }
    }
}

