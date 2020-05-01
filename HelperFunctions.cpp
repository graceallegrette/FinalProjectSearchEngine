//
// Created by Grace Allegrette on 4/16/20.
//
// String.cpp

#include <vector>
#include <sstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <set>
#include "HelperFunctions.h"

using namespace std;

template<class T>
T split(string originalString, char delimeter) {
	stringstream ss(originalString);
	T listOfStrings;

	string tempString;

	while (getline(ss, tempString, delimeter)) {
		listOfStrings.insert(tempString);
	}

	return listOfStrings;
}

set<string> getUnion(set<string> set1, set<string> set2) {
	set<string> result;
//	sort(set1.begin(), set1.end());
//	sort(set2.begin(), set2.end());
	set_union(set1.begin(), set1.end(), set2.begin(), set2.end(),
			inserter(result, result.begin()));
//		 result.resize(it - result.begin());

	return result;
}

set<string> getIntersection(set<string> set1, set<string> set2) {
	set<string> result;
//	sort(set1.begin(), set1.end());
//	sort(set2.begin(), set2.end());
	set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(),
			inserter(result, result.begin()));
//		 result.resize(it - result.begin());

	return result;
}

set<string> getDifference(set<string> set1, set<string> set2) {
	set<string> result;
//	sort(set1.begin(), set1.end());
//	sort(set2.begin(), set2.end());
	set_difference(set1.begin(), set1.end(), set2.begin(), set2.end(),
			inserter(result, result.begin()));
//		 result.resize(it - result.begin());

	return result;
}

