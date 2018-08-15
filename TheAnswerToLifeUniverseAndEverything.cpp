// c++14 gcc

#include <iostream>

using namespace std;

void printRecursivly(int numbers[], int size, int i);

int TheAnswerToLifeUniverseAndEverything()
{
    int numbers[]={1,2,3,4,5,6,7,8,9,0,9,8,7,6,5,4,3,2,1,11,21,31,41,51,61,71,81,91,99,89,79,69,59,49,39,29,19,42,3,6,11};
    printRecursivly(numbers, sizeof(numbers)/sizeof(numbers[0]), 0);
    return 0;
}

void printRecursivly(int numbers[], int size, int i)
{
    if (i == size || numbers[i] == 42) return;
    cout<<numbers[i]<<endl;
    printRecursivly(numbers, size, ++i);
}
