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
  Array(int size_t) {
    arr = new T[size_t];
    aCapacity = 1;
    length = size_t;
  }
  ~Array() {
    delete [] arr;
    arr = nullptr;
  }

  void put(T data, int index) {
    if (index == aCapacity) {
      push_back(data);
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
			std::cerr << "Array: index out of bounds on access" << std::endl;
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
			std::cout << arr[i] << std::endl;
		}
		std::cout << std::endl;
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
      std::cerr << std::endl << "Array index out of bounds" << std::endl;
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