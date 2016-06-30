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
	std::cout << std::endl << "Project 02 Program - Stack , Queue , and Hash Table" << std::endl ;
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
		}

		else if (input == 2)
		{
			Clear() ;
			Heap_Tree_Create() ;
		}

		else if (input == 3)
		{
			Clear() ;
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
			std::cout << std::endl << "Invalid input." << std::endl << std::endl ;
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
		std::cout << "    10. Go back." << std::endl << std::endl ;

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

				if (key_in < 0) std::cout << "  Key must be greater than 0. \n\n" ;
				else break ;
			}

			std::cout << "\n  Please input the string." << std::endl << std::endl << "  " ;
			std::cin >> data_in ; std::cin.clear() ; std::cin.ignore() ;

			why_is_the_rum_gone.insert(key_in , data_in) ;

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
			break ;
		}

		else if (input == 11)
		{
			Clear() ;
			why_is_the_rum_gone.display() ;
		}

		else
		{
			Clear() ;
			std::cout << std::endl << "  Invalid input." << std::endl << std::endl ;
		}
	}
}
