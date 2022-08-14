#include "helper.h"

void Split(string s, char delimiter, vector<string>& defPlaceholder) {

	vector<int> pos;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == delimiter) {
			int tmp = int(s[i + 1]);
			if ((tmp >= 97) && (tmp <= 122))
				pos.push_back(i);
		}
	}
	pos.push_back(s.size() + 1);

	for (int i = 0; i < pos.size() - 1; i++) {
		string tmp = s.substr(pos[i] + 1, pos[i + 1] - 2);
		defPlaceholder.push_back(tmp);
	}
}

WordInfo Trans(string r) {

	WordInfo tmp;
	int i = 0;

	while ((int(r[i]) >= 48) && (int(r[i]) <= 57))
		tmp.ID = tmp.ID * 10 + (int(r[i++]) - 48);

	while ((r[i] != ' ') || (r[i + 1] != ' '))
		if (r[i++] != ' ') tmp.word += r[i - 1];

	if (tmp.word[0] == '-') {
		tmp.hashKey = int(tmp.word[1]) - 97;
		tmp.def.push_back(r.substr(i + 2, r.size() - 1));
		return tmp;
	}
	else {
		tmp.hashKey = int(tmp.word[0]) - 65;
		r.erase(0, i + 2); i = 0;

		if (r[i] != '-') {
			string t = "";
			while (r[i] != '.') t += r[i++];

			tmp.type.push_back(t);
			tmp.def.push_back(r.substr(i + 2, r.size() - 1));
		}
		else {
			vector<string> dp;
			Split(r, '-', dp);

			for (int i = 0; i < dp.size(); i++) {
				int j = 0; string t = "";
				while (dp[i][j] != '.') t += dp[i][j++];

				tmp.type.push_back(t);
				tmp.def.push_back(dp[i].substr(j + 2, dp[i].size() - 1));
			}
		}
	}

	return tmp;
}

void InsertTable(HashTable*& dict, WordList* nWord) {
	int  i = nWord->info.hashKey;
	if (dict[i].head == NULL) {
		dict[i].head = nWord;
		dict[i].tail = nWord;
	}
	else {
		dict[i].tail->right = nWord;
		nWord->left = dict[i].tail;
		dict[i].tail = nWord;
	}
}

bool wordCheck(string inp, WordList* w) {

	if (inp[0] == '-') inp = inp.substr(1, inp.size() - 1);

	string tmp = "";
	if (w->info.word[0] == '-')
		tmp = w->info.word.substr(1, w->info.word.size() - 1);
	else tmp = w->info.word;

	tmp = ucFirstletter(tmp);
	inp = ucFirstletter(inp);

	if (inp.size() != tmp.size()) return false;
	
	for (int i = 0; i < inp.size(); i++)
		if (inp[i] != tmp[i])
			return false;

	return true;
}

string ucFirstletter(string s) {
	if ((s[0] != ' ') && (int(s[0]) >= 97))
		s[0] = s[0] - 32;
	return s;
}
