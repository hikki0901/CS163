#pragma once
#include <iostream>
#include <fstream>
#include <vector>

#include <windows.h>
#include <conio.h>

using namespace std;

struct WordInfo {
	string word;
	
	vector<string> type;
	vector<string> def;
	
	int ID;
	bool addition;
};

struct Wordlist {
	WordInfo info;
	Wordlist* left;
	Wordlist* right;
};
