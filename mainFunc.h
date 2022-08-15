#pragma once
#include "helper.h"

#include <algorithm>

WordList* wordSearch(HashTable* dict, string inp);
void wordDelete(HashTable*& dict, WordList*& w);
void addWord(HashTable*& dict);
void favChange(HashTable*& dict, string w, bool flag);
void editWord(HashTable*& dict, string & tmp);
void printWord(WordInfo w);
void printFav();