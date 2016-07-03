#ifndef MENU_PROGRAM_H
#define MENU_PROGRAM_H

#include <cassert>
#include <iostream>
#include <string>

#include "MaxHeapTree.h"
#include "AVLTree.h"
#include "GenLinkedTreeClass.h"
#include "Menu_Program.h"
#include "PrintingPress.h"


class Menu_Program
{

public:

	Menu_Program() ;

private:

	void Clear() ;
	void Greeting() ;
	void Main_Loop() ;

	void Heap_Tree_Create() ;
	void Heap_Tree_Loop(int stellaris) ;

	void AVL_Tree_Create();
	void AVL_Tree_Loop();
} ;

#endif