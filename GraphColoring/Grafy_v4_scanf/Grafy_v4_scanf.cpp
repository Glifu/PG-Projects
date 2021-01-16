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
    //int graphGradeCounter = 0;

    scanf("%d", &numberOfInputs);


    for (int programCyclces = 0; programCyclces < numberOfInputs; programCyclces++) {

        bool czyCykl = true;
        bool czyPelny = true;
        bool czyNieParzysty = true;
        int zeroCounter = 0;
        int oneCounter = 0;
        scanf("%d", &graphSize);
        if (graphSize % 2 == 0) {
            czyNieParzysty = false;
        }
        int graphLongSize = graphSize * graphSize;
        for (int i = 0; i < graphLongSize+1; i++) {
            scanf("%c", &inputData);
            if (inputData == '0' && czyPelny == true) {
                zeroCounter++;
                if (zeroCounter > graphSize) {
                    czyPelny = false;
                }
            }
            else if (inputData == '1') {
                oneCounter++;
            }
            else if (inputData == ' ') {
                i=-1;
            }
            if ((i % graphSize) == (graphSize - 1)) {
                if (oneCounter != 2 && czyPelny == false) {
                    czyCykl = false;
                    scanf("%*[^\n]s\n");
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
            printf( "True\n");
        }
        else {
            printf( "False\n");
        }
    }
}