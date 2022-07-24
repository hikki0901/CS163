#include "fileExe.h"

void fileRead(hashing*& dict) {
  ifstream fi("words.txt");
	string r;
	
	if (fi.is_open()) {
		while (getline(fi, dong)) {
			if (r == "") continue;
			WordInfo p = transfer(r);
		}
		fi.close();
	}
}
