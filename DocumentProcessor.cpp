//
// Created by Grace Allegrette on 4/16/20.
//

#include <vector>
#include <string>
#include <fstream>
#include <set>
#include <iostream>
#include "HelperFunctions.h"
#include "DocumentProcessor.h"
#include "json.hpp"

using namespace std;
using namespace nlohmann;

vector<vector<string> > getCsv(const char *fileName) {
	ifstream file(fileName);
	string line;
	vector<vector<string> > rows;

	while (getline(file, line, '\n')) {
		vector<string> row = split<vector<string> >(line, ',');
		rows.push_back(row);
	}

	file.close();
	return rows;
}

set<string> processStopWords(const char *fileName) {
	ifstream file(fileName);
	string line;
	set<string> stopWords;
	while (getline(file, line, '\n')) {
		stopWords.insert(line);
	}
	file.close();
	return stopWords;
}

void processDocument(const char *fileName) {
	ifstream file;
	json jsonObj;

	vector<vector<string> > rows = getCsv(fileName);
	for (int i = 1; i < rows.size(); i++) {
		cout << rows[i][1] + ".json" << endl;
		file.open("cs2341_data/" + rows[i][1] + ".json");
		if (!file) {
			cout << "Error- failed to open file." << endl;
			exit(-1);
		}
		file >> jsonObj;
		file.close();
		set<string>::iterator it;

		for(int i = 0; i < jsonObj.size(); i++) {
			set<string> words = split<set<string> >(jsonObj["body_text"][i]["text"], ' ');
			for (it = words.begin(); it != words.end(); it++) {
				cout << *it << " ";
			}
			cout << endl;
		}

	}
}
