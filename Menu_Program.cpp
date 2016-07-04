#include <cassert>
#include <iostream>
#include <string>

#include "Menu_Program.h"

// main functions.

Menu_Program::Menu_Program()
{
	Clear() ;
	Greeting() ;
	Main_Loop() ;
}

void Menu_Program::Clear()
{
	for(int i = 0 ; i < 100 ; i++)
		std::cout << std::endl ;
}

void Menu_Program::Greeting()
{
	std::cout << std::endl << "Project 03 Program - Trees , Trees , and more Trees" << std::endl ;
	std::cout << std::endl << "    by:  Manuel Martinez , John Santoro , and Jim Bui" << std::endl << std::endl ;
}

void Menu_Program::Main_Loop()
{
	int input = 0 ;

	while (true)
	{
		std::cout << "  Main Menu" << std::endl << std::endl ;
		std::cout << "    1.  General Tree Menu" << std::endl ;
		std::cout << "    2.  Heap Tree Menu" << std::endl ;
		std::cout << "    3.  AVL Tree Menu" << std::endl ;
		std::cout << "    4.  Exit" << std::endl <<std::endl ;

		std::cout << "  " ;
		std::cin >> input ; std::cin.clear() ; std::cin.ignore() ;

		if (input == 1)
		{
			Clear() ;
			General_Tree_Create() ;		
		}

		else if (input == 2)
		{
			Clear() ;
			Heap_Tree_Create() ;
		}

		else if (input == 3)
		{
			Clear() ;
			AVL_Tree_Create();
		}

		else if (input == 4)
		{
			std::cout << std::endl << "  Exiting program..." << std::endl << std::endl ;
			break ;
		}

		else
		{
			Clear() ;
			std::cout << std::endl << "  Invalid input." << std::endl << std::endl ;
		}
	}
}

void Menu_Program::Heap_Tree_Create()
{
	int input = 0 ;

	while (true)
	{
		std::cout << "  Heap Tree Menu" << std::endl << std::endl ;
		std::cout << "    1.  Create a heap tree." << std::endl ;
		std::cout << "    2.  Go back." << std::endl <<std::endl ;

		std::cout << "  " ;
		std::cin >> input ; std::cin.clear() ; std::cin.ignore() ;

		if (input == 1)
		{
			int n = 0 ;

			Clear() ; 
			std::cout << "  Please input size of the heap tree to be created." << std::endl << std::endl ;
			std::cout << "  " ;
			std::cin >> n ; std::cin.clear() ; std::cin.ignore() ;
			Clear() ;
			std::cout << "  Created a heap tree of size " << n << "." << std::endl << std::endl ;
			Heap_Tree_Loop(n) ;
			Clear() ;	
			break ;
		}

		else if (input == 2)
		{	
			Clear() ;	
			break ;
		}

		else
		{
			Clear() ;
			std::cout << std::endl << "  Invalid input." << std::endl << std::endl ;
		}
	}
}

