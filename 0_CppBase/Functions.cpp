#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int RandMultipByVal(int *v){
	srand(time(0));
	cout << v << endl;
	for (int i = 0; i < 10 ; i++) {
		//cout << rand()<< endl;
	}
	*v = 22;
	int r = 1+rand()%10;
	cout << r << endl;
	return (*v) * r;
}

int printByVal(int *value){
	cout << *value << endl;
}
int main(){
	int Num = 45;
	cout << &Num << endl;
	int result = RandMultipByVal(&Num);
 	printByVal(&result);
	cout << Num << endl;
	return 0;
}
