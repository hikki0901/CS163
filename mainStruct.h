#pragma once
#include <iostream>
#include <fstream>

#include <cstring>
#include <vector>

using namespace std;

struct WordInfo {

	string word = "";
	
	vector<string> type;
	vector<string> def;

	int ID = 0;
	int hashKey = -1;
	bool addition;
	bool fav = false;
};

struct WordList {

	WordInfo info;
	WordList* left;
	WordList* right;
};

struct HashTable {

	WordList* head;
	WordList* tail;
};
