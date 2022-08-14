#pragma once
#include "mainStruct.h"

WordInfo Trans(string r);
void InsertTable(HashTable*& dict, WordList* new_word);
void Split(string s, string delimiter, vector<string>& defPlaceholder);

bool wordCheck(string inp, WordList* w);