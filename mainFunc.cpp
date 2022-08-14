#include "mainFunc.h"

WordList* wordSearch(HashTable* dict, string inp) {
	
	int key = int(inp[0]) - 97;
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