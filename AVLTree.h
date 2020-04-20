//
// Created by Grace Allegrette on 4/20/20.
//
#ifndef AVLTREE_H
#define AVLTREE_H

#include <stdlib.h>

template<class K,class V>
class AVLTree {
private:
	class Node {
	private:
		Node left;
		Node right;
		Node parent;
		K key;
		V value;
	public:

	};
	Node* root;

public:
	AVLTree() {
		root = NULL;
	}

};

#endif
