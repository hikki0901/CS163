
#include "mainStruct.h"
#include "WordAdjustment.h"
#include <iostream>
#include <string>
#include <fstream>
#include <Bits.h>


using namespace std;









void addWord(HashTable*& hash)
{
	WordInfo tmp;
	int choice;
	cout << "insert word: " << endl;
	cin >> tmp.word;
	// if (check = true);
	{
		cout << "This word already exist, do you want to change its definition?" << endl;
		cout << "1: Yes         2: No" << endl;
		cin >> choice;
		while (choice < 1 || choice >2)
		{
			cout << "Invalid choice. Try again: " << endl;
			cin >> choice;
		}
		if (choice == 1)
		{
			//fix
		}
		else 
		{
			//return menu;
		}
		
	}
	// else
	{
		add(tmp, hash);
	}
	
}


void add(WordInfo& tmp, HashTable*& hash)
{
	string def;
	int choice;
	cout << "Enter the meaning: " << endl;
	cin >> def;
	cout << "Confirm? " << endl;
	cout << "1.Yes           2.No" << endl;
	cin >> choice;
	while (choice < 1 || choice >2)
	{
		cout << "Invalid choice. Try again: " << endl;
		cin >> choice;
	}
	if (choice == 1)
	{
		tmp.def = def;
		tmp.addition = 1;

		//insert
		saveNewWord(tmp);
	}
	else
	{
		return;
	}

}



void saveNewWord(WordInfo tmp)
{
	int id = 0;
	ifstream fin;
	fin.open("addition.txt");
	while (!fin.eof())
	{
		id++;
		fin.ignore(10000, '\n');
	}
	fin.close();
	ofstream fout;
	fout.open("addition.txt", ios::app);
	tmp.ID = id;
	fout << tmp.ID << " " << tmp.word << "  " << tmp.def  << " " << tmp.addition << endl;
	fout.close();
	
}


void fix(WordInfo& tmp, HashTable*& hash)
{

}
	
bool check(string& def, HashTable*& hash)
{
	


}

string lower(string& a)
{
	string tmp;
	for (int i = 0; i < a.size(); i++)
	{
		tmp += char(tolower(a[i]));
	}
	return tmp;
}

WordInfo search(HashTable*& hash, string& def)
{
	string first, second;
	for (int i = 0; i < def.size(); i++)
	{
		if ((int(def[i]) >= 65 && int(def[i]) <= 90) || (int(def[i]) >= 97 && int(def[i]) <= 122))
		{
			first += def[i];
			break;
		}
	}
	Wordlist* tmpWord = hash[tolower(first[0]) - 97].head;



	
}


bool compare(Wordlist*& tmpWord, string& first, string& second)
{
	for (int i = 0; i < tmpWord->info.def.size(); i++)
	{
		if ((int(tmpWord->info.def[i]) >= 65 && int(tmpWord->info.def[i]) <= 90) || (int(tmpWord->info.def[i]) >= 97 && int(tmpWord->info.def[i]) <= 122))
		{
			second += tmpWord->info.def[i];
		}
	}

}