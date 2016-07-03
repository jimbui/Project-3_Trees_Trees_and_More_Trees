#pragma once
#include <iostream>
#include "LinkedList.h"
#include "GenQueue.h"
using namespace std;

template<class type>
class GenTreeNode{
private:
    type data;
	int key;
    GenTreeNode<type> * parent;
	LinkedList<GenTreeNode<type>* > * children;
	//GenTreeNode<type> * children;
	//GenTreeNode<type> * next_sibling;

	template<class U> friend class GenLinkedTreeClass;

public:
    GenTreeNode():key(0),parent(0){
		children = new LinkedList<GenTreeNode<type> *> ();
    }
    GenTreeNode(const type &data):key(0),parent(0){
        this->data = data;
		children = new LinkedList<GenTreeNode<type> *> ();
    }
	GenTreeNode(const type &data, int key):parent(0){
		this->data = data;
		this->key= key;
		children = new LinkedList<GenTreeNode<type> *> ();
	}

	void Visit() const
	{
		cout << "Data:  " << data << ", Key:  " << key << endl;
	}

	void PreOrder()
	{
		if (this != nullptr)
		{
			this->Visit();
			LinkedList<GenTreeNode<type> *> * tmp = this->children;
        
			int sz = this->children->getSize();
			int counter = 0;

			for (counter = 0; counter < sz;counter++){
				tmp->getData(counter)->PreOrder();
			}
			
       
		}
	}

	void PostOrder()
	{
        if (this != nullptr)
		{
			LinkedList<GenTreeNode<type> *> * tmp = this->children;
        
			int sz = this->children->getSize();
			int counter = 0;

			for (counter = 0; counter < sz;counter++){
				tmp->getData(counter)->PostOrder();
			}

			this->Visit();
       
		}
	}

	void LevelOrder()
	{
		if (this == nullptr)
			return;

		GenQueue< GenTreeNode<type>* > Q;
		Q.enqueue(this);

		while (!Q.isEmpty()){

			GenTreeNode<type> *n = Q.dequeue();
			n->Visit();

			int sz = n->children->getSize();
			int counter = 0;

			for (counter = 0; counter < sz;counter++){
				Q.enqueue(n->children->getData(counter));
			}

		}
	}

};






