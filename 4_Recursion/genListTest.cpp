#include "genDLList.h"
using namespace std;

void printArray(int *arr){
   cout << "array is : ";
   for (int i =0; i<10;i++){
        cout << arr[i] << "  ";
   }
   cout << endl;
}

int main(){

    srand(time(NULL));

    int test_data[10];// declare an array to save the test data
    for (int i = 0; i < 10; i++){
        test_data[i] = (rand() % 100)+1; // generate the test data
    }
    printArray(test_data); // print the test data

    DoublyLinkedList<int> dll;
    dll.printAll();
    for (int i = 0; i < 10; i++){
        dll.addToDLLHead(test_data[i]);
    }
    dll.printAll();
    dll.clear();
    for (int i = 0; i < 10; i++){
        dll.addToDLLTail(test_data[i]);
    }
    dll.printAll();
    cout << "Search : " << dll.recursiveSearch(dll.getHead(), dll.getTail(), test_data[5]) -> info << endl;

    dll.clear();
    for (int i = 0; i < 10; i++){
        dll.addNode(test_data[i]);
    }
    dll.printAll();

}
