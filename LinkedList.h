#pragma once
#include "LinkedListNode.h"
#include<iostream>
#include<cassert>
#include <stdexcept>      // std::exception
using namespace std;

template <class T> class LinkedList{
public:
    LinkedListNode<T> * head;
    int sz;

	template<class U> friend class GenTreeNode;

public:
    LinkedList():sz(0),head(nullptr){
    }
    bool isEmpty() const{
        return head == nullptr;
    }
    int getSize() {
        return sz;
    }
    void insert(const T & data){
        LinkedListNode<T> *tmp = new LinkedListNode<T>(data);
        if (head==nullptr){
            head = tmp;
            sz++;
        }
        else{
            LinkedListNode<T> *ptr = head;
            while(ptr->next!=nullptr){
                ptr = ptr->next;
            }
            ptr->next = tmp;
            sz++;
        }
    }
    void insert (const T & data, int pos){
        if (pos <=0){
            LinkedListNode<T> *tmp = new LinkedListNode<T>(data,head);
            head = tmp;
            sz++;
        }
        else if (pos >= sz){
            LinkedList::insert(data);
        }
        else{
            LinkedListNode<T> *ptr = head;
            int k = 0;
            while(ptr->next !=nullptr){
                if (k==pos-1){
                    LinkedListNode<T> *tmp = new LinkedListNode<T>(data);
                    tmp->next = ptr->next;
                    ptr->next = tmp;
                    sz++;
                    break;
                }
                else{
                    ptr = ptr->next;
                    k++;
                }
            }
        }

    }

    void del(const T & data){
        LinkedListNode<T> *ptr = head;
        LinkedListNode<T> *prev = head;
        if(this->isEmpty()){//check if the list is empty
            throw underflow_error("You cannot delete something when there's nothing to delete. Can you ?");
        }
        else{
            while (ptr->next!=nullptr){
                if (ptr->data == data){
                    if (ptr == head){
                        head = head->next;
                        delete prev;
                        sz--;
                    }
                    else{
                        LinkedListNode<T> *tmp = ptr->next;
                        ptr->id = ptr->next->id;
                        ptr->data = ptr->next->data;
                        ptr->next = ptr->next->next;
                        delete tmp;
                        sz--;
                    }
                }
                prev = ptr;
                ptr = ptr->next;
            }
            if (ptr->data==data){
                prev->next = nullptr;
                delete ptr;
                sz--;
            }
        }
    }
    void printList() const{
        LinkedListNode<T> *ptr = head;
        while(ptr->next!=nullptr){
            cout << "Node[" << ptr->id << "]= '" << ptr->data << "'-->";
            ptr = ptr->next;
        }
        cout << "Node[" << ptr->id << "]= '" << ptr->data << "'-->";
        cout << "end" << endl;
    }

	T getData () {
		if (this->head == nullptr) {return 0;}
		else return this->head->data;
	}

	T getNext () {
		if (this->head == nullptr) {return 0;}
		else return this->head->next->data;
	}

	T getData (int pos) {
		int count = 0;
		LinkedListNode<T> *ptr = head;
		if (ptr == nullptr) {throw underflow_error ("The list is empty");}
		
		while (ptr != nullptr)
		{
			if (count == pos)
			{
				return ptr->data;
			}
			
			ptr = ptr->next;

			count++;
		}

		throw underflow_error ("The item was not found");
	}

	T PopFront () 
	{
		LinkedListNode <T> *tmp = head;
		T data = head->data;
		head = head->next;

		delete tmp;
		sz--;
		
		return data;
	}


};