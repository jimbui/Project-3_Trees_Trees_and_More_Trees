#ifndef HEAPTREENODE_H
#define HEAPTREENODE_H

#include <iostream>

template<class type> class HeapTreeNode
{

private:

	int key_element ;
	type data_element ;

public:

	HeapTreeNode()
	{
		key_element = -1 ;
		data_element = "NULL" ;
	}

	HeapTreeNode(int key_in ,  type data_in)
	{
		key_element = key_in ;
		data_element = data_in ;
	}

	int get_key()
	{
		return key_element ;
	}

	type get_data()
	{
		return data_element ;
	}

	void display()
	{
		std::cout << " key: " << this->get_key() << "    element: " << this->get_data() << " \n" ;
	}
} ;

#endif
