#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;


void merge(int leftArr[], int leftSize, int rightArr[], int rightSize, int dest[]){
    int i=0, j=0, k=0;
    while ((i<leftSize) && (j<rightSize))
    {
        if (leftArr[i] <= rightArr[j])
        {
            /* copy leftArr[i] to dest[k] and move the pointer i and k forward */
            dest[k] = leftArr[i];
            i++;
            k++;
        }
        else
        {
            /* copy rightArr[j] to dest[k] and move the pointer j and k forward */
            dest[k] = rightArr[j];
            j++;
            k++;
        }
    }

    /* move the remaining elements in leftArr into dest */
    while (i < leftSize)
    {
        dest[k]= leftArr[i];
        i++;
        k++;
    }
    /* move the remaining elements in rightArr into dest */
    while (j < rightSize)
    {
        dest[k]= rightArr[j];
        j++;
        k++;
    }

}

void mergeSort(int *arr, int size){
    if (size >=2){
        int midIdx = size/2 - 1;
        int leftSize = midIdx + 1;
        int rightSize = size - (midIdx + 1);
        int leftPart[leftSize];
        int rightPart[rightSize];
        memcpy(leftPart, arr, (leftSize)*sizeof(int));
        memcpy(rightPart, &arr[midIdx+1], (rightSize)*sizeof(int));
        mergeSort(leftPart, leftSize);
        mergeSort(rightPart, rightSize);
        merge(leftPart, leftSize, rightPart, rightSize, arr); 
    }
}


void printArray(int arr[], int size){
    for (int i = 0 ; i < size ; i++){
        cout << arr[i] << "  ";
    }
    cout << endl;
}

int main()
{
    int size = 10;
    int a[size];
    srand(time(0));
    for (int i = 0; i < 10 ; i++){
        a[i]=rand()%10 + 1;
    }
    cout << "Before sorting, the content of the array is : " ;
    printArray(a, 10);
    mergeSort(a, 10);
    cout << "After sorting, the content of the array is : " ;
    printArray(a, 10);
}
