#pragma once
#include "mainStruct.h"


void addWord(HashTable*& hash);
void add(WordInfo& tmp, HashTable*& hash);
void saveNewWord(WordInfo tmp);
void fix(WordInfo& tmp, HashTable*& hash);
bool check(string& def, HashTable*& hash);
string lower(string& a);
WordInfo search(HashTable*& hash, string& def);
bool compare(Wordlist*& tmpWord, string& first, string& second);

