#include "mainFunc.h"

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
	} else if (wordCheck(H->info.word, w) == true) {
		if (H->right == NULL) {
			H = NULL;
			T = NULL;		
		}

		H = H->right;
		H->left = NULL;
	} else if (wordCheck(T->info.word, w) == true) {
		T = T->left;
		T->right = NULL;
	} else {
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


void editWord(HashTable*& dict)
{
	string tmp;
	cout << "Enter the word you want to edit: ";
	getline(cin, tmp);
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
			cout << "Enter the definition: ";;
			cin.ignore(1000, '\n');
			getline(cin, d, '\n');
			tmpWord->info.def.push_back(d);
		}

	}

}