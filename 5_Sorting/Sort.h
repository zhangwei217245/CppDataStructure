//
// Created by zhangwei217245 on 11/10/16.
//

#ifndef CPPDATASTRUCTURE_SORT_H
#define CPPDATASTRUCTURE_SORT_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


template <class X>
class Data{
private:
    X *arr;
    int size;
    /**
     * Do insertion sort.
     */
    void insertionSort();

    /**
     * Do selection sort.
     */
    void selectionSort();

    /**
     * Do bubble sort.
     */
    void bubbleSort();

    /**
     * Do Shell sort.
     */
    void shellSort();

    /**
     * build min heap
     */
    void build_minheap();
    /**
     * build max heap
     */
    void build_maxheap();
    /**
     * max_heapify function
     * @param heapSize
     * @param rootIndex
     */
    void max_heapify(int heapSize, int rootIndex);

    /**
     * min_heapify function
     * @param heapSize
     * @param rootIndex
     */
    void min_heapify(int heapSize, int rootIndex);

    /**
     * Do heapSort in ascending order
     */
    void heapSortASC();


    /**
     * Do heapSort in descending order
     */
    void heapSortDESC();

    /**
     * partition function for the quick sort.
     * @param low
     * @param high
     * @return
     */
    int partition(int low, int high);
    /**
     * quick sort function
     * @param low
     * @param high
     */
    void quickSort(int low, int high);

    /**
     * Merge sort with memory copy
     */
    void mergeSort_MC();
    /**
     * merge with memory copy
     * @param part1
     * @param part2
     */
    void merge_MC(Data<X> *part1, Data<X> *part2);
    /**
     * merge sort withouth memory copy
     * @param leftIndex
     * @param rightIndex
     */
    void mergeSort_NoMC(int leftIndex, int rightIndex);
    /**
     * merge without memory copy
     * @param leftIndex
     * @param middleIndex
     * @param rightIndex
     */
    void merge_NoMC(int leftIndex, int middleIndex, int rightIndex);
    /**
     * swap the value of a and b.
     * @param a
     * @param b
     */
    void swap(X *a, X *b){
        X t = *a;
        *a = *b;
        *b = t;
    };
public:
    Data(X *_arr, int _size){
        arr = _arr;
        size = _size;
    }
    /**
     * sort the data according to the algoName
     * insertionSort
     * selectionSort
     * bubbleSort
     * shellSort
     * quickSort
     * mergeSort_NoMC
     * mergeSort_MC
     * heapSortASC
     * heapSortDESC
     *
     * @param algoName
     */
    void sort(std::string algoName);
    /**
     * print the data.
     */
    void printData();
};


template <class X>
void Data<X>::heapSortDESC() {
    // Build heap (rearrange array)
    build_minheap();

    cout << "============  MIN HEAP ============" << endl;
    printData();

    // One by one extract an element from heap
    for (int i=size-1; i>=1; i--)
    {
        // Move current root to end
        swap(&arr[0], &arr[i]);
        cout << "------------ i=" << i << " ------------" << endl;
        printData();

        // call max heapify on the reduced heap
        min_heapify(i, 0);
    }
    cout << "===================================" << endl;
}

template <class X>
void Data<X>::heapSortASC() {
    // Build heap

    build_maxheap();

    cout << "============  MAX HEAP ============" << endl;
    printData();

    // One by one extract an element from heap
    for (int i=size-1; i>=1; i--)
    {
        // Move current root to end
        swap(&arr[0], &arr[i]);

        cout << "------------ i=" << i << " ------------" << endl;
        printData();

        // call max heapify on the reduced heap
        max_heapify(i, 0);
    }
    cout << "===================================" << endl;
}

template <class X>
void Data<X>::build_minheap() {
    for(int i = size/2 - 1 ; i >= 0 ; i-- )
    {
        min_heapify (size, i) ;
    }
}

template <class X>
void Data<X>::build_maxheap() {
    for(int i = size/2 - 1 ; i >= 0 ; i-- )
    {
        max_heapify (size, i) ;
    }
}

template <class X>
void Data<X>::max_heapify(int heapSize, int rootIndex) {

    int largest = rootIndex;  // Initialize largest as root
    // in C/C++, the index of the array starts from 0. So we have the following:
    int l = 2*rootIndex + 1;  // left = 2*i+1
    int r = 2*rootIndex + 2;  // right = 2*i + 2

    // If left child is larger than root
    if (l < heapSize && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < heapSize && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != rootIndex)
    {
        swap(&arr[rootIndex], &arr[largest]);

        // Recursively heapify the affected sub-tree
        max_heapify(heapSize, largest);
    }
}


template <class X>
void Data<X>::min_heapify(int heapSize, int rootIndex) {

    int smallest = rootIndex;  // Initialize largest as root
    int l = 2*rootIndex + 1;  // left = 2*i + 1
    int r = 2*rootIndex + 2;  // right = 2*i + 2

    // If left child is larger than root
    if (l < heapSize && arr[l] < arr[smallest])
        smallest = l;

    // If right child is larger than largest so far
    if (r < heapSize && arr[r] < arr[smallest])
        smallest = r;

    // If largest is not root
    if (smallest != rootIndex)
    {
        swap(&arr[rootIndex], &arr[smallest]);

        // Recursively heapify the affected sub-tree
        min_heapify(heapSize, smallest);
    }
}

