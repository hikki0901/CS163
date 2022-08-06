#include <fstream>
#include <string>
#include <cstdlib>

void fileRead(hashing*& dict);
void fileWrite(hashing*& dict);
void fileReset(hashing*& dict);

void removeWord(hashing*& dict, WordInfo& word);
WordList* transfer(string r);

