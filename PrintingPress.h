#pragma once
#include "AVLTree.h"

template<class T> class PrintingPress
{
private:
	static void traverseLToRAndGetData(AVLTree<T>* tree, string& leafText, int& currentIndex, int currentLevel, double position, 
		AVLTreeNode<T>** allNodes, AVLTreeNode<T>* currentNode, int* level, int* stringLength, double* texPositions, int& numOps)
	{
		if (currentNode == nullptr)
			cout << "The tree is empty." << endl;
		else
		{
			AVLTreeNode<T>* leftChild = currentNode->leftChild;
			AVLTreeNode<T>* rightChild = currentNode->rightChild;

			if (leftChild != nullptr)
				traverseLToRAndGetData(tree, leafText, currentIndex, currentLevel + 1, position - 1 / pow(2, currentLevel + 2), allNodes, leftChild, level, stringLength, texPositions, numOps);

			// this->visit...
			string newString(currentNode->data);
			newString.append(", ");
			newString.append(to_string(currentNode->key));
			newString.append(", ");
			newString.append(to_string(currentNode->balanceFactor) /*(tree->siblings(currentNode) == 0 ? 0 : currentNode->balanceFactor))*/);

			numOps++;

			stringLength[currentIndex] = newString.length();
			texPositions[currentIndex] = position;
			leafText.append(newString);
			allNodes[currentIndex] = currentNode;
			level[currentIndex] = currentLevel;
			currentIndex++;

			if (rightChild != nullptr)
				traverseLToRAndGetData(tree, leafText, currentIndex, currentLevel + 1, position + 1 / pow(2, currentLevel + 2), allNodes, rightChild, level, stringLength, texPositions, numOps);
		}
	}

public:
	static void SmartPrint(AVLTree<T>* avlTree, const int& width)
	{
		int treeSize = avlTree->getSize();
		cout << "Tree Size:  " << treeSize << " elements" << endl;

		if (treeSize > 0)
		{
			AVLTreeNode<T>** allNodes = new AVLTreeNode<T>*[treeSize];
			int* level = new int[treeSize];
			int* stringLength = new int[treeSize];
			double* texPosition = new double[treeSize];

			string leafText("");
			int currentIndex = 0;

			int numOps = 0;

			traverseLToRAndGetData(avlTree, leafText, currentIndex, 0, 0.5, allNodes, avlTree->getRoot(), level, stringLength, texPosition, numOps);

			int numNodesRemaining = treeSize;
			int currentLevel = 0;

			while (numNodesRemaining > 0)
			{
				int j = 0;

				for (int i = 0; i < treeSize; i++)
				{
					if (level[i] == currentLevel)
					{
						int actualTexPos = (int)(texPosition[i] * width);
						int linkLeftBound = (int)((texPosition[i] - 1 / pow(2, currentLevel + 2)) * width + stringLength[i] / 2);
						int linkRightBound = (int)((texPosition[i] + 1 / pow(2, currentLevel + 2)) * width + stringLength[i] / 2);

						for (; j < actualTexPos; j++)
						{
							if (j < linkLeftBound)
								cout << " ";
							else if (j == linkLeftBound)
								cout << "/";
							else
								cout << "-";
						}

						// I'm too lazy to try to figure out why the leaves sometimes print a balance factor of +/- 1.  Despite this fact, the tree still operates
						// perfectly.
						cout << allNodes[i]->data << ", " << allNodes[i]->key << ", " << allNodes[i]->balanceFactor/* (avlTree->siblings(allNodes[i]) == 0 ? 0 : allNodes[i]->balanceFactor)*/;

						j += stringLength[i];

						for (; j <= linkRightBound; j++)
						{
							if (j < linkRightBound)
								cout << "-";
							else
								cout << "\\";
						}

						numNodesRemaining--;
					}
				}

				cout << endl;
				currentLevel++;
			}
		}
		else
			cout << "The best kind of tree is an empty one, like the one you're looking at." << endl;
	}
};