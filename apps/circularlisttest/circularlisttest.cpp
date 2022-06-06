//
// File:   circularlisttest.cpp
// Author: Kaylee Hurst
// Purpose:
// Demonstrate the use of our Circular List class.
//

#include <iostream> 
#include "circularList.h"

template <typename T>
void printItem(T &item) {
  std::cout << item << " ";
}

int main() {
  List<int> aListOfIntegers;
  if (aListOfIntegers.empty()) {  //test if empty
    std::cout << "Yep, the new list is empty. " << std::endl;
  }
  if (!aListOfIntegers.empty()) //test if initialization was correct
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

  aListOfIntegers.push_front(5);  //tests adding 5 to the front of the container
  aListOfIntegers.traverse(printItem);
  std::cout << std::endl;

  for (int i = 0; i < 10; i++)
  {
    std::cout << aListOfIntegers.front() << " "; //tests front
  }
  std::cout << std::endl;

  aListOfIntegers.back() = 11;    //tests changing the last value w/ .back()
  aListOfIntegers.traverse(printItem);
  std::cout << std::endl;

  aListOfIntegers.front() = 1;    //tests changing the first value w/ .front()
  aListOfIntegers.traverse(printItem);
  std::cout << std::endl;

  return 0;
}