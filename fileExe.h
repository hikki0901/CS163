#include "mainStruct.h"
#include <fstream>
#include <string>
#include <cstdlib>

void fileRead(Wordlist*& hashTable);
void fileWrite(Wordlist*& hashTable);
void fileReset(Wordlist*& hashTable);

void removeWord(Wordlist*& hashTable, WordInfo& word);
void split(string s, vector<string>& defs);
WordInfo transfer(string r);
