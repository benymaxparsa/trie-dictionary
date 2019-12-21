#include <iostream>
#include "Dictionary.h"

Dictionary dic("words.txt");

void app() {
	cout << " 1. load new Dic -- 2. number of words -- 3. show Dic -- 4. search -- 5. remove -- 6. insert -- 99. exit -- 88. restart " << endl;
	int toDo;
	cin >> toDo;

	switch (toDo)
	{
	case 1:
		dic.load("words.txt");
		app();
		break;
	case 2:
		cout << dic.numWords() << endl;
		app();
		break;
	case 3:
		dic.print();
		app();
		break;
	case 4: {
		cout << "enter your word..." << endl;
		string str4;
		cin >> str4;
		bool result = dic.isLegalWord(str4);
		if (result)
			cout << "word were found" << endl;
		else
			cout << "entered word were not found" << endl;
		app();
		break;
	}
	case 5: {
		cout << "enter your word..." << endl;
		string str1;
		cin >> str1;
		bool result1 = dic.remove(str1);
		if (result1)
			cout << "word were deleted" << endl;
		else
			cout << "entered word couldn't be deleted" << endl;
		app();
		break;
	}
	case 6: {
		cout << "enter your word..." << endl;
		string str2;
		cin >> str2;
		bool result2 = dic.insert(str2);
		if (result2)
			cout << "word were added" << endl;
		else
			cout << "entered word couldn't be added" << endl;
		app();
		break;
	}
	case 99:
		return;
	case 88:
		system("cls");
		app();
		break;
	default:
		cout << "undifined input" << endl;
		app();
		break;
	}
}

int main() {
	
	cout << "Trie Dictionary - Data Structures project by Parsa KamaliPour" << endl;
	app();
	
	
	//dic.print();

	//cout << num << "   " << avl << endl;

	return 0;
}