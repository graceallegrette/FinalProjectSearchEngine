//
// Created by Grace Allegrette on 4/16/20.
//
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include<iostream>
#include<stdlib.h>
#include "LinkedList.h"
#include "String.h"

#define NUMBER_OF_BUCKETS 1000

using namespace std;

template<class K, class V>
class KeyValuePair {
public:
	K *key;
	V *value;
	KeyValuePair() {
		key = new K();
		value = new V();
	}
	KeyValuePair(const KeyValuePair<K, V> &other) {
		this->key = new K(*(other.key));
		this->value = new V(*(other.value));
	}
	~KeyValuePair() {

		delete key;

		delete value;

	}

	void setKey(const K &key) {
		delete this->key;
		this->key = new K(key);

	}
	void setValue(const V &value) {
		delete this->value;
		this->value = new V(value);

	}
	K& getKey() {
		return *key;

	}
	V& getValue() {
		return *value;

	}
	KeyValuePair<K, V>& operator=(const KeyValuePair<K, V> &other) {
		delete this->key;
		delete this->value;
		this->key = new K(*(other.key));
		this->value = new V(*(other.value));

		return *this;
	}

};

template<class K, class V>
class HashTable {
private:
	LinkedList<KeyValuePair<K, V> > *buckets;
	long (*hashFunction)(K);

public:
	HashTable(long (*hashFunction)(K)) {
		buckets = new LinkedList<KeyValuePair<K, V> > [NUMBER_OF_BUCKETS];
		this->hashFunction = hashFunction;

	}
	HashTable(const HashTable<K, V> &other) {
		buckets = new LinkedList<KeyValuePair<K, V> > [NUMBER_OF_BUCKETS];
		for (int i = 0; i < NUMBER_OF_BUCKETS; i++) {
			this->buckets[i] = other.buckets[i];
		}
		this->hashFunction = other.hashFunction;
	}

	~HashTable() {
		delete[] buckets;

	}

	V& operator[](const K &key) {
		int bucketIndex = hashFunction(key) % NUMBER_OF_BUCKETS;
		LinkedList<KeyValuePair<K, V> > list = buckets[bucketIndex];
		cout << list.size() << endl;
		for (struct Node<KeyValuePair<K, V> > *currentNode = list.head;
				currentNode != NULL; currentNode = currentNode->next) {
			KeyValuePair<K, V> pair = currentNode->data;
			cout << pair.getKey() << endl;
			cout << pair.getValue() << endl;
			cout << "TIGER KING" << endl;
			if (pair.getKey() == key) {
				cout << "pair" << endl;
				return pair.getValue();
			}
		}
		KeyValuePair<K, V> newPair;
		newPair.setKey(key);
		list.addBack(newPair);
		cout << "newPair" << endl;
		return newPair.getValue();

	}
	HashTable<K, V>& operator=(const HashTable<K, V> &other) {
		for (int i = 0; i < NUMBER_OF_BUCKETS; i++) {
			this->buckets[i] = other.buckets[i];
		}
		this->hashFunction = other.hashFunction;
	}

	const V& operator[](const K &key) const {

	}

};

#endif
