//
// File:   bagtest.cpp
// Author: Kaylee Hurst
// Purpose:
// Test the Bag ADT.
//

#include <iostream> 
#include "bag.h"



int main()
{
    Bag<int>aBagOfIntegers;

    if (aBagOfIntegers.size() == 0)
    {
        std::cout << "Congrats, your bag is currently empty!" << std::endl; //constructor behavior
    }
    else
    {
        std::cout << "Opps, something went wrong and your bag is not empty!" << std::endl;
    }

    for (int count = 0; count > 10; count++)    //Insert behavior
    {
        aBagOfIntegers.insert(count);
    }
    if (aBagOfIntegers.size() == 10)
    {
        std::cout << "There are now 10 items in your bag." << std::endl;   
    }
    else 
    {
        std::cout << "Something went wrong in the insert.() function!" << std::endl;
    }


    std::cout << "The Size of the Bag: " << aBagOfIntegers.size() << std::endl;      //size behavior
    
    aBagOfIntegers.insert(9);                                                                               //count behavior
    std::cout << "The number '9' is in this list " << aBagOfIntegers.count(9) << " times." << std::endl;     //testing w/ duplicate- should be 2
    std::cout << "The number '1' is in this list " << aBagOfIntegers.count(1) << " times." << std::endl;    //testing w/o duplicate- should be 1
    std::cout << "The number '25' is in this list " << aBagOfIntegers.count(25) << " times." << std::endl;  //testing w/ no instance- should be 0

    return 0;
}
