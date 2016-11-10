//
// Created by zhangwei217245 on 11/10/16.
//

#ifndef CPPDATASTRUCTURE_SORT_H
#define CPPDATASTRUCTURE_SORT_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;


template <class X>
class Data{
public:
    X *arr;
    int size;
    Data(X *_arr, int _size){
        arr = _arr;
        size = _size;
    }
    /**
     * algoName = (i|s|b|m|M|q|h)
     * i = insertion sort
     * s = selection sort
     * b = bubble sort
     * m = merge sort without memcpy
     * M = merge sort with memcpy
     * q = quick sort
     * h = heap sort
     * @param data
     * @param algoName
     */
    void sort(Data<X> data, char algoName);
    void mergeSort_MC(Data<X> data);
    void merge_MC(Data<X> part1, Data<X> part2, Data<X> dest);
    void mergeSort_NoMC(Data<X> data);
    void merge_NoMC(Data<X> data);
    void printData(Data<X> data);
};


template <class X>
void mergeSort(Data<X> data){
    if (data.size >=2){
        int midIdx = data.size/2 - 1;
        int leftSize = midIdx + 1;
        int rightSize = data.size - (midIdx + 1);
        int leftPart[leftSize];
        int rightPart[rightSize];
        memcpy(leftPart, arr, (leftSize)*sizeof(int));
        memcpy(rightPart, &arr[midIdx+1], (rightSize)*sizeof(int));
        mergeSort(leftPart, leftSize);
        mergeSort(rightPart, rightSize);
        merge(leftPart, leftSize, rightPart, rightSize, arr);
    }
}

template <class X>
void mergeSort_MC(Data<X> data){
    for (int i = 0 ; i < data.size ; i++){
        cout << data.arr[i] << "  ";
    }
    cout << endl;
}

template <class X>
void merge_MC(Data<X> part1, Data<X> part2, Data<X> dest){
    int i=0, j=0, k=0;
    while ((i<part1.size) && (j<part2.size))
    {
        if (part1.arr[i] <= part2.arr[j])
        {
            /* copy part1.arr[i] to dest.arr[k] and move the pointer i and k forward */
            dest.arr[k] = part1.arr[i];
            i++;
            k++;
        }
        else
        {
            /* copy part2.arr[j] to dest.arr[k] and move the pointer j and k forward */
            dest.arr[k] = part2.arr[j];
            j++;
            k++;
        }
    }

    /* move the remaining elements in part1.arr into dest */
    while (i < part1.size)
    {
        dest.arr[k]= part1.arr[i];
        i++;
        k++;
    }
    /* move the remaining elements in part2.arr into dest */
    while (j < part2.size)
    {
        dest.arr[k]= part2.arr[j];
        j++;
        k++;
    }
}

template <class X>
void printArray(Data<X> data){
    for (int i = 0 ; i < data.size ; i++){
        cout << data.arr[i] << "  ";
    }
    cout << endl;
}

#endif //CPPDATASTRUCTURE_SORT_H
