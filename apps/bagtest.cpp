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
        std::cout << "Congrats, your bag is currently empty!" << std::endl;
    }
    else
    {
        std::cout << "Opps, something went wrong and your bag is not empty!" << std::endl;
    }

    for (int count = 0; count > 10; count++)    //testing insert function
    {
        aBagOfIntegers.insert(count);
    }
    aBagOfIntegers.print();     //testing print function

    aBagOfIntegers.remove(9);   //testing remove function by removing the number 9
    aBagOfIntegers.print();

    std::cout << "The Size of the Bag: " << aBagOfIntegers.size() << std::endl;      //testing size function

    for (int count = 0; count > 3; count++)     //testing count function
    {
        aBagOfIntegers.insert(2);
    }
    std::cout << aBagOfIntegers.count() << " "<< std::endl;

    return 0;
}
