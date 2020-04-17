//
// Created by Grace Allegrette on 2/16/20.
//
// String.cpp
#include "String.h"
#include <cstring>
#include <iostream>
//#include "Vector.h"

using namespace std;

#define MAX_STRING_SIZE 1000

//string:: string() first creates an object of string which takes in information and puts to null
String::String() {
	length_ = 0;
	information = new char[1];
	information[0] = '\0';
}

//creates an object in string
String::String(const String &other) {
	length_ = other.length_;
	information = new char[length_ + 1]; // +1 for null terminator
	strcpy(information, other.information);
}

String::String(const char *c) {
	length_ = strlen(c);
	information = new char[length_ + 1];
	strcpy(information, c);
}

String::~String() {
	delete[] information;
}

// overrides the = sign operator
String& String::operator=(const String &other) {
	if (this != &other) {
		delete[] information;
		this->length_ = other.length_;
		information = new char[this->length_ + 1];
		strcpy(information, other.information);
	}
	return *this;
}

// overrides the = sign operator
String& String::operator=(const char *other) {
	delete[] information;
	this->length_ = strlen(other);
	information = new char[this->length_ + 1];
	strcpy(information, other);

	return *this;
}

// sets += operator to perform string concatenation
String& String::operator+=(const String &other) {
	if (this != &other) {
		char *newInformation = new char[this->length_ + other.length_ + 1];

		strcpy(newInformation, information);
		strcpy(newInformation + this->length_, other.information); // start copying from the end of the first string
		this->length_ += other.length_;
		delete[] information; // must delete before setting the new one
		information = newInformation;
	}
	return *this;
}

//sets == operator
bool String::operator==(const String &other) const {
	return strcmp(information, other.information) == 0;
}

bool String::operator!=(const String &other) const {
	return strcmp(information, other.information) != 0;
}

//sets < operator
bool String::operator<(const String &other) const {
	return strcmp(information, other.information) < 0;
}

//sets > operator
bool String::operator>(const String &other) const {
	return strcmp(information, other.information) > 0;
}

//sets <= operator
bool String::operator<=(const String &other) const {
	return strcmp(information, other.information) <= 0;
}

//sets >= operator
bool String::operator>=(const String &other) const {
	return strcmp(information, other.information) >= 0;
}

String operator+(const String &lhs, const String &rhs) {
	String result(lhs);
	result += rhs;
	return result;
}

std::ostream& operator<<(std::ostream &os, const String &rhs) {
	os << rhs.information;
	return os;
}

std::istream& operator>>(std::istream &is, String &rhs) {
	char buffer[MAX_STRING_SIZE];
	is >> buffer;

	rhs = buffer; // call assignment operator to create class from the string in the buffer

	return is;
}

int String::getLength() {
	return length_;
}
//
//char String::at(int index) {
//	return information[index];
//}

String String::removeLastChar() {
	information[length_ - 1] = '\0';
	length_--;
	return *this;
}

//void String::set(int index, char ch) {
//	information[index] = ch;
//}

char& String::operator[](size_t index) {
	return information[index];
}

const char& String::operator[](size_t index) const {
	return information[index];
}
String String::substring(size_t start, size_t length) {
	String substr;
	delete[] substr.information;
	substr.length_ = length;
	substr.information = new char[substr.length_ + 1];
	for (int i = start, j = 0; i < (start + length); i++, j++) {
		substr.information[j] = information[i];
	}
	substr.information[substr.length_] = '\0';

	return substr;
}

char* String::c_str() {
	return information;
}

bool String::contains(const String &searchTerm) const {
	int length = this->length_ - searchTerm.length_ + 1;
	char *c_str1 = this->information;
	char *c_str2 = searchTerm.information;

	for (int i = 0; i < length; i++) {
		if (equal(c_str1 + i, c_str2, searchTerm.length_)) {
			return true;
		}
	}
	return false;
}

bool String::containsPhrase(const String &searchTerm) const {
	int length = this->length_ - searchTerm.length_ + 1;
	char *c_str1 = this->information;
	char *c_str2 = searchTerm.information;

	for (int i = 0; i < length; i++) {
		if ((i == 0 || c_str1[i - 1] == ' ')
				&& (i == length - 1 || c_str1[i + searchTerm.length_] == ' ')
				&& equal(c_str1 + i, c_str2, searchTerm.length_)) {
			return true;
		}
	}
	return false;
}

bool String::equal(char *c_str1, char *c_str2, int length) const {
	for (int i = 0; i < length; i++) {
		if (c_str1[i] != c_str2[i]) {
			return false;
		}
	}
	return true;
}







