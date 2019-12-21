#include <iostream>
#include "Dictionary.h"

int main() {
	Dictionary dic("words.txt");

	int num = dic.numWords();
	bool avl = dic.isLegalWord("hector");
	//dic.print();

	cout << num << "   " << avl << endl;

	return 0;
}