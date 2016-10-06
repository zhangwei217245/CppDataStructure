#include "genSLList.h"
using namespace std;

int main(){

    SinglyLinkedList<int> sll;
    sll.printAll();
    for (int i = 0; i < 12; i++){
        sll.addToSLLHead(i % 4);
    }
    sll.printAll();
    for (int i = 0; i < 12; i++){
        sll.addToSLLTail(i % 4);
    }
    sll.printAll();
    cout << sll.deleteAll(3) << " elements were deleted" << endl;
    sll.printAll();
    sll.deleteNode(0);
    sll.printAll();

}
