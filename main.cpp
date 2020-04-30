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

	for (int i = 0; i < document.size(); i++) {
		for (int j = 0; j < document[i].size(); j++) {
			//cout << document[i][j] << ", ";
		}
		//cout << endl;
	}
	auto j3 = json::parse("{ \"happy\": true, \"pi\": 3.141 }");
	cout << j3["happy"] << endl;

	// Initializing 1st vector
	 vector<int> v1 = {1, 3, 4, 5, 20, 30};

	 // Initializing 2nd vector
	 vector<int> v2 = {1, 5, 6, 7, 25, 30};

	 // Declaring resultant vector
	 // for union
	 vector<int> v3(10);

	 // Declaring resultant vector
	 // for intersection
	 vector<int> v4(10);

	 // using set_union() to compute union  of 2
	 // containers v1 and v2 and store result in v3
	 auto it = set_union(v1.begin(), v1.end(), v2.begin(),
	                              v2.end(), v3.begin());

	 // using set_intersection() to compute intersection
	 // of 2 containers v1 and v2 and store result in v4
	 auto it1 = set_intersection(v1.begin(),v1.end(),
	               v2.begin(), v2.end(), v4.begin());

	 // resizing new container
	 v3.resize(it - v3.begin());

	 // resizing new container
	 v4.resize(it1 - v4.begin());

	 // Displaying set union
	 cout << "Union of two containers is : ";
	 for (int &x : v3)
	     cout << x << " ";
	 cout << endl;

}

