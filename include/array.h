//
// File:   Array.h
// Author: Kaylee Hurst
// Purpose:
// A simplifed version of the C++ STL array class

#pragma once
#include <iostream>

template <typename T>
class Array {
public:
  Array() {
    arr = new T[1];
    aCapacity = 1;
    length = 0;
  }
  ~Array() {
    delete [] arr;
    arr = nullptr;
  }

  void put(T data, int index) {
    if (index == aCapacity) {
      push_back(T data);
    }
    else {
      arr[index] = data;
    }
  }

  void push_back(T data) {
    // if number of elements is equal to capacity
		// than we need to reallocate and deep copy
		if (length == aCapacity) {
			expand(2 * aCapacity);
		}
		arr[length] = data;
		length++;
  }

  T &at(int index) {
    if (index < 0 || index > length) {
			cerr << "Array: index out of bounds on access" << endl;
			exit(1);
		}
		else {
			return arr[index];
		}
  }

  int size() {
    return length;
  }

  int capacity() {
    return aCapacity;
  }

  void traverse() {
		for (int i = 0; i < length; i++) {
			cout << arr[i] << endl;
		}
		cout << endl;
  }

	bool operator==(Array& other) const {
		if (other.size() != length) {
			return false;
		}
		else {
			for (int i = 0; i < length; i++) {
				if (arr[i] != other.get(i)) {
					return false;
				}
			}
		}
		return true;
	};

  T& operator[](int i) {
    if ((i < 0) || (i >= length)) {
      cerr << endl << "Array index out of bounds" << endl;
    }
    return at(i);
  }

	Array& operator=(const Array& source) {
		// Do a self check.
		if (this == &source)
		{
			return *this;
		}
		// Reset self
		delete[] arr;
		arr = new T[1];
		aCapacity = 1;
		length = 1;
		for (int i = 0; i < source.size(); i++) {
			push_back(source.at(i));
		}
		return *this;
	}
private:
  T *arr = new T[1];
  int aCapacity = 1;
  int length = 1;
  int size_t = 1;

  void expand(int newCapacity) {
    if (newCapacity > aCapacity) {
      T *temp = new T[newCapacity];
      for (int i = 0; i < length; i++) {
        temp[i] = arr[i];
      }
      delete[] arr;
      aCapacity = newCapacity;
      arr = temp;
    }
    else {
      std::cerr << "Array::expand: new capacity is less than equal to current\n";
    }
  }
};