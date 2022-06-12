//
// File:   queue.h
// Author: Your Glorious Instructor
// Purpose:
// Implement the Queue ADT.
//

#include "list.h"

template <typename T>

class Queue : public Iterator<T>
{
    private:
        List<T> *queueList ; = new List<T> ();
        T *queuePtr;
    public:
        Queue() {}
        Queue(Queue &rhs) {}
        ~Queue() { delete queueList; }
        bool empty() { return queueList.empty(); }
        void push(T data) { queueList.push_front(data); }
        T pop() { return queueList.pop_back(); }
        void traverse(void (*doIt)(T data))
        {
            queueList.traverse(doIt);
        }
       virtual C * next()
        {
           if (queuePtr == nullptr)
           {
               return nullptr;
           }
           else 
           { 
              ++queuePtr;
              return queuePtr;
           }
        }   
};