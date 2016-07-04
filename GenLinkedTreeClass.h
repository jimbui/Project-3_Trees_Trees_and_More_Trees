#pragma once
#include "GenTreeNode.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
using namespace std;

template <class type> 
class GenLinkedTreeClass{
private:
	int size;
	GenTreeNode<type> *root;

	int getleaves(GenTreeNode<type> *temp)
	{
		int valAdded = 0;

		if (temp == nullptr) 
			return 0;

		if (temp->children->isEmpty()) 
			valAdded = 1;

		int sz = temp->children->getSize();
		int counter = 0;

		for (counter = 0; counter < sz;counter++)
		{
			valAdded += getleaves(temp->children->getData(counter));
		}

		return valAdded;
	}

	// Modification:  No recursion (runtime = O(n))
	GenTreeNode<type>* findNodePrivate(/*int count,*/ int key, GenTreeNode<type> *temp)
	{
		if (temp == nullptr)
			throw underflow_error("The tree is empty.");

		GenQueue< GenTreeNode<type>* > Q;

		Q.enqueue(temp);

		while (!Q.isEmpty()) 
		{
			GenTreeNode<type> *n = Q.dequeue();

			// n->Visit();
			if (n->key == key)
				return n;

			int sz = n->children->getSize();
			int counter = 0;

			for (counter = 0; counter < sz; counter++)
				Q.enqueue(n->children->getData(counter));
		}

		throw underflow_error("The data was not found");
	}

public:
	GenLinkedTreeClass():root(0),size(0)
	{
		// buildTree("tree.txt");
		buildTreeInsert() ;
	}

	~GenLinkedTreeClass() {
		delete root;
		root = nullptr;
	}

	GenTreeNode<type>* getRoot() const {return root;}//returns root
	
	int getSize() const {return size;}				//returns size
	
	int getHeight()
	{
		int height = 0;
		height = getHeight(root);
		return height;
	}			
	
	int getHeight(GenTreeNode<type> *node)		//returns height according to node
	{
		int nodeHeight = 0;
		
		while (node != nullptr)
		{
			node = node->children->getData();
			if (node == nullptr)
				break;
			nodeHeight++;
		}
		
		return nodeHeight;
	
	}

	int getDepth(GenTreeNode<type> *node)								//returns depth
	{
		int depth = 0;

		if (node == nullptr) {return 0;}
		while (node != root)
		{
			depth++;
			node = node->parent;
		}

		return depth;
	
	}

	bool empty() const {return root == nullptr;}

	int leaves() 
	{
		return getleaves(root);	
	
	}

	int siblings(GenTreeNode<type>* node)			//returns siblings according to node
	{
		int siblings = 0;
		GenTreeNode<type>* temp = node;
		if (temp == nullptr) {return 0;}
		else {siblings = temp->children->getSize();}
		
		return siblings;
	}

	// O(n) is the worst case scenario.  It will occur when the tree has a single branch extending from its root.
	GenTreeNode<type>* findCommonAncestor(GenTreeNode<type>* node1, GenTreeNode<type>* node2)
	{
		GenTreeNode<type>* it1 = node1;
		GenTreeNode<type>* it2 = node2;

		int depthNode1 = getDepth(it1);
		int depthNode2 = getDepth(it2);

		if (depthNode1 == 0 || depthNode2 == 0)
			return nullptr;

		while (depthNode1 != 0)
		{
			if (depthNode2 > depthNode1)
			{
				depthNode2--;
				it2 = it2->parent;
			}
			else if (depthNode1 > depthNode2)
			{
				depthNode1--;
				it1 = it1->parent;
			}
			else 
			{
				depthNode1--;
				depthNode2--;
				it1 = it1->parent;
				it2 = it2->parent;

				if (it1 == it2)  // The common ancestor of two nodes should not be one of the nodes itself.
					return it1;
			}
		}
	}

	GenTreeNode<type>* findNode(int key)
	{
		return findNodePrivate(key, root);
	}

	//Visit the passed node data
	void visit(GenTreeNode<type> *ptr)
	{
        cout << ptr->data << endl;
    }

	void preorder()
	{
		root->PreOrder();
	}

	void postorder()
	{
		root->PostOrder();
	}

	void levelorder()
	{
		root->LevelOrder();
	}

	//Find parent
	// GenTreeNode<type> * findParent(string str){
 //        int level = 0;
 //        for (int i=str.size()-1;i>=0;i--){
 //            if (str[i]=='.') level++;
 //        }
 //        if (level<1) return root;
 //        else{
 //            int last_dot = str.find_last_of('.');
 //            int cur_level = 0;
 //            str = str.substr(last_dot+1); // 0.#.#.par_pos
 //            string::size_type sz;
 //            int par_pos = stoi(str,&sz);
 //            GenTreeNode<type> * ptr = root;
	// 		LinkedList<GenTreeNode<type> *> *tmp;
 //            while (ptr !=nullptr && cur_level!=level){
	// 			tmp = ptr->children;
	// 			//ptr= ptr->children->head->data;
 //                cur_level++;
 //            }
	// 		ptr = tmp->getData(par_pos);
 //            /*for(int i=0;i<par_pos;i++){
 //                ptr = ptr->children->getData();
 //            }*/
 //            return ptr;
 //        }
 //    }

