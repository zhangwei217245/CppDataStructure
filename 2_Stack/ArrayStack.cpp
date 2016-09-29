#include <string>
#include <iostream>
using namespace std;
 
class Stack {
private:
      int top;
      int capacity;
      int length;
      int *storage; // O O O O O
public:
      Stack(int capacity) {
            if (capacity <= 0)
                  throw string("Stack's capacity must be positive");
            storage = new int[capacity];
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
                  throw string("Stack is empty");
            return storage[top];
      }
 
      void pop() {
            if (top == -1)
                  throw string("Stack is empty");
	    length--;
            top--;
      }
 
      bool isEmpty() {
            return (top == -1);
      }
 
      ~Stack() {
            delete[] storage;
      }
};

int main(){
	try{
		Stack stk(5);
	
		stk.peek();
		for (int i = 0; i < 5; i++){
			stk.push(i);
		}
		for (int i = 0; i < 2; i++){
			cout<<"TOP ELEMENT="<< stk.peek() << endl;
			cout<<"SIZE=" <<  stk.size() << endl;
			stk.pop();	
		}
	}catch(string e){
		cout << "Exception: " << e << endl;
	}
	return 0;
}