void Menu_Program::Heap_Tree_Loop(int stellaris) 
{
	int input = 0 ;
	MaxHeapTree<std::string> why_is_the_rum_gone(stellaris) ;

	while (true)
	{
		std::cout << "  Heap Tree Menu" << std::endl << std::endl ;
		std::cout << "    1.  Return root of tree." << std::endl ;
		std::cout << "    2.  Return number of elements in the tree." << std::endl ;
		std::cout << "    3.  Returns the height of the tree." << std::endl ;
		std::cout << "    4.  Check if the tree is empty." << std::endl ;
		std::cout << "    5.  Return the number of leaves in the tree." << std::endl ;
		std::cout << "    6.  Build tree from text file." << std::endl ;
		std::cout << "    7.  Clear the tree and reset to initial size." << std::endl ;
		std::cout << "    8.  Insert item into tree." << std::endl ;
		std::cout << "    9.  Pop max key." << std::endl ;
		std::cout << "    10. Display the tree." << std::endl ;
		std::cout << "    11. Display the whole entire array all the way from the start to the very bitter end." << std::endl ;
		std::cout << "    12. Go back." << std::endl << std::endl ;

		std::cout << "  " ;
		std::cin >> input ; std::cin.clear() ; std::cin.ignore() ;

		if (input == 1)
		{
			Clear() ;

			if (why_is_the_rum_gone.empty()) std::cout << "  The tree is empty. \n\n" ;
			else std::cout << "  The root of the tree is: " << why_is_the_rum_gone.getMax() << " \n\n" ;
		}

		else if (input == 2)
		{
			Clear() ;

			if (why_is_the_rum_gone.empty()) std::cout << "  The tree is empty. \n\n" ;
			else std::cout << "  The tree has " << why_is_the_rum_gone.getSize() << " elements. \n\n" ;
		}

		else if (input == 3)
		{
			Clear() ;

			std::cout << "  The height of the tree is " << why_is_the_rum_gone.getHeight() << ". \n\n" ;
		}

		else if (input == 4)
		{
			Clear() ;

			if (why_is_the_rum_gone.empty()) std::cout << "  The tree is empty and has no elements. \n\n" ;
			else std::cout << "  The tree is not empty and has elements. \n\n" ;
		}

		else if (input == 5)
		{
			Clear() ;

			if (why_is_the_rum_gone.empty()) std::cout << "  The tree is empty. \n\n" ;
			else std::cout << "  The tree has " << why_is_the_rum_gone.leaves() << " leaves. \n\n" ;
		}

		else if (input == 6)
		{
			Clear() ;

			why_is_the_rum_gone.buildTreehouse("MaxHeapTreeText.txt") ;
		}

		else if (input == 7)
		{
			Clear() ;

			why_is_the_rum_gone.clear() ;
		}

		else if (input == 8)
		{
			Clear() ;

			int key_in ;
			std::string data_in ;

			while (true)
			{
				std::cout << "  Please input the key of the element." << std::endl << std::endl << "  " ;
				std::cin >> key_in ; std::cin.clear() ; std::cin.ignore() ;

				if (key_in <= 0) 
				{
					Clear() ;
					std::cout << "  Key must be greater than 0. \n\n" ;
				}

				else break ;
			}

			std::cout << "\n  Please input the string." << std::endl << std::endl << "  " ;
			std::cin >> data_in ; std::cin.clear() ; std::cin.ignore() ;

			why_is_the_rum_gone.insert(key_in , data_in) ;

			Clear() ;
			std::cout << "\n  Element has been inserted. \n\n" ;
		}

		else if (input == 9)
		{
			Clear() ;

			if (why_is_the_rum_gone.empty()) std::cout << "  The tree is empty. \n\n" ;

			else
			{
				why_is_the_rum_gone.delMax() ;
				std::cout << "  Max key has been popped. \n\n" ;
			}
		}

		else if (input == 10)
		{
			Clear() ;
			why_is_the_rum_gone.display_tree() ;
		}


		else if (input == 11)
		{
			Clear() ;
			why_is_the_rum_gone.display() ;
		}

		else if (input == 12)
		{
			Clear() ;
			break ;
		}

		else
		{
			Clear() ;
			std::cout << std::endl << "  Invalid input." << std::endl << std::endl ;
		}
	}
}

void Menu_Program::AVL_Tree_Create()
{
	int input = 0;

	while (true)
	{
		std::cout << "  AVL Tree Menu" << std::endl << std::endl;
		std::cout << "    1.  Create an AVL tree." << std::endl;
		std::cout << "    2.  Go back." << std::endl << std::endl;

		std::cout << "  ";
		std::cin >> input; std::cin.clear(); std::cin.ignore();

		if (input == 1)
		{
			Clear();
			std::cout << "  Created an AVL tree." << std::endl << std::endl;
			AVL_Tree_Loop();
			Clear();
			break;
		}

		else if (input == 2)
		{
			Clear();
			break;
		}

		else
		{
			Clear();
			std::cout << std::endl << "  Invalid input." << std::endl << std::endl;
		}
	}
}

