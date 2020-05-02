//
// Created by Grace Allegrette on 4/16/20.
//

#include <vector>
#include <sstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <set>
#include "HelperFunctions.h"

using namespace std;


set<string> getUnion(set<string> set1, set<string> set2) {
	set<string> result;
	set_union(set1.begin(), set1.end(), set2.begin(), set2.end(),
			inserter(result, result.begin()));
//		 result.resize(it - result.begin());

	return result;
}

set<string> getIntersection(set<string> set1, set<string> set2) {
	set<string> result;
	set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(),
			inserter(result, result.begin()));
//		 result.resize(it - result.begin());

	return result;
}

set<string> getDifference(set<string> set1, set<string> set2) {
	set<string> result;
	set_difference(set1.begin(), set1.end(), set2.begin(), set2.end(),
			inserter(result, result.begin()));
//		 result.resize(it - result.begin());

	return result;
}

