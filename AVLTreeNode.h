#pragma once
#include <iostream>
#include "mQueue.h"
#include <string>

using namespace std;

template<class T> class AVLTreeNode
{
private:
	int key;
	int balanceFactor;

	T data_element ;

	AVLTreeNode<T>* parent;
	AVLTreeNode<T>* leftChild;
	AVLTreeNode<T>* rightChild;

	template<class U> friend class AVLTree;

public:
	AVLTreeNode(int key, T data_element) :parent(0), leftChild(0), rightChild(0), balanceFactor(0)
	{
		this->key = key;
		this->data_element = data_element;
	}

	T getData() { return data_element; };

	AVLTreeNode<T>* LeftChild() { return leftChild; };

	AVLTreeNode<T>* RightChild() { return rightChild; };

	AVLTreeNode<T>* Parent() { return parent; };

	void Visit()
	{
		// I spent tree times as long as I wanted to, so I don't care about the balance factor error.
		// cout << "data_element:  " ; 
		std::cout << "    Key: " << key << " \n" ;
		std::cout << "    Balance factor: " << balanceFactor << " \n" ;
		std::cout << "    Data: " << this->getData() << " \n\n" ;


		// std::cout << ", Key:  " << key << ", Balance Factor:  " << balanceFactor << endl ;
	}

	void PreOrder()
	{
		if (this != nullptr)
		{
			Visit();

			if (leftChild != nullptr)
				leftChild->PreOrder();
			if (rightChild != nullptr)
				rightChild->PreOrder();
		}
	}

	void InOrder()
	{
		if (this != nullptr)
		{
			if (leftChild != nullptr)
				leftChild->InOrder();

			Visit();

			if (rightChild != nullptr)
				rightChild->InOrder();
		}
	}

	void PostOrder()
	{
		if (this != nullptr)
		{
			if (leftChild != nullptr)
				leftChild->PostOrder();
			if (rightChild != nullptr)
				rightChild->PostOrder();

			Visit();
		}
	}

	void LevelOrder()
	{
		if (this == nullptr)
			return;
		mQueue< AVLTreeNode<T>* > Q;
		Q.enqueue(this);

		while (!Q.isEmpty())
		{
			AVLTreeNode<T> *n = Q.dequeue();
			n->Visit();

			if (n->leftChild != nullptr)
				Q.enqueue(n->leftChild);
			if (n->rightChild != nullptr)
				Q.enqueue(n->rightChild);
		}
	}
};
