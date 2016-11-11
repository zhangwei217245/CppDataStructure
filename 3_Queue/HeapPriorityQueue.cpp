//
// Created by zhangwei217245 on 11/10/16.
//

#include "HeapPriorityQueue.h"

int main(int argc, char **argv){

    srand(time(0));
    int size = 10;
    HeapPriorityQueue<int> queue(size);


    for(int i = 0; i < size+3; i++){
        int num = 1+rand()%100;
        try {
            queue.push(num);
            cout << num << " ";
        } catch (string e){
            cout << endl;
            cout << e << "  and " << num << " cannot be pushed into the queue!" << endl;
        }
    }
    cout << endl;



    for(int i = 0; i < size + 3; i++){
        try {
            cout << queue.pop() << " ";
        } catch (string e){
            cout << endl;
            cout << e << endl;
        }
    }

    cout << endl;

}