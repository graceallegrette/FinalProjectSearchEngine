//
// Created by Grace Allegrette on 3/25/20.
//
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include<iostream>
#include<stdlib.h>

using namespace std;
template<class T>
struct Node {
	T data;
	struct Node<T> *prev;
	struct Node<T> *next;
};
//fixes friend functions with templates
template<class T> class LinkedList;
template<class T> ostream& operator<<(ostream &os, const LinkedList<T> &list);

template<class T>
class LinkedList {
protected:
//	struct Node<T> *head;
//	struct Node<T> *tail;
	int size_;

public:
	struct Node<T> *head;
	struct Node<T> *tail;
	LinkedList();
	~LinkedList();
	LinkedList(LinkedList &other);
	int size() const;
	bool isEmpty();
	void addFront(T data);
	void addBack(T data);
	T removeFront();
	T removeBack();
	void print();
	friend ostream& operator<< <T>(ostream &os, const LinkedList<T> &list);
	LinkedList<T>& operator=(const LinkedList<T> &other);
	void printBackwards();
	T* contains(T pattern);
};

template<class T>
class Stack: public LinkedList<T> {
public:
	Stack();
	~Stack();
	Stack(Stack &other);
	T peek();
	void push(T data);
	T pop();
};

//
// Created by Grace Allegrette on 3/25/20.
//
// LinkedList.cpp

template<class T> LinkedList<T>::LinkedList() {
	head = NULL;
	tail = NULL;
	size_ = 0;
}

template<class T> LinkedList<T>::~LinkedList() {
	struct Node<T> *currentNode = head;
	while (currentNode != NULL) {
		struct Node<T> *nodeToDelete = currentNode;
		currentNode = currentNode->next;
//		delete nodeToDelete;
	}
}

template<class T> LinkedList<T>::LinkedList(LinkedList<T> &other) {
	this->size_ = 0;
	this->head = NULL;
	this->tail = NULL;
	for (struct Node<T> *currentNode = other.head; currentNode != NULL;
			currentNode = currentNode->next) {
		addBack(currentNode->data);
	}
}

template<class T> int LinkedList<T>::size() const {
	return size_;
}

template<class T> bool LinkedList<T>::isEmpty() {
	return size_ == 0;
}

template<class T> void LinkedList<T>::addFront(T data) {
	if (isEmpty()) {
		struct Node<T> *newHead = new Node<T>;
		newHead->data = data;
		newHead->prev = NULL;
		newHead->next = NULL;
		head = newHead;
		tail = newHead;
	} else {
		struct Node<T> *newHead = new Node<T>;
		newHead->data = data;
		newHead->prev = NULL;
		struct Node<T> *oldHead = head;
		newHead->next = oldHead;

		oldHead->prev = newHead;

		head = newHead;
	}

	size_++;
}

template<class T> void LinkedList<T>::addBack(T data) {
	if (isEmpty()) {
		struct Node<T> *newTail = new Node<T>;
		newTail->data = data;
		newTail->prev = NULL;
		newTail->next = NULL;
		head = newTail;
		tail = newTail;
	} else {
		struct Node<T> *oldTail = tail;
		struct Node<T> *newTail = new Node<T>;
		oldTail->next = newTail;

		newTail->data = data;
		newTail->prev = oldTail;
		newTail->next = NULL;

		tail = newTail;
	}

	size_++;
}

template<class T> T LinkedList<T>::removeFront() {
	if (isEmpty()) {
		T t;
		return t;
	} else if (size_ == 1) {
		T data = head->data;
		delete head;
		head = NULL;
		tail = NULL;
		size_ = 0;
		return data;
	}

	else {
		struct Node<T> *newHead = head->next;

		newHead->prev = NULL;

		T data = head->data;
		delete head;

		head = newHead;

		size_--;
		return data;
	}
}

template<class T> T LinkedList<T>::removeBack() {
	if (isEmpty()) {
		return NULL;

	} else if (size_ == 1) {
		T data = head->data;
		delete head;
		head = NULL;
		tail = NULL;
		size_ = 0;
		return data;
	} else {
		struct Node<T> *newTail = tail->prev;

		newTail->next = NULL;

		T data = tail->data;
		delete tail;

		tail = newTail;

		size_--;
		return data;
	}
}

