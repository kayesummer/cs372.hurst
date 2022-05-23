//
// File:   assignment1.cpp
// Author: Kaylee Hurst
// Purpose:
// Illustrate some of the bad things that can happen with
// pointers
//
#include <iostream>
#include <string>
using namespace std;

void mistake1 ();
void mistake2 ();
string mistake3();
void helper(string);


int main() {
  // Put your code here.
  mistake1();
  mistake2();
  string badWord = mistake3();
  helper(badWord);
  return 0;
}

void mistake1 ()    //dangling reference
{
    const int SIZE = 100;
    int* array1 = new int[SIZE];

    for (int count = 0; count < SIZE; count++)
    {
        array1[count] = count;
    }

    int* array2 = array1;
    delete[] array1;

    for (int counter = 0; counter < 10; counter++)
    {
        cout << array2[counter] << endl;
    }
}

void mistake2 ()    //shallow copy
{
    const int SIZE = 100;
    int* array1 = new int[SIZE];

    for (int count = 0; count < SIZE; count++)
    {
        array1[count] = count;
    }

    int* ptr1 = array1;
    int* ptr2 = array1;
    delete[] ptr1;

    cout << ptr2 << endl;
    for (int counter = 0; counter < 10; counter++)
    {
        cout << array1[counter] << endl;
    }

}

string mistake3 ()  //bad returns
{
    string* ptr;
    ptr = new string;
    *ptr = "abcdefghijkl";

    return *ptr;
}

void helper (string badWord)
{
    string word = badWord;
    cout << word << endl;
}