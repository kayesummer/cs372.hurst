//
// File:   receiptbag.h
// Author: Your Glorious Instructor
// Purpose:
// Implement the Bag ADT.
//
#pragma once
#include <iostream>
#include "list.h"

template <typename Thing>
class ReceiptBag 
{
public:
  ReceiptBag() 
  {
    bagContents = new List<Thing*>;
    bagContents[0] = nullptr;
  }

  ~ReceiptBag() 
  {
    delete [] bagContents;
    bagContents = nullptr;
  }

  //to add item to the end of the bag
  int insert(Thing aThing)  
  {
    bagContents->push_back(&aThing);
    counter++;
    receipt++;
    receiptID->push_back(receipt);
    return receipt;
  }

  //to remove the last item in bag
  Thing pop()    
  {
    Thing aThing;
    Thing receiptThing;
    if (counter > 0)
    {
      aThing = bagContents[counter];
      receiptThing = receiptID[counter];
      bagContents.remove(aThing);
      receiptID.remove(receiptThing);
      counter--;
    }
    else 
    {
      std::cerr << "Can't pop out of an empty bag" << std::endl;
    }

    return aThing;
  }

  //returns number of items in bag
  int size()    
  {
    return counter;
  }

  //returns the number of times a thing is in the bag
  int count(Thing aThing)     
  {
    int numberOfTimes = 0;
    for (int i = 0; i < counter; i++)
    {
      if ((bagContents[i]) == aThing)
      {
        numberOfTimes++;
      }
    }
    return numberOfTimes;
  }

private:
  List<Thing*> *bagContents;
  List<int> *receiptID;
  int counter = 0;
  int receipt = 0;
};