// Project 03 - Trees , Trees , and Trees (A Tale of Two Forests)
// by:  Manuel Martinez , John Santoro , and Jim Bui

#include "Menu_Program.h"

int main()
{
	/*GenLinkedTreeClass<string>* genTree = new GenLinkedTreeClass<string>();

	genTree->levelorder();
	cout << endl;*/

	// int duh = 666;

	 Menu_Program() ;

	/*while (true)
	{
		cout << "Find common ancestor by key --> " << endl;

		int key1;
		int key2;

		cout << "Enter search key 1:  ";
		cin >> key1;
		cin.ignore();
		cout << "Enter search key 2:  ";
		cin >> key2;
		cin.ignore();
		cout << endl;

		try
		{
			cout << "Common Ancestor --> ";
			GenTreeNode<string>* commonAncestor = genTree->findCommonAncestor(genTree->findNode(key1), genTree->findNode(key2));

			if (commonAncestor != nullptr)
				commonAncestor->Visit();
			else
				cout << "God";
		}
		catch (const underflow_error& e)
		{
			cerr << e.what() << endl;
		}

		cout << endl;
	}*/

	cin.get();
	return 1748 ;
}
