#include "fileExe.h"

void fileRead(HashTable*& dict, string dir, bool flag) {
	ifstream fin(dir);

	string r;
	WordInfo tmp;

	while (getline(fin, r)) {
		if (r == "") continue;
		if ((int(r[0]) < 48) || (int(r[0]) > 57)) continue;
		else {
			tmp = Trans(r);
			tmp.addition = flag;

			WordList* w = new WordList();
			w->info = tmp;

			InsertTable(dict, w);
		}
	}

	fin.close();
}
