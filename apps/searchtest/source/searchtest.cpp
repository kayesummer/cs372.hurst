//
// File:    searchtest
// Author: Kaylee Hurst
// Purpose:
// compares the execution time of binary search vs. lookup times in a binary search tree
//

#include "tree.h"       //to use tree ADT
#include <vector>       //to use vector ADT
#include <algorithm>    //to use sort function
#include <chrono>       //to time averages
#include <iomanip>      //for print table 
#include <iostream>
using namespace std;

//global variables
struct myStructure
{
    int size;
    Tree<int> *treePtr = new Tree<int>;
    vector<int> *vectorPtr = new vector<int>;
};

//function prototypes 
myStructure* fillAndSort(const int); 
void vectorBinarySearch(vector<int> *, const int, int);
void bstSearch(Tree<int> *, int);


int main()
{   
    //variables
    const int NUMOFTESTS = 5;
    const int LOOP = 100;
    const int TESTSIZES [NUMOFTESTS] = {1000, 2500, 5000, 10000, 50000};
    double vectorAverages[NUMOFTESTS];
    double bstAverages[NUMOFTESTS];
    double vectorSum = 0;
    double bstSum = 0;
    srand(0);
    
    for (int count = 0; count < NUMOFTESTS; count++)    //call each function & insert averages into arrays
    { 
        myStructure* structPtr = fillAndSort(TESTSIZES[count]);   
        for (int counter = 0; counter < LOOP; counter++)
        {
            int value = rand() % TESTSIZES[count];  //get random number
            //time binary search times
            auto start1 = chrono::steady_clock::now();
            vectorBinarySearch((structPtr->vectorPtr), TESTSIZES[count], value);
            auto end1 = chrono::steady_clock::now();
            chrono::duration<double> elapsed_seconds1 = end1 - start1; 
            vectorSum += elapsed_seconds1.count();

            //time bst search times
            auto start2 = chrono::steady_clock::now();
            bstSearch((structPtr->treePtr), value); 
            auto end2 = chrono::steady_clock::now();
            chrono::duration<double> elapsed_seconds2 = end2 - start2;
            bstSum += elapsed_seconds2.count();
        }
        vectorAverages[count] = vectorSum / LOOP;
        bstAverages[count] = bstSum / LOOP;
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

myStructure* fillAndSort(const int size)
{
    myStructure* structPtr = new myStructure;
    srand(0);
    
    for (int count = 0; count < size; count++)  //fill the vector with random integers
    {
        (structPtr->vectorPtr)->push_back(rand() % size);
    }
    sort((structPtr->vectorPtr)->begin(), (structPtr->vectorPtr)->end());   //sort vector
    
    for (int count = 0; count < size; count++)      //fill tree with same elements in vector
    {
        (structPtr->treePtr)->insert((structPtr->vectorPtr->at(count)));        //having issues assigning vector values to bst, used .at() b/c [] was giving errors
    }
    return structPtr;
}

template <typename T>
void vectorBinarySearch(vector<T> *V, const int size, T value)
{
    T first = 0;
    T last = size - 1;
    T middle = 0;
    T position = -1;
    bool found = false;

    while(!found && first <= last)
    {
        middle = (first + last) / 2;    //calc midpoint
        if (V[middle] == value)
        {
            found = true;
            position = middle;
        }
        else if (V[middle] > value)     //if in lower half
        {
            last = middle - 1;
        }
        else        //if in upperhalf
        {
            first = middle + 1;
        }
    }
    if (found)
    {
        cout << "vector: found ";
    }
    else 
    {
        cout << "vector: not found ";
    }
}

void bstSearch(Tree<int> *treePtr, int value)
{
    bool found = (treePtr)->member(value);
    if (found)
    {
        cout << "bst: found ";
    }
    else 
    {
        cout << "bst: not found ";
    }
}

