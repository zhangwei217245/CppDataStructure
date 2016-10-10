#include "genArrayQueue.h"
#include <string>
#include <iostream>
using namespace std;
int main()
{
    try{
    ArrayQueue<int, 2> aq;    
    aq.enqueue(1);
    aq.enqueue(2);
    aq.enqueue(3);

    cout << aq.dequeue() << endl;
    cout << aq.dequeue() << endl;
    cout << aq.dequeue() << endl;
    cout << aq.dequeue() << endl;
    cout << aq.dequeue() << endl;

    }catch(string ex){
        cout << ex << endl;
    }
}
