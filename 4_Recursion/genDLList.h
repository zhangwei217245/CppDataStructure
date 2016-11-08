#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

#include <iostream>
#include <string>
#include <cstddef>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <vector>
#include <stdio.h>
using namespace std;

template<class T>
class DLLNode {
public:
    DLLNode() {
        next = prev = 0;
    }
    DLLNode(const T& el, DLLNode<T> *n = 0, DLLNode<T> *p = 0) {
        info = el; next = n; prev = p;
    }
    T info;
    DLLNode<T> *next, *prev;
};

template<class T>
class DoublyLinkedList {
public:
    DoublyLinkedList() {
        head = tail = 0;
    }
    void addToDLLTail(const T&);
    T deleteFromDLLTail();
    ~DoublyLinkedList() {
        clear();
    }
    bool isEmpty() const {
        return head == 0;
    }
    void clear();
    void setToNull() {
        head = tail = 0;
    }
    DLLNode<T>* getHead(){return head;}
    DLLNode<T>* getTail(){return tail;}
    void addToDLLHead(const T&);
    T deleteFromDLLHead();
    T& firstEl();
    T& lastEl();
    DLLNode<T>* find(const T&) const;
    DLLNode<T>* findPlace(DLLNode<T>*, const T&) const;
    DLLNode<T>* recursiveSearch(DLLNode<T>*, DLLNode<T>*, const T&) const;
    void addNode(const T&);
    void printAll();
protected:
    DLLNode<T> *head, *tail;
    friend ostream& operator<<(ostream& out, const DoublyLinkedList<T>& dll) {
        for (DLLNode<T> *tmp = dll.head; tmp != 0; tmp = tmp->next)
            out << tmp->info << ' ';
        return out;
    }
};

template<class T>
void DoublyLinkedList<T>::addToDLLHead(const T& el) {
    if (head != 0) {
         head = new DLLNode<T>(el,head,0);
         head->next->prev = head;
    }
    else head = tail = new DLLNode<T>(el);
}

template<class T>
void DoublyLinkedList<T>::addToDLLTail(const T& el) {
    if (tail != 0) {
         tail = new DLLNode<T>(el,0,tail);
         tail->prev->next = tail;
    }
    else head = tail = new DLLNode<T>(el);
}

template<class T>
T DoublyLinkedList<T>::deleteFromDLLHead() {
    T el = head->info;
    if (head == tail) { // if only one DLLNode on the list;
         delete head;
         head = tail = 0;
    }
    else {              // if more than one DLLNode in the list;
         head = head->next;
         delete head->prev;
         head->prev = 0;
    }
    return el;
}

template<class T>
T DoublyLinkedList<T>::deleteFromDLLTail() {
    T el = tail->info;
    if (head == tail) { // if only one DLLNode on the list;
         delete head;
         head = tail = 0;
    }
    else {              // if more than one DLLNode in the list;
         tail = tail->prev;
         delete tail->next;
         tail->next = 0;
    }
    return el;
}

template <class T>
DLLNode<T>* DoublyLinkedList<T>::findPlace(DLLNode<T>* node, const T& el) const {
    if (node == 0){
        return 0;
    }
    if (node -> info >= el ) {
        return node;
    } else {
        return findPlace(node -> next , el);
    }
}

template <class T>
void DoublyLinkedList<T>::addNode(const T& el){
    DLLNode<T> *newNode = new DLLNode<T>(el);
    if (this -> isEmpty()){ // list is empty
        head = tail = newNode;
    } else {
        DLLNode<T> *destNode = findPlace(head, el);
        if (destNode == 0) {
          newNode -> next = 0;
          newNode -> prev = tail;
          newNode -> prev -> next = newNode;
          tail = newNode;
        } else {
          cout << destNode->info << endl;
          if (head == destNode) {
            head = newNode;
          }
          newNode -> prev = destNode -> prev;
          newNode -> next = destNode;
          if (destNode -> prev != 0) {
            destNode -> prev -> next =newNode;
          }
          destNode -> prev = newNode;
        }
    }
}

template <class T>
DLLNode<T>* DoublyLinkedList<T>::find(const T& el) const {
    DLLNode<T> *tmp = head;
    for ( ; tmp != 0 && !(tmp->info == el);  // overloaded ==
         tmp = tmp->next);
    if (tmp == 0)
         return 0;
    else return tmp;
}



template <class T>
DLLNode<T>* DoublyLinkedList<T>::recursiveSearch(DLLNode<T>* front, DLLNode<T> *rear, const T& el) const {
  DLLNode<T>* fn = 0; //the next of front
  DLLNode<T>* rp = 0; //the prev of rear
  if (front != 0){
      fn = front -> next;
      if (front -> info == el) {
        return front;
      }
  }
  if (rear != 0) {
      rp = rear -> prev;
      if (rear -> info == el) {
        return rear;
      }
  }
  return recursiveSearch(fn, rp, el);
}



template<class T>
T& DoublyLinkedList<T>::firstEl() {
    if (isEmpty()) {
        throw string("The list is empty.");
    }
    return head->info;
}

template<class T>
T& DoublyLinkedList<T>::lastEl() {
    if (isEmpty()) {
        throw string("The list is empty.");
    }
    return tail->info;
}

template<class T>
void DoublyLinkedList<T>::clear() {
    for (DLLNode<T> *tmp; head != 0; ) {
        tmp = head;
        head = head->next;
        delete tmp;
    }
    setToNull();
}

template<class T>
void DoublyLinkedList<T>::printAll() {
    cout << "LinkedList = " ;
    for (DLLNode<T> *tmp = head; tmp != 0; ) {
        cout << tmp -> info << " ";
        tmp = tmp-> next;
    }
    cout << endl;
}


#endif
