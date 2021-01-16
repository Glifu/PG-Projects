// ProblemPlecakowy_v4.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>

    int weight[15];
    int price[15];


int backPack(int remainingWeight, int indexNumber, int numberOfItems) {
    if (remainingWeight == 0 || indexNumber == numberOfItems) {
        return 0;
    }
    if (weight[indexNumber] > remainingWeight) {
        return backPack(remainingWeight, indexNumber + 1, numberOfItems);
    }
    int wInc, wExc; // weightInclude weightExclude
    wInc = price[indexNumber] + backPack(remainingWeight-weight[indexNumber], indexNumber + 1, numberOfItems);
    wExc = backPack(remainingWeight, indexNumber + 1, numberOfItems);

    if (wInc > wExc) {
        return wInc;
    }
    else {
        return wExc;
    }
};


int main()
{
    int numberOfInputs;
    int numberOfItems;
    int carCapacity;
    int result;


    scanf("%d", &numberOfInputs);

    for (int i = 0; i < numberOfInputs; i++) {
        scanf("%d", &numberOfItems);
        for (int a = 0; a < numberOfItems; a++) {
            scanf("%d", &price[a]);
        }
        for (int a = 0; a < numberOfItems; a++) {
            scanf("%d", &weight[a]);
            if ( weight[a] > 100){
                price[a] = price[a] - 5;
            }
        }
        scanf("%d", &carCapacity);
        int profit = -20;
        profit = profit + backPack(carCapacity, 0, numberOfItems);
        if (profit < 0) {
            profit = 0;
        }
        printf("%d\n", profit);
    }
    
}