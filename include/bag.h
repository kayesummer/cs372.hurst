//
// File:   bag.h
// Author: Your Glorious Instructor
// Purpose:
// Implement the Bag ADT.
//
#pragma once
#include <iostream>
#include "list.h"

template <typename Thing>
class Bag {
public:
  Bag() 
  {
    bagContents = new List<Thing*>;
    bagContents[0] = nullptr;
  }

  ~Bag() 
  {
    delete [] bagContents;
    bagContents = nullptr;
  }

  void insert(Thing aThing)     //to add item to the end of the bag
  {
    bagContents->push_back(&aThing);
    counter++;
  }

  void pop()      //to remove the last item in bag
  {
    Thing* ptrToAThing;
    int i = counter;
    bool thingIsNull = true;
    while (thingIsNull && (i > 0)) {
      if (bagContents[i] != nullptr) {
        ptrToAThing = bagContents[i];
        thingIsNull = false;
        ptrToAThing.remove();
        counter--;
      }
    }
  }

  int size()      //returns number of items in bag
  {
    return counter;
  }

  int count(Thing aThing)     //returns the number of times a thing is in the bag
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
  int counter = 0;
};