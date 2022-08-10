#include "fileExe.h"
#include <string>

using namespace std;

void split(string s, vector<string>& defs){
    vector<int> pos;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '-') pos.push_back(i);

    pos.push_back(s.size() + 1);
    for (int i = 0; i < pos.size() - 1; i++) {
        string token = s.substr(pos[i] + 1, pos[i+1] - 2);
        defs.push_back(token);
    }

}

WordInfo transfer(string r) {

    WordInfo tmp;
    int i = 0; string ID = "";

    while ((int(r[i]) >= 48) && (int(r[i]) <= 57)) ID += r[i++];
    tmp.ID = stoi(ID, 0, 10); r.erase(0, i + 1);

    i = 0; string w = "";
    while (r[i] != ' ') w += r[i++];
    tmp.word = w;

    if (r[0] == '-') {
        r.erase(0, i + 2);
        tmp.def.push_back(r);
        return tmp;
    } else {
        i = 0; r.erase(0, i + 2);

        if (r[i] != '-') {
            string t = "";
            while (r[i] != '.') t += r[i++];

            tmp.type.push_back(t);
            r.erase(0, i + 2);
            tmp.def.push_back(r);
        } else {
            vector<string> defs;
            split(r, defs);

            for (int i = 0; i < defs.size(); i++) {
                int j = 0; string t = "";
                while (defs[i][j] != '.') t += defs[i][j++];

                tmp.type.push_back(t);
                defs[i].erase(0, j + 2);
                tmp.def.push_back(defs[i]);
            }

        }
    }
    return tmp;
}

void fileRead(hashing*& dict) {
  ifstream fi("words.txt");
	string r;
	
	if (fi.is_open()) {
		while (getline(fi, r)) {
			if (r == "") continue;
			WordInfo p = transfer(r);
		}
		fi.close();
	}
}
