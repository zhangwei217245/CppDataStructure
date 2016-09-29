/*
 * File:   IntSLList.cpp
 * Author: zhangwei
 *
 * Created on September 22, 2016, 9:52 AM
 */
#include <iostream>
#include "IntSLList.h"
using namespace std;


IntSLList::~IntSLList() {
    for (IntSLLNode *p; !isEmpty();) {
        p = head->next;
        delete head;
        head = p;
    }
}

void IntSLList::printAll() {
    IntSLLNode *tmp; // find the predecessor of tail;
    for (tmp = head; tmp != tail; std::cout<<tmp->info, tmp = tmp->next);
    cout << endl;
}

void IntSLList::addToHead(int el) {
    head = new IntSLLNode(el, head);
    if (tail == 0) tail = head;
}

void IntSLList::addToTail(int el) {
    if (tail != 0) { // if list not empty;
        tail->next = new IntSLLNode(el);
        tail = tail->next;
    } else
        head = tail = new IntSLLNode(el);
}

int IntSLList::deleteFromHead() {
    int el = head->info;
    IntSLLNode *tmp = head;
    if (head == tail) // if only one node in the list;
        head = tail = 0;
    else head = head->next;
    delete tmp;
    return el;

}

int IntSLList::deleteFromTail() {
    int el = tail->info;
    if (head == tail) { // if only one node in the list;
        delete head;
        head = tail = 0;

    } else { // if more than one node in the list,
        IntSLLNode *tmp; // find the predecessor of tail;
        for (tmp = head; tmp->next != tail; tmp = tmp->next);
        delete tail;
        tail = tmp; // the predecessor of tail becomes tail;
        tail->next = 0;
    }
    return el;

}



void IntSLList::deleteNode(int el) {
    if (head != 0){ // if nonempty list;
        if (head == tail && el == head->info) { // if only one delete head;
            // node in the list;
            IntSLLNode *tmp = head;
            delete tmp;
            head = tail = 0;
        } else if (el == head->info) {// if more than one node in the list
            IntSLLNode *tmp = head;
            head = head->next;
            delete tmp; // and old head is deleted;
        } else { // if more than one node in the list
            IntSLLNode *pred, *tmp;
            for (pred = head, tmp = head->next; // and a nonhead node
                    tmp != 0 && !(tmp->info == el); // is deleted;
                    pred = pred->next, tmp = tmp->next);
            if (tmp != 0) {
                pred->next = tmp->next;
                if (tmp == tail)
                    tail = pred;
                delete tmp;
            }
        }
    }
}

bool IntSLList::isInList(int el) const {
    IntSLLNode *tmp;
    for (tmp = head; tmp != 0 && !(tmp->info == el); tmp = tmp->next);
    return tmp != 0;
}
