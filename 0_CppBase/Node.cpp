#include <iostream>
using namespace std;

class Node{
public:
	void set(int d, Node *ndPt) {
		this -> D = d;
		this -> NodePtr = ndPt;
	}
	void print(Node* ndPt){
		cout << ndPt -> getD() << endl;
		cout << ndPt -> getNodePtr() << endl;
	}
	int getD(){
		return this -> D;
	}
	Node* getNodePtr(){
		return this -> NodePtr;
	}
private:
	int D;
	Node *NodePtr;
};
int main(){
	Node N1, N2;
	N1.set(2, &N2);
	N2.set(4, &N1);
	
	N1.print(&N1);
	N2.print(&N2);

}
