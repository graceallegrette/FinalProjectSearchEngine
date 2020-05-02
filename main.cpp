#include <fstream>
#include <iostream>
#include <set>
#include "LinkedList.h"
#include "HashTable.h"
#include "String.h"
#include "AVLTree.h"
#include "QueryProcessor.h"
#include "HelperFunctions.h"
#include "DocumentProcessor.h"
#include "json.hpp"

using namespace std;
using namespace nlohmann;

long stringHashFunction(String string) {
	long hash = 0;
	for (int i = 0; i < string.getLength(); i++) {
		hash += string[i];
		hash *= 13;
	}
	return hash;

}

int main(int argc, char *argv[]) {
//	AVLTree<string, long> wordCounts(&stringHashFunction);
//	vector<vector<string> > document = processDocument("metadata-cs2341.csv");

	set<string> set1 = { "brown", "quick", "the", "yay" };
	set<string> set2 = { "fox", "brown", "the" };
	set<string> result = getDifference(set1, set2);
	set<string> stopWords = processStopWords("stopWords.txt");
//	AVLTree<string, long> words;

	set<string>::iterator it;
	for (it = result.begin(); it != result.end(); it++) {
	//	cout << *it << endl;
	}

	for (it = stopWords.begin(); it != stopWords.end(); it++) {
//		cout << *it << endl;
	}
	processDocument("metadata-cs2341.csv");
}

