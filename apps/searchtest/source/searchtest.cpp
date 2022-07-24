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
#include <iomanip>
#include <iostream>

template <typename T>

//function prototypes
double vectorBinarySearch(const int, T[], T);
struct* fillAndSort(size_t);
double bstSearch(int);

//global variables
struct structure
{
    size_t size;
    Tree* treePtr = new Tree<int>;
    vector* vectorPtr = new vector<int>;
};

int main()
{   
    //variables
    const int NUMOFTESTS = 5;
    const int SIZES [NUMOFTESTS] = {1000, 2500, 5000, 10000, 50000};
    double vectorAverages[NUMOFTESTS];
    double bstAverages[NUMOFTESTS];
    

    for (int count = 0; count < NUMOFTESTS; count++)    //call each function & insert averages into arrays
    {
        structure.size = sizes[count];
        fillAndSort(structure.size);
        vectorAverages[count] = vectorBinarySearch(SIZES[count]);
        bstAverages[count] = bstSearch(sizes[count]); 
    }
    
    //Print table
    cout << setprecision(8) << fixed << showpoint;
    cout << "    Vector and Tree Size and Average Times: \n";
    cout << "\tSize:\tVector Average Time:\tTree Average Time:\n";
    for (int count = 0; count < NUMOFTESTS; count++)
    {
        cout << SIZES[count] << "\t" << vectorAverages[count] << "\t" << bstAverages[count] << endl;
    }

    //delete dynamically allocated variables
    delete [] vectorPtr;
    vectorPtr = nullptr;
    delete treePtr;
    treePtr = nullptr;

    return 0; 
}

template <typename T>
double vectorBinarySearch(const int size, T A[], T value)
{
    T first = 0;
    T last = size - 1;
    T middle = 0;
    T position = -1;
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
    srand(0);
    
    for (int count = 0; count < size; count++)  //fill the vector with random integers
    {
        structure.vectorPtr.push_back(rand() % size);
    }
    sort(structure.vectorPtr.begin(), structure.vectorPtr.end());   //sort vector
    
    for (int count = 0; count < size; count++)      //fill tree with same elements in vector
    {
        structure.treePtr.insert(structure.vectorPtr[count]);
    }

    return *structure;
}

double bstSearch(int findMe)
{
    double sum = 0;
    double average = 0;
    int loop = 20;
    for (int count = 0; count < loop; count++)
    {
        auto start = chrono::steady_clock::now();
        structure.treePtr.member(findMe);
        auto end = chrono::steady_clock::now();
        chrono::duration<double> elapsed_seconds = end - start; 
        sum += elapsed_seconds.count();
    }

    average = sum / loop;
    return average;
}

