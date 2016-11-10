#include "AVLTree.h"
using namespace std;
void printArray(int *arr){
   for (int i =0; i<10;i++){
        cout << arr[i] << "  ";
   }
   cout << endl;
}
int main(){
   AVLTree<int> AVLTree;
   //srand(0);
   srand(time(NULL));

   int test_data[10];// declare an array to save the test data
   for (int i = 0; i < 10; i++){
        test_data[i] = (rand() % 100)+1; // generate the test data
        AVLTree.root = AVLTree.insert(AVLTree.root, test_data[i]);
   }
   printArray(test_data); // print the test data
   AVLTree.print_t(AVLTree.root); // print the tree

   for (int i = 0; i < 10; i++){
         // search each test data, make sure all of them will be found.
        cout << test_data[i] << (AVLTree.search(AVLTree.root, test_data[i])?" can":" cannot")<< " be found in the tree!" << endl;
        // search the neighbor integer of each test data, make sure all of them cannot be found.
       cout << test_data[i]-1 << (AVLTree.search(AVLTree.root, test_data[i]-1)?" can":" cannot")<< " be found in the tree!" << endl;
   }

    cout << "Preorder:" ; AVLTree.preorder(AVLTree.root);cout << endl;
    cout << "Inorder:" ; AVLTree.inorder(AVLTree.root); cout<< endl;
    cout << "Postorder:"; AVLTree.postorder(AVLTree.root);cout << endl;

    cout << "The height of the tree is : " << AVLTree.height(AVLTree.root) << endl;

   return 0;
}