template<class T> Stack<T>::Stack() :
		LinkedList<T>() {

}

template<class T> Stack<T>::Stack(Stack &other) :
		LinkedList<T>(other) {

}

template<class T> Stack<T>::~Stack() {

}

template<class T> T Stack<T>::peek() {
	return LinkedList<T>::head->data;
}

template<class T> void Stack<T>::push(T data) {
	LinkedList<T>::addFront(data);
}

template<class T> T Stack<T>::pop() {
	return LinkedList<T>::removeFront();
}

template<class T> void LinkedList<T>::print() {
	if (isEmpty()) {
		if (head != NULL) {
			cout << "Error empty list. Head not NULL";
			cout << endl;
		}
		if (tail != NULL) {
			cout << "Error empty list. Tail not NULL";
			cout << endl;
		}
		if (size_ != 0) {
			cout << "Error empty list. size not zero";
			cout << endl;
		}
		cout << "Empty list.";
		cout << endl;
	} else {
		struct Node<T> *currNode = head;
		int count = 0;
		while (currNode->next != NULL) {
			cout << currNode->data << endl;
			count++;
			currNode = currNode->next;
		}
		cout << currNode->data << endl << endl;
		count++;
		if (currNode != tail) {
			cout << "Error tail not found";
			cout << endl;
		}
		if (count != size_) {
			cout << "Count does not equal size";
			cout << endl;
		}
	}
}

template<class T> ostream& operator<<(ostream &os, const LinkedList<T> &list) {
	if (list.isEmpty()) {
		if (list.head != NULL) {
			os << "Error empty list. Head not NULL";
			cout << endl;
		}
		if (list.tail != NULL) {
			os << "Error empty list. Tail not NULL";
			cout << endl;
		}
		if (list.size_ != 0) {
			os << "Error empty list. size not zero";
			cout << endl;
		}
		os << "Empty list.";
		cout << endl;
	} else {
		struct Node<T> *currNode = list.head;
		int count = 0;
		while (currNode->next != NULL) {
			os << currNode->data << endl;
			count++;
			currNode = currNode->next;
		}
		os << currNode->data << endl << endl;
		count++;
		if (currNode != list.tail) {
			os << "Error tail not found";
			cout << endl;
		}
		if (count != list.size_) {
			os << "Count does not equal size";
			cout << endl;
		}
	}
	return os;
}

template<class T> LinkedList<T>& LinkedList<T>::operator=(
		const LinkedList<T> &other) {
	this->size_ = 0;
	this->head = NULL;
	this->tail = NULL;
	for (struct Node<T> *currentNode = other.head; currentNode != NULL;
			currentNode = currentNode->next) {
		this->addBack(currentNode->data);
	}
	return *this;
}

template<class T> void LinkedList<T>::printBackwards() {
	if (isEmpty()) {
		if (head != NULL) {
			cout << "Error empty list. Head not NULL";
			cout << endl;
		}
		if (tail != NULL) {
			cout << "Error empty list. Tail not NULL";
			cout << endl;
		}
		if (size_ != 0) {
			cout << "Error empty list. size not zero";
			cout << endl;
		}
		cout << "Empty list.";
		cout << endl;
	} else {
		struct Node<T> *currNode = tail;
		int count = 0;
		while (currNode->prev != NULL) {
			cout << currNode->data << endl;
			count++;
			currNode = currNode->prev;
		}
		cout << currNode->data << endl << endl;
		count++;
		if (currNode != head) {
			cout << "Error head not found";
			cout << endl;
		}
		if (count != size_) {
			cout << "Count does not equal size";
			cout << endl;
		}
	}

}

template<class T> T* LinkedList<T>::contains(T pattern) {
	for (struct Node<T> *currNode = head; currNode != NULL;
			currNode = currNode->next) {
		if (currNode->data == pattern) {
			return &currNode->data;
		}
	}
	return NULL;
}

#endif
