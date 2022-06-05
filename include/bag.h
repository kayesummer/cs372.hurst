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
  Bag() {
    bagContents = new List<Thing*>;
    bagContents[0] = nullptr;
  }
  ~Bag() {
    delete [] bagContents;
    bagContents = nullptr;
  }
  void insert(Thing aThing) {
    bagContents->push_back(&aThing);
  }
  void remove(Thing aThing)     //to remove/delete a specific item
  {
    int index = 0;
    int position = -1; 
    bool found = false; 
    int i = bagContents.size();
    while (index < i && !found)     //search for aThing
    {
        if ((bagContents[index].data) == aThing)
        {
            found = true; 
            position = index;
        }
        index++;
    }
    (bagContents[position].prev).next = bagContents[position].next;
    (bagContents[position].next).prev = bagContents[position].prev;
    delete bagContents[position];
  }
  Thing &pop() {
    Thing* ptrToAThing;
    int i = bagContents.size();
    bool thingIsNull = true;
    while (thingIsNull && (i > 0)) {
      if (bagContents[i] != nullptr) {
        ptrToAThing = bagContents[i];
        thingIsNull = false;
      }
    }
    return ptrToAThing;
  }
  int size() {
    return bagContents->capacity();   //getting errors w/ .capacity, so I tried to do the following code, but I don't know what I am doing wrong.
    // Thing* current = bagContents->front();    
    // int count = 0;
    // while (current != nullptr) 
    // {
    //   current = (bagContents[count]).next;
    //   count++;
    // }
    // return count;
  }
  int count() {
    return bagContents.size();
  }
    void printItem(Thing &item) {
    std::cout << item << " ";
    }
  void print()
  {
      bagContents.traverse(printItem);
  }
private:
  List<Thing*> *bagContents;
};