void Menu_Program::AVL_Tree_Loop()
{
	int input = 0;
	AVLTree<string> avlTree;

	while (true)
	{
		std::cout << "  AVL Tree Menu" << std::endl << std::endl;
		std::cout << "    1.  Return root of tree." << std::endl;
		std::cout << "    2.  Return number of elements in the tree." << std::endl;
		std::cout << "    3.  Returns the height of the tree." << std::endl;
		std::cout << "    4.  Check if the tree is empty." << std::endl;
		std::cout << "    5.  Return the number of leaves in the tree." << std::endl;
		std::cout << "    6.  Finds a specific node with the key the user enters." << std::endl;
		std::cout << "    7.  Preorder traversal." << std::endl;
		std::cout << "    8.  Postorder traversal." << std::endl;
		std::cout << "    9.  Levelorder traversal." << std::endl;
		std::cout << "    10. Inorder traversal." << std::endl;
		std::cout << "    11. Build tree from text file." << std::endl;
		std::cout << "    12. Clear tree." << std::endl;
		std::cout << "    13. Insert an item into the tree." << std::endl;
		std::cout << "    14. Remove an item from the tree." << std::endl;
		std::cout << "    15. Go back." << std::endl << std::endl;

		std::cout << "  ";
		std::cin >> input; std::cin.clear(); std::cin.ignore();

		if (input == 1)
		{
			Clear();

			AVLTreeNode<string>* root = avlTree.getRoot();

			if (root == nullptr)
				cout << "The root is null.";
			else
			{
				root->Visit();
				// std::cout << root->getData() << " \n\n" ;
			}
		}
		else if (input == 2)
		{
			Clear();

			cout << "Tree Size:  " << avlTree.getSize() << " elements";
		}
		else if (input == 3)
		{
			Clear();
			int numOps = 0;  // Used for runtime checking

			cout << "Height:  " << avlTree.getHeight(numOps);
		}
		else if (input == 4)
		{
			Clear();

			cout << (avlTree.empty() ? "This tree is empty." : "This tree is not empty.");
		}
		else if (input == 5)
		{
			Clear();

			cout << "Number of leaves:  " << avlTree.leaves();
		}
		else if (input == 6)
		{
			Clear();

			int key;

			cout << "Enter key to search:  ";
			cin >> key;
			cin.ignore();

			try
			{
				avlTree.find(key)->Visit();
			}
			catch (const underflow_error& e)
			{
				cerr << e.what() << endl;
			}
		}
		else if (input == 7)
		{
			Clear();

			if (avlTree.empty())
				cout << "There is nothing to display because the tree is empty." << endl;
			else
				avlTree.preorder();
		}
		else if (input == 8)
		{
			Clear();

			if (avlTree.empty())
				cout << "There is nothing to display because the tree is empty." << endl;
			else
				avlTree.postorder();
		}
		else if (input == 9)
		{
			Clear();

			if (avlTree.empty())
				cout << "There is nothing to display because the tree is empty." << endl;
			else
				avlTree.levelorder();
		}
		else if (input == 10)
		{
			Clear();

			if (avlTree.empty())
				cout << "There is nothing to display because the tree is empty." << endl;
			else
				avlTree.inorder();
		}
		else if (input == 11)
		{
			Clear();

			/*cout << "Enter file name + extension:  ";
			string fileName;

			cin >> fileName;
			cin.ignore();*/

			avlTree.buildTree(/*fileName*/"AVLtree.txt");
			cout << "Tree built." << endl;
		}
		else if (input == 12)
		{
			Clear();

			avlTree.clear();

			cout << "AVL tree cleared.";
		}
		else if (input == 13)
		{
			Clear();

			string data;
			int key;

			cout << "Enter new data:  ";
			cin >> data;
			cin.ignore();
			cout << "Enter key:  ";
			cin >> key;
			cin.ignore();

			int numOps = 0;

			avlTree.insert(key, data, numOps);  // Runtime checking
		}
		else if (input == 14)
		{
			Clear();

			int key;

			cout << "Enter key of data to delete:  ";
			cin >> key;
			cin.ignore();

			int numOps = 0;

			avlTree.del(key, numOps);  // Runtime checking
		}
		/*else if (input == 15)
		{
			Clear();

			PrintingPress<string>::SmartPrint(&avlTree, 300);
		}*/
		else if (input == 15)
		{
			Clear();
			break;
		}
		else
		{
			Clear();
			std::cout << std::endl << "  Invalid input." << std::endl << std::endl;
		}

		cout << endl;
	}
}

void Menu_Program::General_Tree_Create()
{
	int input = 0 ;

	while (true)
	{
		std::cout << "  General Tree Menu" << std::endl << std::endl ;
		std::cout << "    1.  Create a general tree." << std::endl ;
		std::cout << "    2.  Go back." << std::endl <<std::endl ;

		std::cout << "  " ;
		std::cin >> input ; std::cin.clear() ; std::cin.ignore() ;

		if (input == 1)
		{
			Clear() ; 

			// do something here.

			General_Tree_Loop() ;

			break ;
		}

		else if (input == 2)
		{	
			Clear() ;	
			break ;
		}

		else
		{
			Clear() ;
			std::cout << std::endl << "  Invalid input." << std::endl << std::endl ;
		}
	}
}

