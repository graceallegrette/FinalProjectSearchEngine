#include <fstream>
#include <iostream>
#include "LinkedList.h"
#include "HashTable.h"
#include "String.h"
#include "AVLTree.h"
#include "QueryProcessor.h"
#include "HelperFunctions.h"
#include "DocumentProcessor.h"
#include "json.hpp"

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
//	wordCounts["C"] = 3;
//	wordCounts.inorderTraversal();
//	wordCounts["B"] = 2;
//	wordCounts.inorderTraversal();
//	wordCounts["A"] = 1;
//	wordCounts.inorderTraversal();

//	wordCounts["C"] = 3;
//	wordCounts["B"] = 2;
//	wordCounts["D"] = 4;
//	wordCounts["A"] = 1;
//	wordCounts["E"] = 5;
//	wordCounts.inorderTraversal();

	string str = "the quick brown fox";


	vector<string> listOfStrings = split(str, ' ');
	vector<vector<string> > document = processDocument("metadata-cs2341.csv");

	for(int i = 0; i < document.size(); i++) {
		for(int j = 0; j < document[i].size(); j++) {
			cout << document[i][j] << ", ";
		}
		cout << endl;
	}


	for (int i = 0; i < listOfStrings.size(); i++) {
		cout << listOfStrings[i] << endl;
	}

}

