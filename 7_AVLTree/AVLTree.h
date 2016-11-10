#include <iostream>
#include <cstddef>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

template<class T>
class TreeNode {
public:
    TreeNode() {
        left = right = NULL;
    }

    TreeNode(const T &e, TreeNode<T> *l = NULL, TreeNode<T> *r = NULL) {
        el = e;
        left = l;
        right = r;
    }

    T el;
    TreeNode<T> *left, *right;

};

template <class T>
class AVLTree {
public:
    AVLTree() {
        root = NULL;
    }

    ~AVLTree() {
        //Preorder traversal to delete every node.
        //But the preorder traversal function needs to be implemented first.
    }

    int height(TreeNode<T> *subroot);

    int diff(TreeNode<T> *subroot);

    TreeNode<T>* rr_rotation(TreeNode<T> *subroot);

    TreeNode<T>* ll_rotation(TreeNode<T> *subroot);

    TreeNode<T>* lr_rotation(TreeNode<T> *subroot);

    TreeNode<T>* rl_rotation(TreeNode<T> *subroot);

    TreeNode<T>* balance(TreeNode<T> *subroot);

    bool search(TreeNode<T> *node, const T &e);

    void preorder(TreeNode<T> *tree);

    void inorder(TreeNode<T> *tree);

    void postorder(TreeNode<T> *tree);

    TreeNode<T>* insert(TreeNode<T> *subTreeRoot, const T &e);

    void print_t(TreeNode<T> *tree);

    TreeNode<T> *root;
private:
    int _print_t(TreeNode<T> *tree, int is_left, int offset, int depth, char s[20][255]);
};

template <class T>
TreeNode<T> *AVLTree<T>::ll_rotation(TreeNode<T> *subroot) {
    TreeNode<T> *temp = NULL;

    return temp;
}
template <class T>
TreeNode<T> *AVLTree<T>::rr_rotation(TreeNode<T> *subroot) {
    TreeNode<T> *temp = NULL;

    return temp;
}
template <class T>
TreeNode<T> *AVLTree<T>::lr_rotation(TreeNode<T> *subroot) {


    return NULL;
}
template <class T>
TreeNode<T> *AVLTree<T>::rl_rotation(TreeNode<T> *subroot) {

    return NULL;
}

template <class T>
TreeNode<T>* AVLTree<T>::balance(TreeNode<T> *subroot) {
    TreeNode<T> *temp = subroot;
    int bl_factor = diff(temp);
    if (bl_factor > 1)
    {
        if (diff (temp->left) > 0)
            temp = ll_rotation (temp);
        else
            temp = lr_rotation (temp);
    }
    else if (bl_factor < -1)
    {
        if (diff (temp->right) > 0)
            temp = rl_rotation (temp);
        else
            temp = rr_rotation (temp);
    }
    return temp;
}

template <class T>
int AVLTree<T>::diff(TreeNode<T> *subroot) {
    return height(subroot->left) - height(subroot -> right);
}


template <class T>
int AVLTree<T>::height(TreeNode<T> *subroot) {
    return 0;
}

template<class T>
TreeNode<T>* AVLTree<T>::insert(TreeNode<T> *subTreeRoot, const T &e) {

    if (subTreeRoot == NULL) {
        subTreeRoot = new TreeNode<T>(e);
    } else {

        if (subTreeRoot->el > e) {
            subTreeRoot->left = insert(subTreeRoot->left, e);
        } else {
            subTreeRoot->right = insert(subTreeRoot->right, e);
        }
//        cout << "================ Before Balancing ================" << endl;
//        print_t(this->root);
        subTreeRoot = balance(subTreeRoot);
//        cout << "================= After Balancing ================" << endl;
//        print_t(this->root);
    }
    return subTreeRoot;
}

template<class T>
bool AVLTree<T>::search(TreeNode<T> *node, const T &e) {
    bool found = false;
    if (node == NULL) return found;
    if (node->el == e) {
        found = true;
    } else {
        found = (search(node->right, e) || search(node->left, e));
    }
    return found;
}

template<class T>
void AVLTree<T>::preorder(TreeNode<T> *tree) {
    if (tree == NULL) {
        return;
    }
    cout << tree->el << " ";
    preorder(tree->left);
    preorder(tree->right);
}

template<class T>
void AVLTree<T>::inorder(TreeNode<T> *tree) {
    if (tree == NULL) {
        return;
    }
    inorder(tree->left);
    cout << tree->el << " ";
    inorder(tree->right);
}

template<class T>
void AVLTree<T>::postorder(TreeNode<T> *tree) {
    if (tree == NULL) {
        return;
    }
    postorder(tree->left);
    postorder(tree->right);
    cout << tree->el << " ";
}


template<class T>
int AVLTree<T>::_print_t(TreeNode<T> *tree, int is_left, int offset, int depth, char s[20][255]) {
    char b[20];
    int width = 5;

    if (tree == NULL) return 0;

    sprintf(b, "(%03d)", tree->el);

    int left = _print_t(tree->left, 1, offset, depth + 1, s);
    int right = _print_t(tree->right, 0, offset + left + width, depth + 1, s);

    for (int i = 0; i < width; i++)
        s[2 * depth][offset + left + i] = b[i];

    if (depth && is_left) {

        for (int i = 0; i < width + right; i++)
            s[2 * depth - 1][offset + left + width / 2 + i] = '-';

        s[2 * depth - 1][offset + left + width / 2] = '+';
        s[2 * depth - 1][offset + left + width + right + width / 2] = '+';

    } else if (depth && !is_left) {

        for (int i = 0; i < left + width; i++)
            s[2 * depth - 1][offset - width / 2 + i] = '-';

        s[2 * depth - 1][offset + left + width / 2] = '+';
        s[2 * depth - 1][offset - width / 2 - 1] = '+';
    }
    return left + width + right;
}

template<class T>
void AVLTree<T>::print_t(TreeNode<T> *tree) {
    char s[20][255];
    for (int i = 0; i < 20; i++)
        sprintf(s[i], "%80s", " ");

    _print_t(tree, 0, 0, 0, s);

    for (int i = 0; i < 20; i++)
        printf("%s\n", s[i]);
}
