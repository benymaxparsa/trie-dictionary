//#pragma once
#ifndef Dictionary_h
#define Dictionary_h

#include "Trie.h"
#include <iostream>

class Dictionary : public Trie {
private:
	Trie dictionary;
public:
	Dictionary() {
	}
	Dictionary(string file) : dictionary(Trie(file)) {
	}
	~Dictionary() {
		dictionary.clear();
	}

	void load(string file);
	bool isLegalWord(string word);
	int numWords();
	void print();
};

#endif
