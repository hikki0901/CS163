#include "fileExe.h"
#include "mainFunc.h"

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
	
	ifstream f_2("favorite.txt");

	string s;
	WordInfo tmp2;

	while (getline(f_2, s)) {
		if (s == "") continue;
		if ((int(s[0]) < 48) || (int(s[0]) > 57)) continue;
		else {
			tmp2 = Trans(s);

			WordList* W = wordSearch(dict, tmp2.word);
			W->info.fav = true;

		}
	}

	f_2.close();
}

void fileWrite(HashTable*& dict) {

	vector<string> deFile;
	vector<string> adFile;
	vector<string> faFile;

	for (int i = 0; i < 26; i++) {
		WordList* tmp = dict[i].head;

		if (tmp == NULL) continue;
		while (tmp != NULL) {
			string s = unTrans(tmp->info);

			if (tmp->info.addition == false) deFile.push_back(s);
			if (tmp->info.addition == true) adFile.push_back(s);
			if (tmp->info.fav == true) faFile.push_back(s);

			tmp = tmp->right;
		}
	}
	
	ofstream f_1;
	f_1.open("word1.txt", ios::out | ios::trunc);

	for (int i = 0; i < deFile.size(); i++)
		f_1 << deFile[i] << endl;

	f_1.close();

	ofstream f_2;
	f_2.open("addition1.txt", ios::out | ios::trunc);

	for (int i = 0; i < adFile.size(); i++)
		f_2 << adFile[i] << endl;

	f_2.close();

	ofstream f_3;
	f_3.open("favorite1.txt", ios::out | ios::trunc);

	for (int i = 0; i < faFile.size(); i++)
		f_3 << faFile[i] << endl;

	f_3.close();
}

void dataReset(HashTable*& dict) {

	for (int i = 0; i < 26; i++) {
		dict[i].head = NULL;
		dict[i].tail = NULL;
	}
	fileRead(dict, "default.txt", false);
	fileWrite(dict);
}