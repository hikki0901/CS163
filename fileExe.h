#include "mainStruct.h"
#include <fstream>
#include <string>
#include <cstdlib>

void fileRead(HashTable*& dict);
void fileWrite(HashTable*& dict);
void fileReset(HashTable*& dict);

void removeWord(HashTable*& dict, WordInfo& word);
void split(string s, vector<string>& defs);
WordInfo transfer(string r);
