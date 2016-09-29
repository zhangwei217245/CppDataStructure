/*
 * File:   IntSLList.h
 * Author: zhangwei
 *
 * Created on September 22, 2016, 9:52 AM
 */

#ifndef INTSLLIST_H
#define INTSLLIST_H


class IntSLLNode {
public:
    IntSLLNode() {
        next = 0;
    }
    IntSLLNode(int el, IntSLLNode *ptr = 0) {
        info = el;
        next = ptr;
    }
    int info;
    IntSLLNode *next;
};

class IntSLList {
public:

    IntSLList() {
        head = tail = 0;
    }
    ~IntSLList();

    int isEmpty() {
        return head == 0;
    }
    void printAll();
    void addToHead(int);
    void addToTail(int);
    int deleteFromHead(); // delete the head and return its info;
    int deleteFromTail(); // delete the tail and return its info;
    void deleteNode(int);
    bool isInList(int) const;

private:
    IntSLLNode *head, *tail;
};

#endif /* INTSLLIST_H */
