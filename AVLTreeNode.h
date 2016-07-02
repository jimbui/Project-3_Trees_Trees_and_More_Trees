#pragma once
#include <iostream>
#include "mQueue.h"

using namespace std;

template<class T> class AVLTreeNode
{
private:
	int key;
	int balanceFactor;

	T data;

	AVLTreeNode<T>* parent;
	AVLTreeNode<T>* leftChild;
	AVLTreeNode<T>* rightChild;

	template<class U> friend class AVLTree;
	template<class U> friend class PrintingPress;

public:
	AVLTreeNode(const int& key, const T& data) :parent(0), leftChild(0), rightChild(0), balanceFactor(0)
	{
		this->key = key;
		this->data = data;
	}

	T getData() const { return data; };

	AVLTreeNode<T>* LeftChild() { return leftChild; };

	AVLTreeNode<T>* RightChild() { return rightChild; };

	AVLTreeNode<T>* Parent() { return parent; };

	void Visit() const
	{
		// I spent tree times as long as I wanted to, so I don't care about the balance factor error.
		cout << "Data:  " << data << ", Key:  " << key << ", Balance Factor:  " << (leftChild == nullptr && rightChild == nullptr ? 0 : balanceFactor) << endl;
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