#include <iostream>


using namespace std;

void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

int main(){
	int x;
	int y;
	int *xptr;
	int *yptr;
	x=9;
	y=6;
	xptr = &x;
	yptr = &y;
	int ** xxptr = &xptr;
	int ***xxxptr = &xxptr;
	swap(&x, &y);
	cout << "The address of x is " << &x << endl;
	cout << "The value of x is " << x << endl;
	cout << "The value of y is " << y << endl;
	cout << "The address of xptr is " << &xptr << endl;
	cout << "The value of xptr is " << xptr << endl;
	cout << "The value of *xptr is " << *xptr << endl;
	cout << "The address of y is " << yptr << endl;
	cout << "The value of x is " << *(*xxptr) << endl;
	cout << "The value of x is " << *(*(*xxxptr)) << endl;


}
