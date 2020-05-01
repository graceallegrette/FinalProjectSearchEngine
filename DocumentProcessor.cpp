//
// Created by Grace Allegrette on 4/16/20.
//

#include <vector>
#include <string>
#include <fstream>
#include <set>
#include "HelperFunctions.h"
#include "DocumentProcessor.h"

using namespace std;

//vector<vector<string> > processDocument(const char *fileName) {
//	ifstream file(fileName);
//	string line;
//	vector<vector<string> > rows;
//
//	while (getline(file, line, '\n')) {
//		vector<string> row = split<vector<string> >(line, ',');
//		rows.push_back(row);
//	}
//
//	file.close();
//	return rows;
//}
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
