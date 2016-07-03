#include "GenLinkedTreeClass.h"
#include <iostream>
using namespace std;

int main () {

	GenLinkedTreeClass<string> Tree;
	
	
	cout << endl << endl << endl;
	cout << "Size of tree is: " << Tree.getSize() << endl;
	
	cout << "Height of tree is: " << Tree.getHeight() << endl;

	cout << "The height of Root is: " << Tree.getHeight(Tree.getRoot()) << endl;
	
	cout << "The depth of Root is: " << Tree.getDepth(Tree.getRoot()) << endl;

	cout << "Number of leaves on tree: " << Tree.leaves() << endl;

	cout << "Number of Sibling for the root: " << Tree.siblings(Tree.getRoot()) << endl;

	int key = 14;
	GenTreeNode<string> *foundNode = Tree.findNode(key);
	
	
	cout << endl;



	Tree.preorder();
	cout << endl;
	Tree.postorder();
	cout << endl;
	Tree.levelorder();

	//Tree.clear();

	cin.get();
	return 0;
}