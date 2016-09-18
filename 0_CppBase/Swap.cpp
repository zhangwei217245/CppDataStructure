#include <iostream>

using namespace std;

void swap(int &x, int &y){
int temp = x;
    x = y;
    y = temp;

}
 int main(){

    int x =9;
    int y =6;
    int *xptr = &x;
    int *yptr = &y;
    swap(x,y);

    cout << " the value of x is " << x << endl;
    cout << " the value of y is " << y << endl;
    cout << " the value of xptr is " << xptr << endl;
    cout << " the value of yptr is " << yptr << endl;
    cout << " the value of *xptr is " << *xptr << endl;
    cout << " the value of *yptr is " << *yptr <<endl;

    return 0;

 }