/**
 * ShellSort is mainly a variation of Insertion Sort.
 * In insertion sort, we move elements only one position ahead.
 * When an element has to be moved far ahead, many movements are involved.
 * The idea of shellSort is to allow exchange of far items.
 * In shellSort, we make the array h-sorted for a large value of h.
 * We keep reducing the value of h until it becomes 1.
 * An array is said to be h-sorted if all sublists of every h’th element is sorted.
 */
template <class X>
void Data<X>::shellSort() {
    cout << "shellSort" << endl;

    cout << "============  BEGIN ============" << endl;
    // Start with a big gap, then reduce the gap
    for (int gap = size/2; gap > 0; gap /= 2)
    {

        cout << "============ gap="<<gap<<" ============" << endl;
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is
        // gap sorted
        for (int i = gap; i < size; i += 1)
        {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            int temp = arr[i];

            // shift earlier gap-sorted elements up until the correct
            // location for a[i] is found
            cout << "------------  shifting from " << i <<" ------------" << endl;
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap){
                arr[j] = arr[j - gap];
                //cout << "shift: ";
                //printData();
            }

            //  put temp (the original a[i]) in its correct location
            arr[j] = temp;
            printData();
        }
    }
    cout << "============   END  ============" << endl;
}


template <class X>
void Data<X>::bubbleSort() {
    cout << "bubbleSort" << endl;
    cout << "============  BEGIN ============" << endl;
    int i, j;
    for (i = 0; i < size-1; i++){
        cout << "============  i = " << i <<" ============" << endl;
        // The first i elements are already in place.
        for (j = size - 1; j > i ; j--){
            if (arr[j] < arr[j-1]){
                swap(&arr[j], &arr[j-1]);
                cout << "------------  SWAP arr[" << j <<"] and arr[" << j-1 <<"] ------------" << endl;
                printData();
            }
        }
    }
    cout << "============   END  ============" << endl;
}

template <class X>
void Data<X>::selectionSort() {
    cout << "selectionSort" << endl;
    cout << "============  BEGIN ============" << endl;
    // One by one move boundary of unsorted subarray
    for (int i = 0,j,least; i < size-1; i++) {
        least = i; //Find the minimum element in unsorted array
        cout << "============  least = i = " << least <<" ============" << endl;
        for (j = i+1; j < size; j++){
            if (arr[j] < arr[least]){
                least = j;
                cout << "------------  least = " << least <<" ------------" << endl;
            }
        }
        // Swap the found minimum element with the first element
        swap(&arr[least], &arr[i]);
        cout << "------------  SWAP arr[" << least <<"] with arr["<<i<<"] ------------" << endl;
        printData();
    }
    cout << "============   END  ============" << endl;
}

template <class X>
void Data<X>::insertionSort() {
    cout << "insertionSort" << endl;
    cout << "============  BEGIN ============" << endl;
    int j, key, i;
    for (j = 1; j < size; j++)
    {
        key = arr[j];
        i = j-1;
        cout << "============  arr[" << j <<"]="<<arr[j]<<" ============" << endl;
        /* Move elements of arr[0..j-1], that are
           greater than key, to one position ahead
           of their current position */
        while (i >= 0 && arr[i] > key)
        {
            arr[i+1] = arr[i];
            i = i-1;
            printData();
        }
        arr[i+1] = key;
        printData();
    }
    cout << "============   END  ============" << endl;
}

template <class X>
void Data<X>::quickSort(int low, int high) {
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

/**
 * This function takes last element as pivot, places
 * the pivot element at its correct position in sorted
 * array, and places all smaller (smaller than pivot)
 * to left of pivot and all greater elements to right
 * of pivot
 * @param low
 * @param high
 */
template <class X>
int Data<X>::partition(int low, int high) {
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    cout << "============ arr["<< high<<"] = "<< pivot<< " as pivot ============" << endl;
    printData();
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot) {
            i++;    // increment index of smaller element
            if (i != j) {
                cout << "------------  SWAP arr[" << i << "] = " << arr[i] << " with arr["
                 << j << "] = " << arr[j] << "------------" << endl;
                swap(&arr[i], &arr[j]);
                printData();
            }

        }
    }
    cout << "------------  SWAP arr["<< i+1 <<"] = " << arr[i] << " with arr["
         << high <<"] = "<< arr[high] << "------------" << endl;
    swap(&arr[i + 1], &arr[high]);
    printData();
    cout << "============AFTER  PARTITION return " << i+1 << "==============" << endl;
    return (i + 1);
}


template <class X>
void Data<X>::mergeSort_NoMC(int leftIndex, int rightIndex){
    if(rightIndex - leftIndex > 0) {
        // Same as (l+r)/2, but avoids overflow for large leftIndex and rightIndex
        int middleIndex = leftIndex + (rightIndex-leftIndex) / 2;
        mergeSort_NoMC(leftIndex, middleIndex);
        mergeSort_NoMC(middleIndex+1, rightIndex);
        merge_NoMC(leftIndex, middleIndex, rightIndex);
    }
}


