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

template<class T>
class HashTable {
private:
	LinkedList<T>* buckets;

public:
	HashTable(){
		buckets = new LinkedList<T> [NUMBER_OF_BUCKETS];
	}
	~HashTable(){
		delete[] buckets;
	}

	put() {

	}




};







#endif
