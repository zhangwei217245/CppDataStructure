#include<iostream>
using namespace std;
template <class X> void mergeSort(X*, int, int);
template <class X> void merge(X*, int, int, int);

int main() {
	int numOfDigitsInArray;
	cout << "Enter number of digits in array: ";
	cin >> numOfDigitsInArray;

	int* arrayOfInt = new int [numOfDigitsInArray];
	for(int i = 0; i < numOfDigitsInArray; i++)
		arrayOfInt [i] = rand()%100;

	double* arrayOfDouble = new double [numOfDigitsInArray];
	for(int i = 0; i < numOfDigitsInArray; i++)
		arrayOfDouble[i] = (double)(rand() % 10000) / 100;

	char* arrayOfChar = new char [numOfDigitsInArray];
	for(int i = 0; i < numOfDigitsInArray; i++)
		arrayOfChar[i] = rand()%100;

	for(int i = 0; i < numOfDigitsInArray; i++)
		cout << arrayOfInt[i] << " ";

	cout << endl;
	mergeSort(arrayOfInt, 0, numOfDigitsInArray-1);
//	mergeSort(arrayOfChar, 0, numOfDigitsInArray-1);
//	mergeSort(arrayOfDouble, 0, numOfDigitsInArray-1);


	for(int i = 0; i < numOfDigitsInArray; i++)
		cout << arrayOfInt[i] << " ";

}


template <class X> void mergeSort(X* arr, int left, int right ) {
	if(right - left > 0) {
		int middle = (left + right) / 2;
		mergeSort(arr, left, middle);
		mergeSort(arr, middle+1, right);
		merge(arr, left, right, middle);
	}		
}


template <class X> void merge(X* arrayMain, int left,int right,int middle) {
	int i=0,j=left,k=middle+1;
	X* arrayAdditional=new X[right-left+1];
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


