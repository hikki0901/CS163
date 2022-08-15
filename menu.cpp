#include "fileExe.h"
#include "mainFunc.h"
#include "menu.h"


void start(int& choice)
{
	system("cls");
	cout << "CS163 - Dictionary - Group 12" << endl;
	cout << "1. Search for a word    2. Add new words" << endl;
	cout << "3. Reset the data       4. View the favorite list" << endl;
	cin >> choice;
}



void searchMenu(HashTable* dict)
{
	int choice;
	system("cls");
	cout << "Enter the word you want to search: ";
	string tmp;
	cin.ignore(1000, '\n');
	getline(cin, tmp);
	while (wordSearch(dict, tmp) == NULL)
	{
		system("cls");
		cout << "No words matches the word you search" << endl;
		cout << "1. Enter again     2. Return to menu" << endl;
		cin >> choice;
		while (choice > 2 || choice < 1)
		{
			system("cls");
			cout << "No words matches the word you search" << endl;
			cout << "1. Enter again     2. Return to menu" << endl;
			cin >> choice;
		}
		if (choice == 1) return searchMenu(dict);
		else
		{
			return;
		}
	}
	WordList* tmpWord = wordSearch(dict, tmp);
	choice = 0;
	do
	{
		system("cls");
		printWord(tmpWord->info);
		cout << "1. Edit the word                   2. Delete the word" << endl;
		if (tmpWord->info.fav == true)
			cout << "3. Remove from favorite list       4. Return to menu" << endl;
		else cout << "3. Add to favorite list            4. Return to menu" << endl;
		cin >> choice;
	} while (choice < 1 || choice > 4);
	if (choice == 1)
	{
		editWord(dict, tmpWord->info.word);
		cout << "Edit the word sucessfully" << endl;
		system("pause");

	}
	if (choice == 2)
	{
		wordDelete(dict, tmpWord);
		cout << "Delete the word sucessfully" << endl;
		system("pause");

	}
	if (choice == 3)
	{
		if (tmpWord->info.fav == true)
		{
			favChange(dict, tmpWord->info.word, false);
			cout << "Remove the word from favorite list successfully" << endl;
		}
		else
		{
			favChange(dict, tmpWord->info.word, true);
			cout << "Add the word to favorite list successfully" << endl;
		}
		system("pause");

	}


}

void Menu(HashTable* dict)
{
	system("cls");
	int choice = 0;
	do
	{
		start(choice);
	} while (choice < 1 || choice > 4);
	if (choice == 1)
	{
		searchMenu(dict);
		return Menu(dict);
	}
	if (choice == 2)
	{
		addWord(dict);
		system("pause");
		return Menu(dict);
	}
	if (choice == 3)
	{
		dataReset(dict);
		cout << "Dictionary successfully reset" << endl;
		system("pause");
		return Menu(dict);
	}
	if (choice == 4)
	{
		system("cls");
		printFav();
		system("pause");
		return Menu(dict);
	}
}