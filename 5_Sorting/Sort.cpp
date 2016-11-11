//
// Created by zhangwei217245 on 11/10/16.
//

#include "Sort.h"

using namespace std;

int main(int argc, char **argv){

    string algoName = string(argv[1]);


    if (argc <= 1) {
        cout << "You need to specify the name of the sorting algorithm!" << endl;
        return 0;
    }

    int size = 10;
    srand(time(0));

    int* arrayOfInt = new int [size];
    for(int i = 0; i < size; i++)
        arrayOfInt [i] = 1+rand()%100;

    Data<int> data(arrayOfInt, size);
    data.sort(algoName);

}