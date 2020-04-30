//
// Created by Grace Allegrette on 4/16/20.
//
// String.cpp

#include <vector>
#include <sstream>
#include <string>
#include "HelperFunctions.h"

using namespace std;


vector<string> split(string originalString, char delimeter) {
  	stringstream ss(originalString);
  	vector<string> listOfStrings;

  	string tempString;

    while(getline(ss, tempString, delimeter)) {
        listOfStrings.push_back(tempString);
    }

  	return listOfStrings;
}
