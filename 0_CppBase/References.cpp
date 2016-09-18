#include <iostream>
using namespace std;

void swap(int& x, int& y){
   int temp = x;
   x=y;
   y=temp;
}
void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;

}

int main(){
    //Define :
    //Variable:
    int a;
    //Reference:
    int &ar;
    //Pointer:
    int *aptr;

    //Retrieval
    //value of Reference or Variable
    a;
    ar;
    //Address of Variable or Reference
    &a;
    &ar;
    //value stored in the space specified by the pointer:
    *aptr;

    int x = 6;
    int y = 9;
    int *xptr = &x;
    int *yptr = &y;
    int& yr = y;
    int& xr = x;
    cout << "x=" <<x << ",y=" << y << endl;
    cout << "xr=" << xr << ",yr="<< yr << endl;
    cout << "&x=" <<&x << ",&y=" << &y << endl;
    cout << "&xr="<< &xr << ",&yr="<< &yr << endl;
    swap(xptr, yptr);
    cout << "x=" <<x << ",y=" << y << endl;
    cout << "xr=" << xr << ",yr="<< yr << endl;
    cout << "&x=" <<&x << ",&y=" << &y << endl;
    cout << "&xr="<< &xr << ",&yr="<< &yr << endl;

}
