//
// Created by Grace Allegrette on 4/28/20.
//
#ifndef DOCUMENTPROCESSOR_H
#define DOCUMENTPROCESSOR_H

#include <vector>
#include <string>
#include <set>

using namespace std;

vector<vector<string> > processDocument(const char *fileName);
set<string> processStopWords(const char *fileName);

#endif
