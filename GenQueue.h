#pragma once
#include "LinkedList.h"
template<class type>
class GenQueue :public LinkedList<type> {
private:
	LinkedListNode<type> *tail;
public:
	GenQueue() :tail(nullptr) {}
	bool isEmpty() const {
		return LinkedList<type>::isEmpty();
	}
	void enqueue(const type & data) {
		LinkedListNode<type> *tmp = new LinkedListNode<type>(data);
		if (this->isEmpty()) {
			LinkedList<type>::head = tmp;
			tail = tmp;
			LinkedList<type>::sz++;
		}
		else {
			tail->next = tmp;
			tail = tmp;
			LinkedList<type>::sz++;
		}
	}

	type front() const {
		if (this->isEmpty()) throw underflow_error("Empty Queue");
		return LinkedList<type>::head->data;
	}

	type back() const {
		if (this->isEmpty()) throw underflow_error("Empty Queue");
		return tail->data;
	}

	type dequeue() {
		type dat = this->front();
		LinkedListNode<type> *ptr = LinkedList<type>::head;
		LinkedList<type>::head = ptr->next;
		delete ptr;
		LinkedList<type>::sz--;
		return dat;
	}

	int size() {
		return LinkedList<type>::sz;
	}

	void static display(GenQueue<type> & Q) {
		GenQueue<type> Qtmp;
		while (!Q.isEmpty()) {
			type d = Q.dequeue();
			Qtmp.enqueue(d);
			cout << d << "->";
		}
		cout << "back" << endl;
		Q = Qtmp;
	}
};