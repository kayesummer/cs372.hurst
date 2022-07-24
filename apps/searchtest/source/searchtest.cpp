//
// File:    searchtest
// Author: Kaylee Hurst
// Purpose:
// compares the execution time of binary search vs. lookup times in a binary search tree
//

#include "tree.h"
#include <vector>
#include <algorithm>    //to use sort function
#include <chrono>       //to time averages
#include <iomanip>      //for print table 
#include <iostream>
using namespace std;

template <typename T>

//function prototypes
myStructure* fillAndSort(size_t);
double vectorBinarySearch(const int, T[], T);
double bstSearch(int);

//global variables
struct myStructure
{
    size_t size;
    Tree* treePtr = new Tree<int>;
    vector* vectorPtr = new vector<int>;
};

int main()
{   
    //variables
    const int NUMOFTESTS = 5;
    const int TESTSIZES [NUMOFTESTS] = {1000, 2500, 5000, 10000, 50000};
    double vectorAverages[NUMOFTESTS];
    double bstAverages[NUMOFTESTS];
    
    for (int count = 0; count < NUMOFTESTS; count++)    //call each function & insert averages into arrays
    {
        structPtr.size = TESTSIZES[count];
        myStructure* structPtr = fillAndSort(structPtr.size);
        vectorAverages[count] = vectorBinarySearch(TESTSIZES[count]);
        bstAverages[count] = bstSearch(TESTSIZES[count]); 
        delete structPtr;       //reset struct variables
        structPtr = nullptr;
    }
    
    //Print table
    cout << setprecision(8) << fixed << showpoint;
    cout << "    Vector and Tree Size and Average Times: \n";
    cout << "\tSize:\tVector Average Time:\tTree Average Time:\n";
    for (int count = 0; count < NUMOFTESTS; count++)
    {
        cout << TESTSIZES[count] << "\t" << vectorAverages[count] << "\t" << bstAverages[count] << endl;
    }

    return 0; 
}

myStructure* fillAndSort(size_t size)
{
    myStructure* structPtr = new myStructure;
    srand(0);
    
    for (int count = 0; count < size; count++)  //fill the vector with random integers
    {
        structPtr.vectorPtr.push_back(rand() % size);
    }
    sort(structPtr.vectorPtr.begin(), structPtr.vectorPtr.end());   //sort vector
    
    for (int count = 0; count < size; count++)      //fill tree with same elements in vector
    {
        structPtr.treePtr.insert(structPtr.vectorPtr[count]);
    }

    return structPtr;
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

double bstSearch(int findMe)
{
    double sum = 0;
    double average = 0;
    int loop = 20;
    for (int count = 0; count < loop; count++)
    {
        auto start = chrono::steady_clock::now();
        structPtr.treePtr.member(findMe);
        auto end = chrono::steady_clock::now();
        chrono::duration<double> elapsed_seconds = end - start; 
        sum += elapsed_seconds.count();
    }

    average = sum / loop;
    return average;
}

