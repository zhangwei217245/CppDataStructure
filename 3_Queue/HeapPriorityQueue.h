//
// Created by zhangwei217245 on 11/10/16.
//

#ifndef CPPDATASTRUCTURE_HEAPPRIORITYQUEUE_H
#define CPPDATASTRUCTURE_HEAPPRIORITYQUEUE_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

template <class X> // defining the template class
class HeapPriorityQueue {
    //-------------------------        variables          -------------------
private :
    X *Quee; // making an array of the template X that i wanna build priority quee on
    // first of all making a heap on it
    // then turning heap to a priority quee
    int size; // holds size of the class
    int last_index = -1; // shows last element in heap
    //------------------------        constructors        ----------------------
public:
    HeapPriorityQueue();
    HeapPriorityQueue(int size);

    //-----------------------          Methods               ----------------------
    X peek();// returns the X on
    void push(X input); // adding an X to priority quee
    X pop(); // getting the head of the quee
private:
    bool max_heapify(int index); // this makes a heap  on the array
};


template <class X>
bool HeapPriorityQueue<X>::max_heapify(int index) // this makes a heap  on the array
{

    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left > last_index) // index is in fact a root so it is in the right place
        return false;

    if (right > last_index) // checking the right child
        right = -1;      // setting a sentinel

    // its a little bit tricky cause im working with templates

    int largest = index; // largest is the index of the greatest elements between index , right and left
    // ofcours if u largest doesnt change after comparing no recursive is needed



    if (Quee[left] < Quee[index]) { // shows heap is not fixed
        swap(Quee[left], Quee[index]);
        largest = left;
    }

    if (right != -1) // ofc we should check if this node has a right child
        if (Quee[right] < Quee[index]) // this " > " operator should be overloaded for every class u wish to use
        { // shows heap is not fixed
            swap(Quee[right], Quee[index]);
            largest = right;
        }
    // now checking if largest has changed
    if (index == largest)
        return true;
    return max_heapify(largest);

}

template <class X>
X HeapPriorityQueue<X>::peek()// returns the X on
{
    return Quee[0]; // ofc if its change able priority quee is screwed
}

template <class X>
void HeapPriorityQueue<X>::push(X input) // adding an X to priority quee
{
    if (last_index == size - 1){
        throw string("Queue is already full.");
    }

    last_index++;
    Quee[last_index] = input;
    for (int i = (last_index + 1) / 2; i >= 0; i--) {
        max_heapify(i);
    }
}


template <class X>
X HeapPriorityQueue<X>::pop() // getting the head of the quee
{
    if (last_index == -1){
        throw string("queue is empty");
    }
    X temp = Quee[0];
    swap(Quee[0], Quee[last_index]);
    last_index--;
    // fixing the heap again
    for (int i = (last_index + 1) / 2; i >= 0; i--) {
        max_heapify(i);
    }
    return temp;

}

template <class X>
HeapPriorityQueue<X>::HeapPriorityQueue() { // default constructor
    size = 1;
    Quee = new X[2];// well meh
}

template <class X>
HeapPriorityQueue<X>::HeapPriorityQueue(
        int size) {// if u tend to use this In a real good program check size and , obviously it shouldnt be negetive
    this->size = size;
    Quee = new X[size]; // allocating equal to the input size

}

#endif //CPPDATASTRUCTURE_HEAPPRIORITYQUEUE_H
