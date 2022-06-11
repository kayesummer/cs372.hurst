//
// File:   iterator.h
// Author: Your Glorious Instructor
// Purpose:
// Implement a pure virtual iterator class.
//

template <class C>
class Iterator
{
    public:
        virtual C * next() = 0 ;
};