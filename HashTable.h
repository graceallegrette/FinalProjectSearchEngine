//
// Created by Grace Allegrette on 4/16/20.
//
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include<iostream>
#include<stdlib.h>
#include "LinkedList.h"

#define NUMBER_OF_BUCKETS 1000

using namespace std;

template<class K, class V>
class KeyValuePair {
public:
	K* key;
	V* value;
	KeyValuePair() {
		key = NULL;
		value = NULL;
	}
	void setKey(const K& key) {
		this->key = new K (key);
	}
	void setValue(const V& value) {
		this->value = new V (value);
	}
	K& getKey() {
		return *key;
	}
	V& getValue() {
		return *value;
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

	~HashTable() {
		delete[] buckets;
	}

	V& operator[](const K &key) {
		int bucketIndex = hashFunction(key) % NUMBER_OF_BUCKETS;
		LinkedList<KeyValuePair<K, V> > list = buckets[bucketIndex];

		for (struct Node<KeyValuePair<K, V> > *currentNode = list.head;
				currentNode != NULL; currentNode = currentNode->next) {
			KeyValuePair<K, V> pair = currentNode->data;
			if (pair.getKey() == key) {
				return pair.getValue();
			}
		}
		KeyValuePair<K, V> newPair;
		newPair.setKey(key);
		list.addBack(newPair);
		return *(newPair.value);
	}

	const V& operator[](const K &key) const {

	}

};

#endif
