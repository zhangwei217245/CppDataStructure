#ifndef SINGLY_LINKED_LIST
#define SINGLY_LINKED_LIST

#include <string>
#include <iostream>

using namespace std;

template<class T>
class SLLNode {
public:
    SLLNode() {
        next = 0;
    }
    SLLNode(const T& el, SLLNode<T> *n = 0) {
        info = el; next = n;
    }
    T info;
    SLLNode<T> *next;
};

template<class T>
class SinglyLinkedList {
public:
    SinglyLinkedList() {
        head = tail = 0;
    }
    void addToSLLTail(const T&);
    T deleteFromSLLTail();
    ~SinglyLinkedList() {
        clear();
    }
    bool isEmpty() const {
        return head == 0;
    }
    void clear();
    void setToNull() {
        head = tail = 0;
    }
    void addToSLLHead(const T&);
    T deleteFromSLLHead();
    T& firstEl();
    T& lastEl();
    T* find(const T&) const;
    void printAll();
    void printRecursively(const SLLNode<T> *);
    void deleteNode(const T&);
    int deleteAll(const T&);
    void deleteAllAfter(const T&, const SLLNode<T> *, const SLLNode<T> *, int* const);
protected:
    SLLNode<T> *head, *tail;
    friend ostream& operator<<(ostream& out, const SinglyLinkedList<T>& dll) {
        for (SLLNode<T> *tmp = dll.head; tmp != 0; tmp = tmp->next)
            out << tmp->info << ' ';
        return out;
    }
};

template<class T>
void SinglyLinkedList<T>::printAll() {
    // for (SLLNode<T> *tmp = this->head; tmp != 0; tmp = tmp->next){
    //     cout << tmp->info << ' ';
    // }
    printRecursively(this->head);
    cout << endl;
}

template<class T>
void SinglyLinkedList<T>::printRecursively(const SLLNode<T>* node) {
    if (node != 0) {
        cout << node->info << " ";
        printRecursively(node->next);
    } else { // This branch can be implicit
        return;
    }
}

template<class T>
int SinglyLinkedList<T>::deleteAll(const T& el) {
    int delete_count = 0;
    if (isEmpty()) {
        return delete_count;
    } else {
        SLLNode<T> *prev = 0;
        SLLNode<T> *curr = head;
        while (curr != 0) {
            if (curr->info == el) {
                delete_count++;
                if (curr == head) {
                    prev = 0;
                    head = curr->next;
                    if (curr == tail) {
                        tail = head;
                    }
                    delete curr;
                    curr = head;
                } else if (curr != head && curr != tail) {
                    prev->next = curr->next;
                    delete curr;
                    curr = prev->next;
                } else if (curr == tail) {
                    prev->next = curr->next;
                    delete curr;
                    tail = prev;
                    curr = 0;
                }
            } else {
                prev = curr;
                curr = prev -> next;
            }
        }
    }
    return delete_count;
}

template<class T>
void SinglyLinkedList<T>::deleteNode(const T& el) {
    int delete_count = 0;
    if (isEmpty()) {
        return;
    } else {
        SLLNode<T> *prev = 0;
        SLLNode<T> *curr = head;
        while (curr != 0 && delete_count == 0) {
            if (curr->info == el) {
                delete_count++;
                if (curr == head) {
                    prev = 0;
                    head = curr->next;
                    if (curr == tail) {
                        tail = head;
                    }
                    delete curr;
                    curr = head;
                } else if (curr != head && curr != tail) {
                    prev->next = curr->next;
                    delete curr;
                    curr = prev->next;
                } else if (curr == tail) {
                    prev->next = curr->next;
                    delete curr;
                    tail = prev;
                    curr = 0;
                }
            } else {
                prev = curr;
                curr = prev -> next;
            }
        }
    }
}

template<class T>
void SinglyLinkedList<T>::addToSLLHead(const T& el) {
    if (head == 0) {
         head = tail = new SLLNode<T>(el);
    } else {
         head = new SLLNode<T>(el,head);
    }
}

template<class T>
void SinglyLinkedList<T>::addToSLLTail(const T& el) {
    if (tail != 0) {
         tail -> next = new SLLNode<T>(el);
         tail = tail -> next;
    }
    else head = tail = new SLLNode<T>(el);
}

template<class T>
T SinglyLinkedList<T>::deleteFromSLLHead() {
    T el = head->info;
    SLLNode<T> *tmp = head;
    if (head == tail) { // if only one SLLNode on the list;
         head = tail = 0;
    } else {              // if more than one SLLNode in the list;
         head = head->next;
    }
    delete tmp;
    return el;
}

template<class T>
T SinglyLinkedList<T>::deleteFromSLLTail() {
    T el = tail->info;
    if (head == tail) { // if only one SLLNode on the list;
         delete head;
         head = tail = 0;
    }
    else {              // if more than one SLLNode in the list;
         SLLNode<T> *tmp; // find the predecessor of tail;
         for (tmp = head; tmp->next != tail; tmp = tmp -> next);
         delete tail;
         tail = tmp;
         tail->next = 0;
    }
    return el;
}

template <class T>
T* SinglyLinkedList<T>::find(const T& el) const {
    SLLNode<T> *tmp;
    for (tmp = head; tmp != 0 && !(tmp->info == el);  // overloaded ==
         tmp = tmp->next);
    if (tmp == 0){
         return 0;
    } else {
         return &tmp->info;
    }
}

template<class T>
T& SinglyLinkedList<T>::firstEl() {
    if (isEmpty()) {
        throw string("The list is empty.");
    }
    return head->info;
}

template<class T>
T& SinglyLinkedList<T>::lastEl() {
    if (isEmpty()) {
        throw string("The list is empty.");
    }
    return tail->info;
}

template<class T>
void SinglyLinkedList<T>::clear() {
    for (SLLNode<T> *tmp; head != 0; ) {
        tmp = head;
        head = head->next;
        delete tmp;
    }
}

#endif