void Menu_Program::General_Tree_Loop() 
{
	int input = 0;
	GenLinkedTreeClass<string> admiral_Tree;
	std::cout << "  General tree created from text file." << std::endl << std::endl;

	while (true)
	{
		std::cout << "  General Tree Menu" << std::endl << std::endl;
		std::cout << "    1.  Return root of tree." << std::endl;
		std::cout << "    2.  Return number of elements in the tree." << std::endl;
		std::cout << "    3.  Returns the height of the tree." << std::endl;
		std::cout << "    4.  Return the height of a specific node." << std::endl;
		std::cout << "    5.  Return the depth of a specific node." << std::endl;
		std::cout << "    6.  Check if the tree is empty." << std::endl;
		std::cout << "    7.  Return the number of leaves in the tree." << std::endl;
		std::cout << "    8.  Return the number of siblings a specific node has." << std::endl;
		std::cout << "    9.  Find the common ancestor of two nodes." << std::endl;
		std::cout << "    10. Search for node by data." << std::endl;
		std::cout << "    11. Preorder traversal." << std::endl;
		std::cout << "    12. Postorder traversal." << std::endl;
		std::cout << "    13. Levelorder traversal." << std::endl;
		std::cout << "    14. Build tree from a text file." << std::endl ;
		std::cout << "    15. Clear the tree." << std::endl ;
		std::cout << "    16. Insert data into tree." << std::endl ;
		std::cout << "    17. Delete data from tree." << std::endl ;
		std::cout << "    18. Go back." << std::endl << std::endl ;

		std::cout << "  ";
		std::cin >> input; std::cin.clear(); std::cin.ignore();

		if (input == 1)
		{
			if (admiral_Tree.empty()) std::cout << "  The tree is empty. \n\n" ;
			else {std::cout << "  The root of the tree is: " << endl;
			admiral_Tree.getRoot()->Visit();
			}
		}

		else if (input == 2)
		{
			if (admiral_Tree.empty()) std::cout << "  The tree is empty. \n\n" ;
			else std::cout << "   The size of the tree is: " << admiral_Tree.getSize();
		}

		else if (input == 3)
		{
			if (admiral_Tree.empty()) std::cout << "  The tree is empty. \n\n" ;
			else std::cout << "    The height of the tree is: " << admiral_Tree.getHeight();
		}

		else if (input == 4)
		{
			if (admiral_Tree.empty()) std::cout << "  The tree is empty. \n\n" ;
			else std::cout << "  The height of the root node: " << admiral_Tree.getHeight(admiral_Tree.getRoot());  
		}

		else if (input == 5)
		{
			if (admiral_Tree.empty()) std::cout << "  The tree is empty. \n\n" ;
			else std::cout << "  The depth of the root node: " << admiral_Tree.getDepth(admiral_Tree.getRoot());  
		}

		else if (input == 6)
		{
			if (admiral_Tree.empty()) std::cout << "  The tree is empty. \n\n" ;
			else std::cout << "   The tree is not empty.  " << endl;
		}

		else if (input == 7)
		{
			if (admiral_Tree.empty()) std::cout << "  The tree is empty. \n\n" ;
			else std::cout << "   The number of leaves on tree are:  " << admiral_Tree.leaves();
		}

		else if (input == 8)
		{
			if (admiral_Tree.empty()) std::cout << "  The tree is empty. \n\n" ;
			else std::cout << "   The number of siblings of the root are:  " << admiral_Tree.siblings(admiral_Tree.getRoot());
		}

		else if (input == 9)
		{
			if (admiral_Tree.empty()) std::cout << "  The tree is empty. \n\n" ;
			else std::cout << "    This function requires two nodes.  "  << endl;
		}

		else if (input == 10)
		{
			int key;
			if (admiral_Tree.empty()) std::cout << "  The tree is empty. \n\n" ;
			else {std::cout << "   Enter a data to search:  " << endl;
			std::cin >> key;
			admiral_Tree.findNode(key)->Visit();
			}
		}

		else if (input == 11)
		{
			if (admiral_Tree.empty()) std::cout << "  The tree is empty. \n\n" ;
			else {std::cout << "   Preorder traversal: " << endl;
			admiral_Tree.preorder();
			}
		}

		else if (input == 12)
		{
			if (admiral_Tree.empty()) std::cout << "  The tree is empty. \n\n" ;
			else {std::cout << "   Postorder traversal: " << endl;
			admiral_Tree.postorder();
			}
		}

		else if (input == 13)
		{
			if (admiral_Tree.empty()) std::cout << "  The tree is empty. \n\n" ;
			else {std::cout << "   Levelorder traversal: " << endl;
			admiral_Tree.levelorder();
			}
		}

		else if (input == 14)
		{
			if (admiral_Tree.empty()) std::cout << "  The tree is empty. \n\n" ;
			else std::cout << "   Tree was builded." << endl;
		}

		else if (input == 15)
		{
			if (admiral_Tree.empty()) std::cout << "  The tree is empty. \n\n" ;
			else admiral_Tree.clear();
		}

		else if (input == 16)
		{
			if (admiral_Tree.empty()) std::cout << "  The tree is empty. \n\n" ;
			else std::cout << "   Tree is created from the tree.txt file  " << endl;
		}

		else if (input == 17)
		{
			int key;
			if (admiral_Tree.empty()) std::cout << "  The tree is empty. \n\n" ;
			else {std::cout << "   Enter a key to delete: " << endl;
			std::cin >> key;
			admiral_Tree.del(key);
			cout << "  Element at key " << key << " was deleted.";
			}
		}

		else if (input == 18)
		{
			Clear();
			break;
		}

		else
		{
			Clear();
			std::cout << std::endl << "  Invalid input." << std::endl << std::endl;
		}

		cout << endl;
	}
}
