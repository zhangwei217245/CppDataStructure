#include <iostream>

using namespace std;

#define BOUND 5

void array(){
	int numbers[BOUND];
	for (int i = 0; i <= BOUND-1; i++){
		numbers[i]=i;
	}
	cout << numbers[2] << endl;
	cout << numbers[6] << endl;
}

void arrayAsPointer(){
	int *numbers = new int[BOUND];
	for (int i = 0; i <= 4; i++) {
		*(numbers + i*2) = i;
	}
	cout << numbers[6] << endl;
	cout << numbers[7] << endl;
}

void array2d(){
	int a[BOUND][BOUND];
	for (int i = 0; i < BOUND; i ++){
		for (int j = 0; j < BOUND; j++){
			a[i][j]=i+j;
		}
	}

	for (int i = 0; i < BOUND; i++) {
		for (int j = 0; j< BOUND; j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}	
}

int main(){

	array();
	arrayAsPointer();
	array2d();
	
}
