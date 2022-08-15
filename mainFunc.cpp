#include "mainFunc.h"
#include "fileExe.h"

WordList* wordSearch(HashTable* dict, string inp) {
	
	inp = ucFirstletter(inp);
	int key = int(inp[0]) - 65;
	WordList* list = dict[key].head;

	
	while (list != NULL) {
		if (wordCheck(inp, list))
			return list;
		list = list->right;
	}

	return NULL;
}

void wordDelete(HashTable*& dict, WordList*& w) {

	int i = w->info.hashKey;

	WordList* H = dict[i].head;
	WordList* T = dict[i].tail;

	if ((H == T) && (wordCheck(H->info.word, w) == true)) {
		H = NULL;
		T = NULL;
	} 
	
	if (wordCheck(H->info.word, w) == true) {

		if (H->right == NULL) {
			H = NULL;
			T = NULL;		
		}

		H = H->right;
		H->left = NULL;
	} else if (wordCheck(T->info.word, w) == true) {
		T = T->left;
		T->right = NULL;
	}
	else {
		WordList* tmp = H;

		do {
			tmp = tmp->right;

			if (wordCheck(tmp->info.word, w) == true) {
				WordList* L = tmp->left;
				WordList* R = tmp->right;

				tmp->left = NULL;
				tmp->right = NULL;
				tmp = NULL;
				delete tmp;

				L->right = R;
				R->left = L;

				break;
			}
		} while (true);
	}

	w = NULL;
	delete w;

	dict[i].head = H;
	dict[i].tail = T;

}

void addWord(HashTable*& dict) {

	WordInfo tmp;
	cout << "Enter the word you want to add: ";
	cin.ignore(1000, '\n');
	getline(cin, tmp.word);

	tmp.word = ucFirstletter(tmp.word);
	tmp.hashKey = int(tmp.word[0]) - 65;
	tmp.addition = true;

	int maxID = -1;
	for (int i = 0; i < 26; i++) {
		WordList* p = dict[i].head;

		while (p != NULL) {
			maxID = max(maxID, p->info.ID);
			p = p->right;
		}
	}
	tmp.ID = maxID + 1;

	cout << "How many word types does your word have? ";
	int tCount; cin >> tCount;

	for (int i = 0; i < tCount; i++) {
		cout << "What is your word type? " << endl;
		cout << "1. noun     2. verb     3. adjective     4. adverb" << endl;
		cout << "Your choice (enter the number correspond with the word type): ";
		int n; cin >> n;
		if (n == 1) tmp.type.push_back("n");
		if (n == 2) tmp.type.push_back("v");
		if (n == 3) tmp.type.push_back("adj");
		if (n == 4) tmp.type.push_back("adv");

		string d = "";
		cout << "Enter the definition: ";
		cin.ignore(1000, '\n');
		getline(cin, d);
		tmp.def.push_back(d);
	}

	WordList* addedWord = new WordList();
	addedWord->info = tmp;
	InsertTable(dict, addedWord);


}

void favChange(HashTable*& dict, string w, bool flag) {

	WordList* tmp = wordSearch(dict, w);

	tmp->info.fav = flag;


}

void editWord(HashTable*& dict,string & tmp)
{
	WordList* tmpWord = wordSearch(dict, tmp);
	if (tmpWord == NULL)
	{
		cout << "No words matches the word you entered" << endl;
		return;
	}
	else
	{
		tmpWord->info.type.clear();
		tmpWord->info.def.clear();
		cout << "How many word types does your word have? ";
		int tCount; cin >> tCount;

		for (int i = 0; i < tCount; i++) {
			cout << i + 1 << endl;
			cout << "What is your word type? " << endl;
			cout << "1. noun     2. verb     3. adjective     4. adverb" << endl;
			cout << "Your choice (enter the number correspond with the word type): ";
			int n; cin >> n;
			while (n < 1 || n > 4)
			{
				cout << "Invalid choice, choose again: ";
				cin >> n;
			}
			if (n == 1) tmpWord->info.type.push_back("n");
			if (n == 2) tmpWord->info.type.push_back("v");
			if (n == 3) tmpWord->info.type.push_back("adj");
			if (n == 4) tmpWord->info.type.push_back("adv");
			string d = "";
			cout << "Enter the definition: ";
			cin.ignore(1000, '\n');
			getline(cin, d, '\n');
			tmpWord->info.def.push_back(d);
		}

	}

}

void printWord(WordInfo w) {
	cout << w.word << endl;
	if (w.type.size() == 1) cout << " (" << w.type[0] << "): " << w.def[0] << endl;
	else {
		for (int i = 0; i < w.type.size(); i++)
			cout << " (" << w.type[i] << "): " << w.def[i] << endl;
	}
}

void printFav() {

	string s;
	WordInfo tmp;

	ifstream fin("favorite.txt");

	while (getline(fin, s)) {
		if (s == "") continue;
		if ((int(s[0]) < 48) || (int(s[0]) > 57)) continue;
		else {
			tmp = Trans(s);
			
			printWord(tmp);
		}
	}

	fin.close();
}