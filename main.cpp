#include "mainStruct.h"
#include "UI.h"

int main() {
	HashTable* dict = new HashTable[26];
	for (int i = 0; i < 26; i++) {
    		dict[i].head = NULL;
		dict[i].tail = NULL;
	}
	return 0;
}
