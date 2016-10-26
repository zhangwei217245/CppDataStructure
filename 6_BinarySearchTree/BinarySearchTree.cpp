#include "BinarySearchTree.h"
using namespace std;

int main(){
   BST<int> bst;
   srand(0);
   //srand(time(NULL));

   bst.placeholder=100;   
   int test_data[10];
   for (int i = 1; i <= 10; i++){
        test_data[i] = (rand() % 100)+1;
        bst.root = bst.insert(bst.root, test_data[i]);
   }
   bst.print_t(bst.root);

   for (int i = 1; i <= 10; i++){
        cout << test_data[i] << (bst.search(bst.root, test_data[i])?" can":" cannot")<< " be found in the tree!" << endl;
        cout << test_data[i]-1 << (bst.search(bst.root, test_data[i]-1)?" can":" cannot")<< " be found in the tree!" << endl;
   }
   return 0;
}
