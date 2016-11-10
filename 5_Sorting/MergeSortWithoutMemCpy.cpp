#include "Sort.h"
using namespace std;
template <class X> void mergeSort(X*, int, int);
template <class X> void merge(X*, int, int, int);

int main() {
	int size = 10;

    srand(time(0));

	int* arrayOfInt = new int [size];
	for(int i = 0; i < size; i++)
		arrayOfInt [i] = rand()%100;

//	double* arrayOfDouble = new double [size];
//	for(int i = 0; i < size; i++)
//		arrayOfDouble[i] = (double)(rand() % 10000) / 100;
//
//	char* arrayOfChar = new char [size];
//	for(int i = 0; i < size; i++)
//		arrayOfChar[i] = rand()%100;

    printArray(arrayOfInt, size);

	cout << endl;
	sort(arrayOfInt, size);
//	sort(arrayOfDouble, size);
//	sort(arrayOfChar, size);


    printArray(arrayOfInt, size);

}

template <class X>
void sort(X *arr, int size){
    mergeSort(arr, 0, size-1);
}


template <class X>
void mergeSort(X* arr, int left, int right ) {
	if(right - left > 0) {
		int middle = (left + right) / 2;
		mergeSort(arr, left, middle);
		mergeSort(arr, middle+1, right);
		merge(arr, left, right, middle);
	}		
}


template <class X>
void merge(X* arrayMain, int left,int right,int middle) {
	int i=0,j=left,k=middle+1;
	X* arrayAdditional=new X[right-left+1];
    printArray(arrayMain, )
	while(j <= middle && k <= right) {
		if(arrayMain[j] <= arrayMain[k]) {
			arrayAdditional[i] = arrayMain[j];
			i++;
			j++;
		}
		else {
			arrayAdditional[i] = arrayMain[k];
			i++;
			k++;
		}
	}
	while(j <= middle) {
		arrayAdditional[i] = arrayMain[j];
		i++;
		j++;
	}
	while(k <= right){
		arrayAdditional[i] = arrayMain[k];
		i++;
		k++;
	}

	for(int i = 0; i < right - left + 1; i++)
		arrayMain[left+i] = arrayAdditional[i];
	delete []arrayAdditional;
}


