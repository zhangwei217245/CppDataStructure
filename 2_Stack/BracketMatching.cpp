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
            throw string("Stack is empty!");
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

int main(int argc, char **argv){     // This version will check for proper bracket matching in a given expression
    try{        //Due to the modified nature of this version it might not be necessary to use the try/catch method
        char *expression = argv[1];//"s=t[5]+{u/(v*(w+y)};";      // This is the given expression
        int size = 20;   // Variable stack size for versatility
        Stack stk(size);
        //stk.peek(); // if used here, it will throw an exception and terminate early
        char v;
	int level = 1;// level is a counter maintaining the depth of your embeded bracket structure.
        char errmsg[200];
        for(int i = 0; i < size; i++){
            if (expression[i] == '(' || expression [i] == '{' || expression[i] == '['){
                    stk.push(expression[i]);
		    cout << expression[i] << " "<< level << endl;
	            level++;
            }else if (expression[i] == ')' || expression[i] == '}' || expression[i] == ']'){
		    level--;
			
		    cout << expression[i] << " "<< level << endl;
		    if (!stk.isEmpty()){//defensive programming! Before any exception happens, make sure you try to avoid them.
/*
                    	v = stk.pop();
			if ( v == '('  && expression[i]!=')') {
				sprintf(errmsg, "Failed at level %d : expect %c", level, ')');
				throw string(errmsg);
			}else  if ( v == '[' && expression[i] != ']') {
				sprintf(errmsg, "Failed at level %d : expect %c", level, ']');
				throw string(errmsg);
			}else  if ( v == '{' && expression[i] != '}') {
				sprintf(errmsg, "Failed at level %d : expect %c", level, '}');
				throw string(errmsg);
			}
*/
                        if(!(v+1 == expression[i] || v+2 == expression[i])){    // this character arithmetic is just a lazy way of manipulating the ASCII table to save coding time
// Although you can do the character arithmetic, but the drawback is that you need to check the ASCII table to make sure you are doing it in the right way or the offset you choose is correct. Also, it deminishes the readability for human. Actually, doing arithmetic will cause CPU to execute an ADD operation with several instructions against the registers, while using explicit characters will avoid at least the ADD instrcution. In addition, this logic is problematic when it comes to the case where expression is "{[(]}", it will fail you since for '(', it won't detect the exact place where the pair is missing. 
			    break;
                        }
                 } else {
			sprintf(errmsg, "Failed at level %d : redundant %c", level, expression[i]);
			throw string(errmsg);
		 }// if you have nothing in the else branch, it's better to omit it!
             }
        }
        if (stk.isEmpty()){
            cout<< "Success"<<endl;
            return 0;
        }
        else{
            cout<< "Fail at level " << level <<endl;
            return 0;
        }
    }catch(string e){
        cout<<"Exception: "<< e << endl;
    }
    return 0;
}