	//Mutators

	void buildTree(string path)
	{
		string line;
        ifstream myfile (path);
        if (myfile.is_open())
        {
            while ( getline (myfile,line) )
            {
				string str(line);
				string key(str.substr(0, str.find_first_of(' ')));  // Get key from input string

				//cout << "key = \"" << key << "\"" << endl;

				str = str.substr(str.find_first_of(' ') + 1, str.length());

				string data(str.substr(0, str.find_first_of(' ')));  // Get data from input string

				//cout << "data = \"" << data << "\"" << endl << endl;

				str = str.substr(str.find_first_of(' ') + 1, str.length());

				int currentLevel = 0;
				int temp = stoi(key) ;
				GenTreeNode<type>* newNode = new GenTreeNode<type>(data, temp);
				GenTreeNode<type>* currentNode = root;

				// Enter into while-loop --> this will be used to find the parent.
				while (str.length() > 0)
				{
					// int endPos = (str.find_first_of('.') < str.find_first_of('>') ? str.find_first_of('.') : str.find_first_of('>'));
					int endPos = 0 ;

					if (str.find_first_of('.') < str.find_first_of('>'))
					{
						endPos = str.find_first_of('.') ;
					}

					else
					{
						endPos =str.find_first_of('>') ;
					}

					string parentIndex(str.substr(0, endPos));

					// if (currentLevel > 0)
					//		currentNode = currentNode->children->getData(stoi(parentIndex));  // Move to next child pointer

					//cout << "parentIndex[" << currentLevel << "] = \"" << parentIndex << "\"" << endl;
					str = str.substr(endPos + 1, str.length());

					if (str.length() > 0 && currentLevel > 0 )
					{
						temp = stoi(parentIndex) ;
						currentNode = currentNode->children->getData(temp);  // Move to next child pointer

						int duh=666;
					}
					else if (str.length() == 0)
					{
						 newNode->parent = currentNode;
						 if (currentNode == nullptr){ root = newNode; }
						 else
						 {
						 	temp = stoi(parentIndex) ; 
						 	currentNode->children->insert(newNode, temp);
						 }
						 size++;
					}

					currentLevel++;
				}
				//int key_pos = line.find(">");
				//int key = stoi(line.substr(0, key_pos));
    //            int pos = line.find(' ');
    //            string data = line.substr(key_pos+1,pos);
    //            string str = line.substr(pos+1);
    //            pos = str.find_last_of('.');
    //            string str2 = str.substr(pos+1);
    //            string::size_type sz;
    //            int node_pos = stoi(str2,&sz);
    //            str = str.substr(0,pos);
    //            GenTreeNode<type> *ptr = findParent(str);
    //            // cout << "parent for " << data << " is "<< (ptr==nullptr?"nullptr":ptr->data)<<endl;
    //            insert(data,ptr,node_pos, key);
            }
            myfile.close();
        }
        else cout << "Unable to open file";
	}

	void buildTreeInsert()
	{
		insert("data_structures" , NULL , 0 , 10) ; 
		insert("hws" , findNode(10) , 0 , 11) ;
		insert("projects" , findNode(10) , 1 , 12) ;
		insert("quizzes" , findNode(10) , 2 , 13) ;
		insert("exams" , findNode(10) , 3 , 14) ;
		insert("hw1" , findNode(11) , 0 , 15) ;
		insert("p1" , findNode(12) , 0 , 16) ;
		insert("p2" , findNode(12) , 1 , 17) ;
		insert("q1" , findNode(13) , 0 , 18) ;
		insert("q2" , findNode(13) , 1 , 19) ;
		insert("q3" , findNode(13) , 2 , 20) ;
		insert("q4" , findNode(13) , 3 , 21) ;
		insert("final_exam" , findNode(14) , 0 , 22) ;
	}

	void clear()
	{
		delete root;
		root = nullptr;
		cout << "Tree has been deleted" << endl;
	}


	void insert(const type &data, GenTreeNode<type> *parent,int node_pos,int key)
	{
		cout << "Inserting " << data <<" in position "<<node_pos<<  ", parent is " << (parent==nullptr?"NULL, this is the root.":parent->data) << endl;
        GenTreeNode<type> *n = new GenTreeNode<type>(data, key);
        if (parent==nullptr){
            root = n;
            size++;
        }
        else{
            if (parent->children->isEmpty()){
                n->parent = parent;
                parent->children->insert(n);
                size++;
            }
            else{
                //GenTreeNode<type> *ptr = parent->children->insert(;
                //while(ptr->next_sibling!=nullptr) ptr = ptr->next_sibling;
                n->parent = parent;
				parent->children->insert(n, node_pos);
                //ptr->next_sibling=n;
                size++;
            }
        }
	}

	void del (int key)
	{
		GenTreeNode<type> * done = findNode(key);
		GenTreeNode<type> * replacement = nullptr;

		if (done->children->isEmpty()) 
		{ 
			//delete done;
			done->parent->children->del(done);
		}
		else {
			replacement = done->children->getData();
			done->data = replacement->data;
			done->children = replacement->children;
			done->key = replacement->key;
			done->children->del(replacement);
		}
		size--;	
	}
};
