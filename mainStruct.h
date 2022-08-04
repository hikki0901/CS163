#pragma once
#include <iostream>
#include <fstream>
#include <vector>

#include <windows.h>
#include <conio.h>

using namespace std;

struct WordInfo {
	string word;
	string type;

	vector<string> def;
	vector<string> examples;
	
	int curWordsCount = 0;
	int maxWordsCount = 3;
	int id;
	bool addition;
};

struct Wordlist {
	WordInfo info;
	Wordlist* left;
	Wordlist* right;
};

struct hashing {
	Wordlist* head;
	Wordlist* tail;
};
