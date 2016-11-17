//**********************  genQueue.h  *************************
//     generic queue implemented with doubly linked list 

#ifndef DLL_QUEUE
#define DLL_QUEUE

#include "genDLList.h"

using namespace std;

template<class T>
class Queue {
public:
    Queue() { 
    }
    void clear() {
        lst.clear();
    }
    bool isEmpty() const { 
        return lst.isEmpty();  
    }
    T& front() { 
        return lst.firstEl();  
    }
    T dequeue() {
        T el = lst.firstEl();
        lst.deleteFromDLLHead();
        return el;
    }
    void enqueue(const T& el) {
        lst.addToDLLTail(el);
    }
private:
    DoublyLinkedList<T> lst;
};

#endif

