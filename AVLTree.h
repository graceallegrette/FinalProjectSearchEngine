//
// Created by Grace Allegrette on 4/20/20.
//
#ifndef AVLTREE_H
#define AVLTREE_H

#include <stdlib.h>

template<class K, class V>
class AVLTree {
private:
	class Node {
	public:
		K* key;
		V* value;
		Node *left;
		Node *right;
		int height;

		Node(K key, V value) {
			this->key = new K (key);
			this->value = new V (value);
			left = NULL;
			right = NULL;
			height = 1;
		}

		~Node() {
			delete key;
			delete value;
		}
	};

	Node *root;
	long (*hashFunction)(K);

public:
	AVLTree(long (*hashFunction)(K)) {
		root = NULL;
		this->hashFunction = hashFunction;

	}
	// A utility function to get maximum
	// of two integers
	int max(int a, int b) {
		if (a > b) {
			return a;
		} else {
			return b;
		}
	}

    int height(Node* node)
    {
        if (node == NULL)
            return 0;
        return node->height;
    }


	// A utility function to right
	// rotate subtree rooted with y
	// See the diagram given above.
	Node* rightRotate(Node *y) {
		Node *x = y->left;
		Node *t2 = x->right;

		// Perform rotation
		x->right = y;
		y->left = t2;

		// Update heights
		y->height = max(height(y->left), height(y->right)) + 1;
		x->height = max(height(x->left), height(x->right)) + 1;

		// Return new root
		return x;
	}

	// A utility function to left
	// rotate subtree rooted with x
	// See the diagram given above.
	Node* leftRotate(Node *x) {
		Node *y = x->right;
		Node *t2 = y->left;

		// Perform rotation
		y->left = x;
		x->right = t2;

		// Update heights
		x->height = max(height(x->left), height(x->right)) + 1;
		y->height = max(height(y->left), height(y->right)) + 1;

		// Return new root
		return y;
	}

	// Get Balance factor of node N
	int getBalance(Node *node) {
		if (node == NULL) {
			return 0;
		}

		return height(node->left) - height(node->right);
	}

	V* find(Node *node, K& key) {
		if (node == NULL) {
			return NULL;
		}

		if (key < *node->key) {
			find(node->left, key);
		} else if (key > *node->key) {
			find(node->right, key);
		} else {
			return node->value;
		}
		cout << "Error in find. Should not reach this line." << endl;
		throw -1;
	}


// Recursive function to insert a key
// in the subtree rooted with node and
// returns the new root of the subtree.
Node* insert(Node *node, K key, V value) {
	/* 1. Perform the normal BST insertion */
	if (node == NULL) {
		return new Node(key, value);
	}

	if (key < *node->key) {
		node->left = insert(node->left, key, value);
	} else if (key > *node->key) {
		node->right = insert(node->right, key, value);
	} else { // Equal keys are not allowed in BST
		cout << "Error: node already inserted" << endl;
		throw -1;
	}



	/* 2. Update height of this ancestor node */
	node->height = 1 + max(height(node->left), height(node->right));

	/* 3. Get the balance factor of this ancestor
	 node to check whether this node became
	 unbalanced */
	int balance = getBalance(node);

	// If this node becomes unbalanced, then
	// there are 4 cases

	// Left Left Case
	if (balance > 1 && key < *node->left->key) {
		return rightRotate(node);
	}

	// Right Right Case
	if (balance < -1 && key > *node->right->key) {
		return leftRotate(node);
	}

	// Left Right Case
	if (balance > 1 && key > *node->left->key) {
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// Right Left Case
	if (balance < -1 && key < *node->right->key) {
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	/* return the (unchanged) node pointer */
	return node;
}

V& operator[](K key) {
	V *value = find(root, key);

	// if not in tree
	if (value == NULL) {
		Node *insertedNode = insert(root, key, NULL);
		return *(insertedNode->value);
	}
	// if already in tree
	else {
		return *value;
	}
}
};

#endif
