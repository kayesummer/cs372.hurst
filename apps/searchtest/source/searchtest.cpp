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
double vectorBinarySearch(const int, T[], T);
struct* fillAndSort(size_t);
double bstSearch(size_t);

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
        structure.size = sizes[count];
        fillAndSort(structre.size);
        vectorAverages[count] = vectorBinarySearch(SIZES[count]);
        bstAverages[count] = bstSearch(sizes[count]); 
    }
    

    return 0; 
}

template <typename T>
double vectorBinarySearch(const int size, T A[], T value)
{
    int first = 0;
    int last = size - 1;
    int middle = 0;
    int position = -1;
    bool found = false;
    double sum = 0;
    double average = 0;
    int loop = 20;

    for (int count = 0; count < loop; count++)
    {
        auto start = chrono::steady_clock::now();
        while(!found && first <= last)
        {
            middle = (first + last) / 2;    //calc midpoint
            if (A[middle] == value)
            {
                found = true;
                position = middle;
            }
            else if (A[middle] > value)     //if in lower half
            {
                last = middle - 1;
            }
            else        //if in upperhalf
            {
                first = middle + 1;
            }
        }

        auto end = chrono::steady_clock::now();
        chrono::duration<double> elapsed_seconds = end - start; 
        sum += elapsed_seconds.count();
    }

    average = sum / loop;
    return average;
}

struct* fillAndSort(size_t size)
{

}

double bstSearch(size_t size)
{
    double sum = 0;
    double average = 0;
    int loop = 20;
    for (int count = 0; count < loop; count++)
    {
        auto start = chrono::steady_clock::now();

        auto end = chrono::steady_clock::now();
        chrono::duration<double> elapsed_seconds = end - start; 
        sum += elapsed_seconds.count();
    }

    average = sum / loop;
    return average;
}

