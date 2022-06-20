//
// File:   container.h
// Author: Kaylee Hurst
// Purpose:
// Implement a container class.
//

template <typename T>
class Container
{
    virtual int size() = 0;
    virtual int max_size() = 0;
    virtual bool empty() = 0;
    virtual void swap(T& a, T& b) = 0;
    virtual void clear() = 0;
};