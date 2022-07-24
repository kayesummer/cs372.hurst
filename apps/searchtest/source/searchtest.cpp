//
// File:    searchtest
// Author: Kaylee Hurst
// Purpose:
// compares the execution time of binary search vs. lookup times in a binary search tree
//

#include "tree.h"
#include <vector>
#include <algorithm>
#include <chrono>
#include <iostream>

template <typename T>

//function prototypes
vectorBinarySearch(const int, T[]);
fillAndSort(size_t);
bstSearch(size_t);

struct structure
{
    size_t size;

};

int main()
{   
    const int NUMOFTESTS = 5;
    const int SIZES [NUMOFTESTS] = {1000, 2500, 5000, 10000, 50000};
    double vectorAverages[NUMOFTESTS];
    double bstAverages[NUMOFTESTS];
    

    for (int count = 0; count < NUMOFTESTS; count++)
    {
        vectorAverages[count] = vectorBinarySearch(SIZES[count]);
        bstAverages[count] = bstSearch(sizes[count]);
    }
    

    return 0; 
}

template <typename T>
vectorBinarySearch(const int size, T A[])
{

}

fillAndSort(size_t size)
{

}

bstSearch(size_t size)
{

}

