#include <iostream>
#include "genDLList.h"

using namespace std;

template <class T>
class Stack {
private:
      int top;
      int capacity;
      int length;
      DoublyLinkedList<T>* storage = new DoublyLinkedList<T>(); // O O O O O
public:
      Stack(int capacity) {
            if (capacity <= 0)
                  throw string("Stack's capacity must be positive");
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

      void push(T value) {
            if (top == capacity)
                  throw string("Stack's underlying storage is overflow");
            top++;
	    length++;
            storage->addToDLLHead(value);
      }

      T& peek() { // topEl
            if (top == -1)
                  throw string("Stack is empty");
            return storage->firstEl();
      }

      void pop() {
            if (top == -1)
                  throw string("Stack is empty");
	    length--;
            top--;
	    this->storage->deleteFromDLLHead();
      }

      bool isEmpty() {
            return (top == -1 || this->storage->isEmpty());
      }

      ~Stack() {
            delete storage;
      }
};


int main(){
	try{
		Stack<int> stk(5);

		//stk.peek();
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
