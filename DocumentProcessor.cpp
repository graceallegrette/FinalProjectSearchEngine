//
// Created by Grace Allegrette on 4/16/20.
//

#include <vector>
#include <string>
#include <fstream>
#include "HelperFunctions.h"
#include "DocumentProcessor.h"

using namespace std;

vector<vector<string> > processDocument(const char *filename) {
	ifstream file(filename);
	string line;
	vector<vector<string> > rows;

	while (getline(file, line, '\n')) {
		vector<string> row = split(line, ',');
		rows.push_back(row);
	}

	file.close();
	return rows;
}
