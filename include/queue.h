//
// File:   queue.h
// Author: Your Glorious Instructor
// Purpose:
// Implement the Queue ADT.
//

#include "list.h"

template <typename T>

class Queue : public Container<T>
{
    private:
        template <class C>
    class Iterator
    {
        public:
            virtual C * next() = 0 ;
    };
        List<T> *queueList ; = new List<T> ();
        T *queuePtr = queueList.front();
    public:
        Queue() {}

        Queue(Queue &rhs) {}

        ~Queue() { delete queueList; }

        bool empty() override { return queueList.empty(); }

        void push(T data) { queueList.push_front(data); }

        T pop() { return queueList.pop_back(); }

        void traverse(void (*doIt)(T data))
        {
            queueList.traverse(doIt);
        }
        
        int size() override
        {
            queueList.size();
        }

        int max_size() override
        {
            queueList.max_size();
        }

        void swap (T& a, T& b) override
        {
            queueList.swap(a,b);
        }

        void clear () override 
        {
            queueList.clear();
        }

        C * next()
        {
           if (queuePtr == nullptr)
           {
               return nullptr;
           }
           else 
           { 
              queuePtr.next();
              return queuePtr;
           }
        }   
};