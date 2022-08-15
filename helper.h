#pragma once
#include "mainStruct.h"

#include <string>

WordInfo Trans(string r);
string unTrans(WordInfo w);

void InsertTable(HashTable*& dict, WordList* new_word);
void Split(string s, string delimiter, vector<string>& defPlaceholder);

bool wordCheck(string inp, WordList* w);
string ucFirstletter(string s);