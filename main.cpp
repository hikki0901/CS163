#include "mainStruct.h"
#include "UI.h"
#include "menu.h"
#include "fileExe.h"
int main() {

	HashTable* dict = new HashTable[26];
	for (int i = 0; i < 26; i++) {
		dict[i].head = NULL;
		dict[i].tail = NULL;
	}
	fileRead(dict, "word.txt", false);
	int choice = 0;

	Menu(dict);

	return 0;
}