//
// Created by Grace Allegrette on 2/16/20.
//
#ifndef STRING_H
#define STRING_H
#include <iostream>
#include <string>

class String {

private:
    char* information;
    int length_;
    bool equal(char* c_str1, char* c_str2, int length) const;

public:
    String();
    String(const String& arg);
    String(const char* other);
    ~String();
    String& operator=(const String& arg);
    String& operator=(const char* other);
    String& operator+=(const String& other);
    bool operator<(const String& other) const;
    bool operator>(const String& other) const;
    bool operator==(const String& other) const;
    bool operator!=(const String& other) const;
    bool operator<=(const String& other) const;
    bool operator>=(const String& other) const;
    friend std::ostream& operator<<(std::ostream& myOstream, const String& a);
    friend std::istream& operator>>(std::istream& myIstream, String& a);
    int getLength();
//    char at(int index);
    String removeLastChar();
//    void set(int index, char ch);
	char& operator[](size_t index);
	const char& operator[](size_t index) const;
	String substring(size_t start, size_t end);
	char* c_str();
	bool contains(const String& searchTerm) const;
	bool containsPhrase(const String& searchTerm) const;
};

String operator+(const String& lhs,const String& rhs);

#endif
