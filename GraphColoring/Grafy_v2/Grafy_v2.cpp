﻿// Grafy.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
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
    //int graphGradeCounter = 0;

    std::ios::sync_with_stdio(false);

    cin >> numberOfInputs;


    for (int programCyclces = 0; programCyclces < numberOfInputs; programCyclces++) {

        bool czyCykl = true;
        bool czyPelny = true;
        bool czyNieParzysty = true;
        int zeroCounter = 0;
        int oneCounter = 0;
        cin >> graphSize;
        if (graphSize % 2 == 0) {
            czyNieParzysty = false;
        }
        int graphLongSize = graphSize * graphSize;
        for (int i = 0; i < graphLongSize; i++) {
            cin >> inputData;
            if (inputData == '0' && czyPelny == true) {
                zeroCounter++;
                if (zeroCounter > graphSize) {
                    czyPelny = false;
                }
            }
            else if (inputData == '1') {
                oneCounter++;
            }
            if ((i % graphSize) == (graphSize - 1)) {
                if (oneCounter != 2 && czyPelny == false) {
                    czyCykl = false;
                    cin.ignore(graphLongSize - i);
                    goto TestowaEtykieta;
                }
                else {
                    oneCounter = 0;
                }
            }
        }

            //if (i%graphSize == graphSize-1) {
            //    cout << i << " |  Czy jest cyklem: " << czyCykl << "  Czy jest Pelny: " << czyPelny << " Czy jest nieparzysty: " << graphSize % 2 << endl;
            //}
        TestowaEtykieta:
        if ((czyCykl == 1 && czyNieParzysty == 1) || czyPelny == 1) {
            cout << "True\n";
        }
        else {
            cout << "False\n";
        }
    }
}