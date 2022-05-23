//
// File:   listtest.cpp
// Author: Your Glorious Instructor <adam.lewis@athens.edu>
// Purpose:
// Demonstrate the use of our List class.
//
/* This info is also in a pdf in docs folder! 
Five Additional Test Cases: 
    1. test if the list is not empty when initialized
    2. test .front();
    3. changing last value in list with .back()
    4. changing first value in list with .front()
    5. adding a specific value to the front of the list w/ push_front 
*/
#include <iostream>
#include "list.h"

template <typename T>
void printItem(T &item) {
  std::cout << item << " ";
}

int main() {
  List<int> aListOfIntegers;
  if (aListOfIntegers.empty()) {  //test if empty
    std::cout << "Yep, the new list is empty. " << std::endl;
  }
  if (!aListOfIntegers.empty()) //**Kaylee test if initialization was correct
  {
    std::cout << "Something was initialized wrong, this list is not empty!" << std::endl;
  }
  for (int i = 10; i >= 0; i--) {
    aListOfIntegers.push_front(i);  //test push_front
  }
  aListOfIntegers.traverse(printItem);
  std::cout << std::endl;
  for (int i = 0; i < 10; i++) {
    std::cout << aListOfIntegers.back() << " "; //test back
    aListOfIntegers.pop_back();
  }
  if (!aListOfIntegers.empty()) {   //tests if not empty
    aListOfIntegers.traverse(printItem);  
    std::cout << std::endl;
  }
  aListOfIntegers.push_back(42);  //tests adding 42 to the end of the container
  aListOfIntegers.traverse(printItem);
  std::cout << std::endl;

  aListOfIntegers.push_front(5);  //**Kaylee tests adding 5 to the front of the container
  aListOfIntegers.traverse(printItem);
  std::cout << std::endl;

  for (int i = 0; i < 10; i++)
  {
    std::cout << aListOfIntegers.front() << " "; //**Kaylee tests front
  }
  std::cout << std::endl;

  aListOfIntegers.back() = 11;    //**Kaylee tests changing the last value w/ .back()
  aListOfIntegers.traverse(printItem);
  std::cout << std::endl;

  aListOfIntegers.front() = 1;    //**Kaylee tests changing the first value w/ .front()
  aListOfIntegers.traverse(printItem);
  std::cout << std::endl;

  return 0;
}