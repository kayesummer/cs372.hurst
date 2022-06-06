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
class ReceiptBag {
public:
  ReceiptBag() 
  {
    bagContents = new List<Thing*>;
    bagContents[0] = nullptr;
    receiptID = new List<Thing*>;
    receiptID[0] = nullptr;
  }

  ~ReceiptBag() 
  {
    delete [] bagContents;
    bagContents = nullptr;
    delete [] receiptID;
    receiptID = nullptr;
  }

  int insert(Thing aThing) 
  {
    bagContents->push_back(&aThing);
    counter++;
    receiptID->push_back(receipt);
    receipt++;
    return receipt;
  }

  Thing &pop() 
  {
    Thing* ptrToAThing;
    int i = counter;
    bool thingIsNull = true;
    while (thingIsNull && (i > 0)) {
      if (bagContents[i] != nullptr) {
        ptrToAThing = bagContents[i];
        thingIsNull = false;
        ptrToAThing.remove();
        receiptID[i].remove();
        counter--;
        return ptrToAThing;
      }
    }
  }

  int size() 
  {
    return counter;
  }

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
  List<Thing*> *receiptID
  int counter = 0;
  int receipt = 0;
};