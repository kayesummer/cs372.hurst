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

  //to add item to the end of the bag
  void insert(Thing aThing)     
  {
    bagContents->push_back(aThing);
    counter++;
  }

  //to remove the last item in bag
  void pop()      
  {
    Thing aThing;
    if (counter > 0)
    {
      aThing = bagContents[counter];
      bagContents.remove(aThing);
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
  int counter = 0;
};