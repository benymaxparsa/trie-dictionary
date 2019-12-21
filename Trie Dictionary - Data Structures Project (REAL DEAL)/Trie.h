//#pragma once
#ifndef Trie_h
#define Trie_h

#include <fstream>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 26;            // number of char in this dictionary
struct Node                    // node 
{ 
	Node* parent;             // not used parent node
	Node* children[SIZE];     // make null children size of chars in every level for each node
	
	int occurrences;
	int index;               
	bool endOfWord;          // show that if this node is a compelete word

	Node();                       // node's constructor that makes 26 null childeren 
	Node(Node* point, int i);
};

class Trie {
private:
	Node* root;
	int size; // number of words in this trie
	vector<char> charsInWord;
	bool traverse(Node*& root, const string& s, bool create = false);
	int countNodes(Node* root);
	void clear(Node* root);
	Node* getNode(string s);

public:
	Trie();
	Trie(string s);
	void load(string s);
	bool insert(const string& s);
	bool contains(const string& s);
	bool remove(const string& s);
	void clear();
	void print();
	void print(Node* node);
	int numWords();
	int countNodes();
	~Trie() {
	}
};

#endif