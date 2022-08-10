#include "mainStruct.h"
#include "UI.h"

int main() {
  Wordlist* hashTable = new Wordlist[26];
  for (int i = 0; i < 26; i++) {
        hashTable[i]->left = NULL;
        hashTable[i]->right = NULL;
  }
  return 0;
}
