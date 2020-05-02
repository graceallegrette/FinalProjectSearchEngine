//
// Created by Grace Allegrette on 4/28/20.
//
#ifndef HELPERFUNCTIONS_H
#define HELPERFUNCTIONS_H

#include <string>
#include <set>
#include <sstream>

using namespace std;

template<class T>
T split(string originalString, char delimeter) {
	stringstream ss(originalString);
	T listOfStrings;

	string tempString;

	while (getline(ss, tempString, delimeter)) {
		listOfStrings.insert(listOfStrings.end(), tempString);
	}

	return listOfStrings;
}
set<string >getUnion(set<string> set1, set<string> set2);
set<string> getIntersection(set<string> set1, set<string> set2);
set<string> getDifference(set<string> set1, set<string> set2);


#endif
