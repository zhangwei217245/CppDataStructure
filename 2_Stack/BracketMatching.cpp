#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

class Stack{
private:
    int top;
    int capacity;
    int length;   // length and top will always be 1 unit apart; therefore, we can take one of them out and replace them with the other and some arithmetic, for efficiency, if desired
    char *storage; // 0 0 0 0 0
public:
    Stack(int capacity) {
        if (capacity <= 0)
            throw string("Stack's capacity must be positive");
        storage = new char[capacity];
        this->capacity = capacity;
        top = -1;
        length = 0;
    }
    void clear(){
        top = -1;
        length = 0;
    }
    int size() {
        return length;
    }
    void push(int value) {
        if (top == capacity)
            throw string("Stack's underlying storage is overflow");
        top++;
        length++;
        storage[top] = value;
    }
    int peek() { // topEl
        if (top == -1)
            throw string("Stack is empty/Brackets not matched");
        return storage[top];
    }
    char pop(){
        if (top == -1)
            return '~';
        top--;
        length--;
        return storage[top+1];
    }
    bool isEmpty(){
        return (top == -1);
    }
    ~Stack(){
        delete[] storage;
    }
};

int main(){     // This version will check for proper bracket matching in a given expression
    try{        //Due to the modified nature of this version it might not be necessary to use the try/catch method
        char expression[] = "s=t[5]+u/(v*w+y));";      // This is the given expression
        int size = 20;   // Variable stack size for versatility
        Stack stk(size);
        //stk.peek(); // if used here, it will throw an exception and terminate early
        char v;
        for(int i = 0; i < size; i++){
            if (expression[i] == '(' || expression [i] == '{' || expression[i] == '['){
                    stk.push(expression[i]);
            }else{
                if (expression[i] == ')' || expression[i] == '}' || expression[i] == ']'){
                    v = stk.pop();
                    if (v == '~'){
                        cout<<"Fail"<<endl;
                        return 0;
                    }
                    else{
                        if(!(v+1 == expression[i] || v+2 == expression[i])){    // this character arithmetic is just a lazy way of manipulating the ASCII table to save coding time
                            cout<<"Fail"<<endl;
                            return 0;
                        }
                    }
                }else{
                    // do nothing here???
                }
            }
        }
        if (stk.isEmpty()){
            cout<< "Success"<<endl;
            return 0;
        }
        else{
            cout<< "Fail"<<endl;
        }
    }catch(string e){
        cout<<"Exception: "<< e << endl;
    }
    return 0;
}

