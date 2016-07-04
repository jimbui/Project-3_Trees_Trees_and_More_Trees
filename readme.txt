Project 03 - Trees , Trees , Trees , and More Trees.
Programeers:  Manuel Martinez, John Santoro, and Jim Bui

The driver program, main.cpp, utilizes a menu program class(Menu_Program.h and Menu_Program.cpp) in order to display information about the general tree, heap tree, and AVL tree.  The command processor requires the user to enter a numeric input in order to progress to the next menu or perform a certain function.  For example, 

  Main Menu

    1.  General Tree Menu
    2.  Heap Tree Menu
    3.  AVL Tree Menu
    4.  Exit
  
> [A numeric value expected]

Typing in 1 and hitting enter on this menu will give the user access to all of the functions associated with the general tree structure.  This is the full menu layout, along with a description of what each of the functions accomplish:

1.  General Tree Menu
--> Goes to
	1.  Create Stack - Creates a new stack of a user-specified initial size
	--> Goes to
		1.  Return root of tree.
	  	2.  Return number of elements in the tree.
		3.  Returns the height of the tree.
		4.  Return the height of a specific node.
		5.  Return the depth of a specific node.
		6.  Check if the tree is empty.
		7.  Return the number of leaves in the tree.
		8.  Return the number of siblings a specific node has.
		9.  Find the common ancestor of two nodes.
		10. Search for node by data.
		11. Preorder traversal.
		12. Postorder traversal.
		13. Levelorder traversal.
		14. Build tree from a text file.
		15. Clear the tree.
		16. Insert data into tree.
		17. Delete data from tree.
		18. Go back.
<--	<-- Goes Back
	2.  Back
<-- Goes Back
2.  Heap Tree Menu
--> Goes to
	1.  Create a heap tree. - Creates a new heap tree of a user-specified initial size.
	--> Goes to
		1.  Return root of tree.
	    2.  Return number of elements in the tree.
	    3.  Returns the height of the tree.
	    4.  Check if the tree is empty.
	    5.  Return the number of leaves in the tree.
	    6.  Build tree from text file.
	    7.  Clear the tree and reset to initial size.
	    8.  Insert item into tree.
	    9.  Pop max key.
	    10. Display the tree.
	    11. Display the whole entire array all the way from the start to the very bitter end.
	    12. Go back.
<--	<-- Goes Back
	2.  Back
<-- Goes Back
3.  AVL Tree Menu
--> Goes to
	1.  Create AVL Tree - Creates a AVL tree.
	--> Goes to
		1.  Return root of tree.
	    2.  Return number of elements in the tree.
	    3.  Returns the height of the tree.
	    4.  Check if the tree is empty.
	    5.  Return the number of leaves in the tree.
	    6.  Finds a specific node with the key the user enters.
	    7.  Preorder traversal.
	    8.  Postorder traversal.
	    9.  Levelorder traversal.
	    10. Inorder traversal.
	    11. Build tree from text file.
	    12. Clear tree.
	    13. Insert an item into the tree.
	    14. Remove an item from the tree.
	    15. Go back.
<--	<-- Goes Back
	2.  Back
<-- Goes Back
4. Exit 
