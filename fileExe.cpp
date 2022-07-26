#include "fileExe.h"

WordInfo transfer(string r) {
    WordInfo tmp;
    int i = 0;
    int pos;

    string Word = "";
    while (r[i] != '/') {
        Word += r[i++];
    }
    tmp.word = Word; i++;
    
    string Type = "";
    while (r[i] != '/') {
        Type += r[i++];
    }
    tmp.type = Type; i++;
    
    tmp.curWordsCount = atoi(r[i]);
    i += 2;
    
    while (r[i] != '/') {
        string Def = "";
        while (r[i] != ';') {
            Def += r[i++];
        }
        tmp.def.push_back(Def);
        i++;
    } 
    i++;
    
    while (r[i] != '/') {
        string Examples = "";
        while (r[i] != ';') {
            Examples += r[i++];
        }
        tmp.examples.push_back(Examples);
        i++;
    } 
	return tmp;
}

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
