#include "genQueue.h"
#include <string>
#include <iostream>
using namespace std;
int main()
{
    try{
    Queue<int> aq;    
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
