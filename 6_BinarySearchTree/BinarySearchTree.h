#include <iostream>
#include <cstddef>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <vector>
#include <stdio.h>

using namespace std;
template <class T>
class BSTNode 
{
    public:
        BSTNode()
        {
            left = right = NULL;
        }

        BSTNode(const T& e, BSTNode<T> *l = NULL, BSTNode<T> *r = NULL)
        {
            el = e; left = l; right = r;
        }
        T el;
        BSTNode<T> *left, *right;

};

template <class T>
class BST{
    public:
        BST()
        {
            root = NULL;
        }
        ~BST()
        {
            //Preorder traversal to delete every node.
            //But the preorder traversal function needs to be implemented first.
        }
		bool search(BSTNode<T> *node, const T& e);
        void preorder(BSTNode<T> *tree);
        void inorder(BSTNode<T> *tree);
        void postorder(BSTNode<T> *tree);
        BSTNode<T>* insert(BSTNode<T> *subTreeRoot, const T& e);
		void print_t(BSTNode<T> *tree);
        BSTNode<T> *root;
    private:
        int _print_t(BSTNode<T> *tree, int is_left, int offset, int depth, char s[20][255]);
};

template<class T>
int BST<T>::_print_t(BSTNode<T> *tree, int is_left, int offset, int depth, char s[20][255]){
	char b[20];
    int width = 5;

    if (tree == NULL) return 0;

    sprintf(b, "(%03d)", tree->el);

    int left  = _print_t(tree->left,  1, offset,                depth + 1, s);
    int right = _print_t(tree->right, 0, offset + left + width, depth + 1, s);

	for (int i = 0; i < width; i++)
        s[2 * depth][offset + left + i] = b[i];

    if (depth && is_left) {

        for (int i = 0; i < width + right; i++)
            s[2 * depth - 1][offset + left + width/2 + i] = '-';

        s[2 * depth - 1][offset + left + width/2] = '+';
        s[2 * depth - 1][offset + left + width + right + width/2] = '+';

    } else if (depth && !is_left) {

        for (int i = 0; i < left + width; i++)
            s[2 * depth - 1][offset - width/2 + i] = '-';

        s[2 * depth - 1][offset + left + width/2] = '+';
        s[2 * depth - 1][offset - width/2 - 1] = '+';
    }
	return left + width + right;
}
template<class T>
void BST<T>::print_t(BSTNode<T> *tree)
{
    char s[20][255];
    for (int i = 0; i < 20; i++)
        sprintf(s[i], "%80s", " ");

    _print_t(tree, 0, 0, 0, s);

    for (int i = 0; i < 20; i++)
        printf("%s\n", s[i]);
}

template <class T>
BSTNode<T> * BST<T>::insert(BSTNode<T> *subTreeRoot, const T& e)
{

    if (subTreeRoot == NULL){
        subTreeRoot = new BSTNode<T>(e);
    }else {

        if (subTreeRoot -> el > e) {
            subTreeRoot -> left = insert(subTreeRoot->left , e);
        } else {
            subTreeRoot -> right  = insert(subTreeRoot -> right, e);
        }
    }
    return subTreeRoot;
}
template<class T>
bool BST<T>::search(BSTNode<T> *node, const T& e){
	bool found = false;
	if (node == NULL) return found;
	if (node -> el == e){
		found = true;
	} else {
		found = (search(node->right,e) || search(node->left, e));
	}
    return found;
}
template <class T>
void BST<T>::preorder(BSTNode<T> *tree){
	if(tree == NULL){
		return;
	}
	cout << tree->el << " ";
	preorder(tree -> left);
	preorder(tree->right);
}
template <class T>
void BST<T>::inorder(BSTNode<T> *tree){
	if(tree == NULL){
		return;
	}
	inorder(tree -> left);
	cout << tree->el << " ";
	inorder(tree->right);
}
template <class T>
void BST<T>::postorder(BSTNode<T> *tree){
	if(tree == NULL){
		return;
	}
	postorder(tree -> left);
	postorder(tree->right);
	cout << tree->el << " ";
}
//http://stackoverflow.com/questions/13484943/print-a-binary-tree-in-a-pretty-way
//http://stackoverflow.com/questions/801740/c-how-to-draw-a-binary-tree-to-the-console
