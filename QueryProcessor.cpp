//
// Created by Grace Allegrette on 4/16/20.
//
// String.cpp
#include "String.h"
#include <cstring>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;


void process(string query) {

}

vector<string> split(string originalString) {
  	stringstream ss(originalString);
  	vector<string> listOfStrings;

  	string tempString;

    while(getline(ss, tempString, ' ')) {
        listOfStrings.push_back(tempString);
    }

  	return listOfStrings;
}
