#include <iostream>
using namespace std;

class A{
public:
	virtual void print(){};
};
class B: public A{
public:
	void print(){
		cout << 'b'<< endl;
	}
};
class C: public A{
public:
	void print(){
		cout << 'c' << endl;
	}
};
int main(){
	B b;
	C c;
	A** base = new A*[2];
	base[0] = &b;
	base[1] = &c;
	for (int i = 0 ; i < 2; i++){
		(base[i]) -> print();
	}

}
