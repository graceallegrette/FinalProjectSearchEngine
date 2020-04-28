#include <fstream>
#include <iostream>
#include "LinkedList.h"
#include "HashTable.h"
#include "String.h"
#include "AVLTree.h"

using namespace std;

long stringHashFunction(String string) {
	long hash = 0;
	for (int i = 0; i < string.getLength(); i++) {
		hash += string[i];
		hash *= 13;
	}
	return hash;

}

int main(int argc, char *argv[]) {
//	HashTable<String, long> wordCounts(&stringHashFunction);
	AVLTree<String, long> wordCounts(&stringHashFunction);
	wordCounts["C"] = 3;
	wordCounts.inorderTraversal();
	wordCounts["B"] = 2;
	wordCounts.inorderTraversal();
	wordCounts["A"] = 1;
	wordCounts.inorderTraversal();

}

