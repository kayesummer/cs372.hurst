//
// File:   receiptbagtest.cpp
// Author: Kaylee Hurst
// Purpose:
// Test the Receipt Bag ADT.
//

#include <iostream> 
#include "receiptbag.h"
using namespace std;



int main()
{
    ReceiptBag<int>aBagOfIntegers;

    //constructor behavior
    if (aBagOfIntegers.size() == 0)
    {
        cout << "Congrats, your bag is currently empty!" << endl; 
    }
    else
    {
        cout << "Opps, something went wrong and your bag is not empty!" << endl;
    }

    //Insert behavior
    for (int count = 0; count > 10; count++)    
    {
        aBagOfIntegers.insert(count);
    }
    if (aBagOfIntegers.size() == 10)
    {
        cout << "There are now 10 items in your bag." << endl;   
    }
    else 
    {
        cout << "Something went wrong in the .insert() function!" << endl;
    }

    //size behavior
    cout << "The Size of the Bag: " << aBagOfIntegers.size() << endl;      
    
    //testing receipt return
    cout << aBagOfIntegers.insert(9) << endl;              

    //count behavior
    cout << "The number '9' is in this list " << aBagOfIntegers.count(9) << " times." << endl;     //testing w/ duplicate- should be 2
    cout << "The number '1' is in this list " << aBagOfIntegers.count(1) << " times." << endl;    //testing w/o duplicate- should be 1
    cout << "The number '25' is in this list " << aBagOfIntegers.count(25) << " times." << endl;  //testing w/ no instance- should be 0

    //pop behavior
    cout << aBagOfIntegers.pop() << endl;       
    if (aBagOfIntegers.size() == 10)
    {
        cout << "There are 10 items in your bag, again." << endl;   
    }
    else 
    {
        cout << "Something went wrong in the .pop() function!" << endl;
    }

    return 0;
}