template <class X>
void Data<X>::merge_NoMC(int leftIndex, int middleIndex, int rightIndex){
    int i=0,j=leftIndex,k=middleIndex+1;

    X* arrayAdditional=new X[rightIndex-leftIndex+1];

    cout << "============  BEFORE MERGING ============" << endl;
    printData();

    while(j <= middleIndex && k <= rightIndex) {
        if(arr[j] <= arr[k]) {
            arrayAdditional[i] = arr[j];
            i++;
            j++;
        }
        else {
            arrayAdditional[i] = arr[k];
            i++;
            k++;
        }
    }
    while(j <= middleIndex) {
        arrayAdditional[i] = arr[j];
        i++;
        j++;
    }
    while(k <= rightIndex){
        arrayAdditional[i] = arr[k];
        i++;
        k++;
    }

    for(i = 0; i < rightIndex - leftIndex + 1; i++){
        arr[leftIndex+i] = arrayAdditional[i];
    }
    delete []arrayAdditional;

    cout << "------------  AFTER  MERGING ------------" << endl;
    printData();
    cout << "=========================================" << endl;
}


template <class X>
void Data<X>::mergeSort_MC(){
    if (size >=2){
        int midIdx = size/2 - 1;
        int leftSize = midIdx + 1;
        int rightSize = size - leftSize;


        int leftArr[leftSize];
        int rightArr[rightSize];

        memcpy(leftArr, arr, (leftSize)*sizeof(int));
        memcpy(rightArr, &arr[midIdx+1], (rightSize)*sizeof(int));

        Data<X> *left = new Data(leftArr, leftSize);
        Data<X> *right = new Data(rightArr, rightSize);

        left -> mergeSort_MC();
        right-> mergeSort_MC();
        merge_MC(left, right);

        delete left;
        delete right;

    }
}

template <class X>
void Data<X>::merge_MC(Data<X> *part1, Data<X> *part2){
    int i=0, j=0, k=0;
    cout << "============  TWO PARTS ============" << endl;
    part1->printData();
    part2->printData();
    cout << "------------    INTO    ------------" << endl;
    while ((i<part1->size) && (j<part2->size))
    {
        if (part1->arr[i] <= part2->arr[j])
        {
            /* copy part1.arr[i] to dest.arr[k] and move the pointer i and k forward */
            arr[k] = part1->arr[i];
            i++;
            k++;
        }
        else
        {
            /* copy part2.arr[j] to dest.arr[k] and move the pointer j and k forward */
            arr[k] = part2->arr[j];
            j++;
            k++;
        }
    }

    /* move the remaining elements in part1.arr into dest */
    while (i < part1->size)
    {
        arr[k]= part1->arr[i];
        i++;
        k++;
    }
    /* move the remaining elements in part2.arr into dest */
    while (j < part2->size)
    {
        arr[k]= part2->arr[j];
        j++;
        k++;
    }
    printData();
    cout << "====================================" << endl;
}


template <class X>
void Data<X>::sort(std::string algoName) {
    cout << "Data before sorting: ";
    printData();
    if (algoName.compare("insertionSort") == 0){
        insertionSort();
    } else if (algoName.compare("shellSort") == 0) {
        shellSort();
    } else if (algoName.compare("selectionSort") == 0) {
        selectionSort();
    } else if (algoName.compare("bubbleSort") == 0) {
        bubbleSort();
    } else if (algoName.compare("quickSort") == 0) {
        cout << "quickSort" << endl;
        quickSort(0, size - 1);
    } else if (algoName.compare("mergeSortMC") == 0) {
        cout << "mergeSort_MC" << endl;
        mergeSort_MC();
    } else if (algoName.compare("mergeSortNoMC") == 0) {
        cout << "mergeSort_NoMC" << endl;
        mergeSort_NoMC(0, size - 1);
    } else if (algoName.compare("heapSortASC") == 0) {
        cout << "heapSortASC" << endl;
        heapSortASC();
    } else if (algoName.compare("heapSortDESC") == 0) {
        cout << "heapSortDESC" << endl;
        heapSortDESC();
    } else {
        cout << "Supported Sorting Algorithms:" << endl;
        cout << "insertionSort" << endl;
        cout << "shellSort" << endl;
        cout << "selectionSort" << endl;
        cout << "bubbleSort" << endl;
        cout << "quickSort" << endl;
        cout << "mergeSortMC" << endl;
        cout << "mergeSortNoMC" << endl;
        cout << "heapSortASC" << endl;
        cout << "heapSortDESC" << endl;
        cout << "ARRAY IS NOT SORTED!!!" << endl;
        return ;
    }

    cout << "Data after  sorting: ";
    printData();
}

template <class X>
void Data<X>::printData(){
    for (int i = 0 ; i < size ; i++){
        cout << arr[i] << "  ";
    }
    cout << endl;
}

#endif //CPPDATASTRUCTURE_SORT_H
