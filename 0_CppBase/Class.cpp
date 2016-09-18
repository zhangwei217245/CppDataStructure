#include <iostream>
#include <string>
using namespace std;

// Write a class called "Cat", define 3 data members as "name", "age", "gender".
// Define a function named as "grow", which takes the parameter as the number of years that the cat needs to grow and it is to increase the Cat's age.
// In the main function, generate two object of the class "Cat", give different name to them and
// make one of the cats grow by 2 years old, and another grow by 3 years old, and print out the age
// of different cats.

class Animal {
private:
    string name;
    int age;
    char gender;

public:
    Animal(string n, int a, char g ){
        name = n;
        age = a;
        gender = g;
    }
    void grow(int a){
        age = age + a;
    }
    void print(){
        cout << gender << endl;
        cout << age << endl;
        cout << name << endl;
    }

};


int main(){
    Animal a("bird", 1 , 'f');
    Animal b("tiger", 2 , 'm');
    a.grow(2);
    b.grow(3);
    a.print();
    b.print();

    return 0;
}
