#include <fstream>
#include <iostream>
#include "LinkedList.h"
#include "HashTable.h"
#include "String.h"
#include "AVLTree.h"

using namespace std;

long stringHashFunction(String string) {
	long hash = 0;
	for(int i= 0; i < string.getLength(); i++) {
		hash += string[i];
		hash *= 13;
	}
	return hash;

}

int main(int argc, char *argv[]) {
//	HashTable<String, long> wordCounts(&stringHashFunction);
	AVLTree<String, long> wordCounts(&stringHashFunction);
	wordCounts["the"] = 25;
	long count = wordCounts["the"];
	cout << count << endl;
	wordCounts["the"] = 24;
	cout << wordCounts["the"] << endl;
	wordCounts["the"]++;
	cout << wordCounts["the"] << endl;

}

