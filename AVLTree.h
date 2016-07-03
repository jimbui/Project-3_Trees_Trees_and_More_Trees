#pragma once
#include "AVLTreeNode.h"
#include "PrintingPress.h"
#include <fstream>
#include <string>

template<class T> class AVLTree
{
private:
	AVLTreeNode<T>* root;
	int sz;

	// Helper Methods ------------------------------------------------------------------
	void parseLine(string line, int& key, string& data)
	{
		string::size_type sz;
		int pos = line.find(' ');
		string k = line.substr(0, pos);
		data = line.substr(pos + 1);
		key = stoi(k, &sz);
	}

	// Uses recursion to traverse the tree.  # of leaves = # of nodes with no children.
	int getLeaves(AVLTreeNode<T>* node)
	{
		if (node == nullptr)
			return 0;

		int valAdded = 0;

		if (siblings(node) == 0)
			valAdded = 1;

		if (node->leftChild != nullptr)
			valAdded += getLeaves(node->leftChild);
		if (node->rightChild != nullptr)
			valAdded += getLeaves(node->rightChild);

		return valAdded;
	}

	// Traverses the entire tree and deletes all of its elements.  O(n) is the running time.
	void TraverseAndDeleteAll(AVLTreeNode<T>* current)
	{
		if (current != nullptr)
		{
			TraverseAndDeleteAll(current->leftChild);
			TraverseAndDeleteAll(current->rightChild); // Traverse the entire tree before deleting elements

			delete current;
			sz--;
		}
	}

	// The base case, from which all rebalancing will occur.  Unfortunately, the runtime is O(n^2) until further notice.
	void RebalanceBase(AVLTreeNode<T>* start, int& numOps, bool isADeletion)
	{
		AVLTreeNode<T>* current = start;
		bool isADeletionCurrent = isADeletion;
		bool firstCall = true;

		// int breakLoop = 0;

		while (current != nullptr /*&& breakLoop < 100*/)
		{
			AVLTreeNode<T>* it = current;
			current = Rebalance(it, 0, numOps, isADeletionCurrent, firstCall);

			if (current == nullptr)
				break;

			if (current->balanceFactor == 2)
			{
				current = RotateRight(current, true, numOps);
				firstCall = true;
			}
			else if (current->balanceFactor == -2)
			{
				current = RotateLeft(current, true, numOps);
				firstCall = true;
			}

			numOps++;

			// AVLTreeNode<T>* duh = root;
			/*breakLoop++;*/
			isADeletionCurrent = false;
			// firstCall = false;
		}
	}

	AVLTreeNode<T>* Rebalance(AVLTreeNode<T>* start, int currentHeight, int& numOps, bool isADeletion, bool firstCall)
	{
		// AVLTreeNode<T>* temp = start;
		int direction = 0;
		/*bool breakThis = false;*/

		while (start != nullptr)
		{
			// bool doThisAgain = false;

			if (currentHeight == 0 && firstCall) // Base case --> check height of both subtrees
			{
				int leftSubtreeHeight = (start->leftChild == nullptr ? 0 : getHeight(start->leftChild, numOps) + 1);
				int rightSubtreeHeight = (start->rightChild == nullptr ? 0 : getHeight(start->rightChild, numOps) + 1);

				start->balanceFactor = leftSubtreeHeight - rightSubtreeHeight /*+ balanceAdded*/;

				currentHeight = (leftSubtreeHeight > rightSubtreeHeight ? leftSubtreeHeight : rightSubtreeHeight) - (isADeletion ? 1 : 0);
			}
			else
			{
				if (direction == 1)  // Approaching from left --> check height of parent's right subtree
				{
					int newHeight = (start->rightChild != nullptr ? getHeight(start->rightChild, numOps) + 1 : 0);

					start->balanceFactor = currentHeight - newHeight;  // Height(left) - Height(right)

					if (currentHeight < newHeight)
						currentHeight = newHeight;
				}
				else if (direction == -1)  // Approaching from right --> check height of parent's left subtree
				{
					int newHeight = (start->leftChild != nullptr ? getHeight(start->leftChild, numOps) + 1 : 0);

					start->balanceFactor = newHeight - currentHeight;  // Height(left) - Height(right)

					if (currentHeight < newHeight)
						currentHeight = newHeight;
				}
			}

			if (start->balanceFactor >= 2 || start->balanceFactor <= -2)
				return start;

			/*if (start->balanceFactor == -2)
			{
				RotateLeft(start);
				break;
			}*/

			// Determines direction
			if (start->parent != nullptr)
			{
				if (start->parent->rightChild == start)  // Approaching from right
					direction = -1;
				else if (start->parent->leftChild == start) // Approaching from left
					direction = 1;
			}

			start = start->parent;
			currentHeight++;
		}

		return nullptr;
	}

	// Performs a right rotation or left-right rotation on a set of nodes.  O(1) due to constant running time
	AVLTreeNode<T>* RotateRight(AVLTreeNode<T>* nodeA, bool performAdditionalRotation, int& numOps)
	{
		AVLTreeNode<T>* nodeB = nodeA->leftChild;

		if (nodeB->balanceFactor < 0 && performAdditionalRotation)  // An additional left rotation is required to keep the tree balanced.
		{
			nodeB = RotateLeft(nodeB, false, numOps);
			return nodeB;
		}

		AVLTreeNode<T>* parent = nodeA->parent;

		if (parent != nullptr)
		{
			if (parent->leftChild == nodeA)
				parent->leftChild = nodeB;
			if (parent->rightChild == nodeA)
				parent->rightChild = nodeB;
		}

		nodeA->leftChild = nodeB->rightChild;
		nodeB->rightChild = nodeA;

		nodeB->parent = parent;
		nodeA->parent = nodeB;

		if (parent == nullptr)
			root = nodeB;

		numOps++;

		return nodeA;
	}

	// Performs a left rotation or right-left rotation on a set of nodes.  O(1) due to constant running time
	AVLTreeNode<T>* RotateLeft(AVLTreeNode<T>* nodeA, bool performAdditionalRotation, int& numOps)
	{
		AVLTreeNode<T>* nodeB = nodeA->rightChild;

		if (nodeB->balanceFactor > 0 && performAdditionalRotation)  // An additional right rotation is required to keep the tree balanced.
		{
			nodeB = RotateRight(nodeB, false, numOps);
			return nodeB;
		}

		AVLTreeNode<T>* parent = nodeA->parent;

		if (parent != nullptr)
		{
			if (parent->leftChild == nodeA)
				parent->leftChild = nodeB;
			if (parent->rightChild == nodeA)
				parent->rightChild = nodeB;
		}

		nodeA->rightChild = nodeB->leftChild;
		nodeB->leftChild = nodeA;

		nodeB->parent = parent;
		nodeA->parent = nodeB;

		if (parent == nullptr)
			root = nodeB;

		numOps++;

		return nodeA;
	}

public:
	// Constructor ------------------------------------------------------------------
	AVLTree() :root(0), sz(0)
	{}

	// Destructor ------------------------------------------------------------------
	~AVLTree()
	{
		// Delete all of the nodes in the tree
		clear();
	}

	// Accessor Methods ------------------------------------------------------------------
	AVLTreeNode<T>* getRoot() const { return root; };

	int getSize() const { return sz; };

	// Base case
	int getHeight(int& numOps)
	{
		// numOps++;
		return getHeight(root, numOps);
	}

	// Recursive definition --> This method iterates through all of the nodes, stores the height of the
	// left and right subtrees, and returns the greater value.
	int getHeight(AVLTreeNode<T>* node, int& numOps)
	{
		numOps++;

		if (node == nullptr) 
			return 0;

		int leftHeight = 0;
		int rightHeight = 0;

		if (node->leftChild != nullptr) 
			leftHeight = 1 + getHeight(node->leftChild, numOps);
		if (node->rightChild != nullptr)
			rightHeight = 1 + getHeight(node->rightChild, numOps);

		return (leftHeight > rightHeight ? leftHeight : rightHeight);
	}

	// Gets the depth of the node in the argument
	int getDepth(AVLTreeNode<T>* node)
	{
		if (node == nullptr || node == root) 
			return 0;
		else
			return 1 + depth(node->parent);  // The depth of the node in the argument
	}

	// Determines whether or not the tree is empty
	bool empty() const { return root == nullptr; };

	// Gets the number of leaves in the tree.  O(n)
	int leaves()
	{
		return getLeaves(root);
	}

	// Gets the number of siblings of the specified node.  O(1)
	int siblings(AVLTreeNode<T>* node)
	{
		int siblingCount = 0;

		if (node == nullptr)
			throw underflow_error("The node you entered is a nullptr.");

		if (node->leftChild != nullptr)
			siblingCount++;
		if (node->rightChild != nullptr)
			siblingCount++;

		return siblingCount;
	}

	// O(log2(n))
	AVLTreeNode<T>* find(const int& key/*, const T& data*/)
	{
		if (root == nullptr)
			throw underflow_error("This tree burned in hell, so it is empty and there's no data to be found.");

		AVLTreeNode<T>* desiredNode = root;

		while (desiredNode != nullptr)
		{
			if (key < desiredNode->key)
			{
				// This is a patch due to an error I've been having.
				if (desiredNode->leftChild != nullptr)
					desiredNode->leftChild->parent = desiredNode;

				desiredNode = desiredNode->leftChild;
			}
			else if (key > desiredNode->key)
			{
				// This is a patch due to an error I've been having.
				if (desiredNode->rightChild != nullptr)
					desiredNode->rightChild->parent = desiredNode;

				desiredNode = desiredNode->rightChild;
			}
			else
			{
				if (desiredNode == nullptr)
					throw underflow_error("We're sorry, but we couldn't retrieve the item for you because it does not exist.");

				// Else
				return desiredNode;
			}
		}
	}

	// Performs preorder traversal and prints result.  O(n)
	void preorder()
	{
		root->PreOrder();
	}

	// Performs postorder traversal  O(n)
	void postorder()
	{
		root->PostOrder();
	}

	// Performs level order traversal  O(n)
	void levelorder()
	{
		root->LevelOrder();
	}

	// Performs inorder traversal  O(n)
	void inorder()
	{
		root->InOrder();
	}

	// Mutator Methods ------------------------------------------------------------------
	// Builds a new tree from a file
	void buildTree(const string& fileName)
	{
		string line;
		ifstream myfile(fileName);

		int duhr = 0;

		if (myfile.is_open())
		{
			string data;
			int key;
			while (getline(myfile, line))
			{
				parseLine(line, key, data);
				insert(key, data, duhr);
			}
			myfile.close();
		}
		else
			cout << "Unable to open file";
	}

	// Removes all elements in the tree --> O(n) is the running time.
	void clear()
	{
		TraverseAndDeleteAll(root);
		root = nullptr;
	}

	// Inserts a new node with specified key and data values (O(log2(n)) best case, and O(n) is the worst case.)
	void insert(const int& key, const T& data)
	{
		if (root == nullptr)
		{
			AVLTreeNode<T>* n = new AVLTreeNode<T>(key, data);
			root = n;
			sz++;

			// GetBalanceFactors(root); --> No need for rebalancing when inserting the first item.
		}
		else
		{
			AVLTreeNode<T>* n = new AVLTreeNode<T>(key, data);
			sz++;

			AVLTreeNode<T>* ptr = root;
			AVLTreeNode<T>* prev = nullptr;
			/*AVLTreeNode<T>* ancestor = nullptr;*/

			int ind = 0;

			while (ptr != nullptr)
			{
				/*if (ptr->balanceFactor != 0)
					ancestor = ptr;*/

				if (key <= ptr->key)
				{
					prev = ptr;
					ptr = ptr->leftChild;
					ind = 0;
				}
				else if (key > ptr->key)
				{
					prev = ptr;
					ptr = ptr->rightChild;
					ind = 1;
				}
			}

			n->parent = prev;

			if (ind == 0) 
				prev->leftChild = n;
			else 
				prev->rightChild = n;

			int duh = 0;

			RebalanceBase(n, duh, false);
		}
	}

	void insert(const int& key, const T& data, int& numOps)
	{
		if (root == nullptr)
		{
			AVLTreeNode<T>* n = new AVLTreeNode<T>(key, data);
			root = n;
			sz++;

			// GetBalanceFactors(root); --> No need for rebalancing when inserting the first item.
			numOps++;
		}
		else
		{
			AVLTreeNode<T>* n = new AVLTreeNode<T>(key, data);
			sz++;

			AVLTreeNode<T>* ptr = root;
			AVLTreeNode<T>* prev = nullptr;
			/*AVLTreeNode<T>* ancestor = nullptr;*/

			int ind = 0;

			while (ptr != nullptr)
			{
				/*if (ptr->balanceFactor != 0)
				ancestor = ptr;*/

				if (key <= ptr->key)
				{
					prev = ptr;
					ptr = ptr->leftChild;
					ind = 0;
				}
				else if (key > ptr->key)
				{
					prev = ptr;
					ptr = ptr->rightChild;
					ind = 1;
				}
			}

			n->parent = prev;

			if (ind == 0)
				prev->leftChild = n;
			else
				prev->rightChild = n;

			numOps++;

			RebalanceBase(n, numOps, false);
		}

		// cout << "Runtime : number of elements = " << numOps << " : " << sz << " = " << (double)numOps / sz << endl;
	}

	// Deletes an existing node with the specified key.  O(n) due to rebalancing.
	void del(const int& key)
	{
		if (root != nullptr)
		{
			AVLTreeNode<T>* current = find(key);
			AVLTreeNode<T>* parent = current->parent;

			if (siblings(current) == 2)
			{
				AVLTreeNode<T>* successor = current->rightChild;
				parent = current;

				while (successor->leftChild != nullptr)
				{
					parent = successor;
					successor = successor->leftChild;
				}

				current->key = successor->key;
				current->data = successor->data;

				current = successor;
			}

			AVLTreeNode<T>* subtree = current->leftChild;

			if (subtree == nullptr)
				subtree = current->rightChild;

			if (parent == nullptr)
				root = subtree;
			else if (parent->leftChild == current)
				parent->leftChild = subtree;
			else
				parent->rightChild = subtree;

			int duh = 0;

			RebalanceBase(parent, duh, true);
			delete current;
			sz--;
		}
	}

	void del(const int& key, int& numOps)
	{
		if (root != nullptr)
		{
			AVLTreeNode<T>* current = find(key);
			AVLTreeNode<T>* parent = current->parent;
			AVLTreeNode<T>* subtree = nullptr;
			// AVLTreeNode<T>* successor = nullptr;

			if (siblings(current) == 2)
			{
				AVLTreeNode<T>* successor = current->rightChild;
				parent = current;

				while (successor->leftChild != nullptr)
				{
					parent = successor;
					successor = successor->leftChild;

					numOps++;
				}

				current->key = successor->key;
				current->data = successor->data;

				current = successor;
			}

			subtree = current->leftChild;

			if (subtree == nullptr)
				subtree = current->rightChild;

			if (parent == nullptr)
				root = subtree;
			else if (parent->leftChild == current)
				parent->leftChild = subtree;
			else
				parent->rightChild = subtree;

			numOps++;

			/*if (subtree != nullptr)
				RebalanceBase(current, numOps);
			else
			{
				if (siblings(current) == 0)
					RebalanceBase(parent, numOps);
				else
					RebalanceBase(current, numOps);
			}*/

			if (siblings(current) == 2)
			{
				RebalanceBase(current, numOps, true);
			}
			else if (siblings(current) == 1)
			{
				if (subtree != nullptr)
					subtree->parent = parent;

				RebalanceBase(subtree, numOps, false);
			}
			else
			{
				if (parent != nullptr)
				{
					if (current == parent->rightChild)
						parent->rightChild = nullptr;
					else if (current == parent->leftChild)
						parent->leftChild = nullptr;
				}

				current->parent = nullptr;
				RebalanceBase(parent, numOps, false);
			}
			
			delete current;
			
			sz--;
		}

		// cout << "Runtime : number of elements = " << numOps << " : " << sz << " = " << (double)numOps / sz << endl;
	}
};