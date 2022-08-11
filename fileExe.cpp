#include "fileExe.h"
#include <string>

using namespace std;

void InsertTable(HashTable*& dict, Wordlist* new_word) {
    int  i = new_word->info.key;
    if (dict[i]->head == NULL) {
        dict[i]->head = new_word;
        dict[i]->tail = new_word;
    } else {
        dict[i]->tail->right = new_word;
        new_word->left = dict[i]->tail;
        dict[i]->tail = new_word;
    }
}

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
    int i = 0; 
    string ID = "";

    while ((int(r[i]) >= 48) && (int(r[i]) <= 57)) ID += r[i++];
    tmp.ID = stoi(ID, 0, 10); 
    r.erase(0, i + 1);

    i = 0; 
    string w = "";
    while (r[i] != ' ') w += r[i++];
    tmp.word = w;

    if (r[0] == '-') {
        r.erase(0, i + 2);
        tmp.def.push_back(r);
        return tmp;
    } else {
        r.erase(0, i + 2); 
	i = 0; 

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

void fileRead(HashTable*& dict) {
    ifstream fin("word.txt");

    string r;
    int hash_id;
    WordInfo tmp;

    while (getline(fin, r)) {
        if (r == "") continue;
        int num =  int(r[0]);
        if ((num < 48) || (num > 57)) hash_id = int(r[0]) - 65;
        else {
            tmp = transfer(r);
            tmp.key = hash_id;
            tmp.addition = false;
            
            Wordlist* new_word = new_word Wordlist();
            new_word->info = tmp;
            
            InsertTable(dict, new_word);
        }
    }

    fin.close();
}
