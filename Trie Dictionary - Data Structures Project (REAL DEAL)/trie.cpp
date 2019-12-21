#include "Trie.h"
#include <algorithm>

string toLower(string s) {
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	return s;
}

Node::Node()
{
	for (int i = 0; i < SIZE; i++)
	{
		children[i] = NULL;
	}
	endOfWord = false;
}

Node::Node(Node* point, int i) {
    for (int i = 0; i < SIZE; i++)
    {
        children[i] = NULL;
    }
    endOfWord = false;
    parent = point;
    index = i;
}

Trie::Trie()
{
	root = new Node;
	size = 0;
}

Trie::Trie(string s)
{
	root = NULL;
	size = 0;
	ifstream mystream;
	string toInsert;
	mystream.open(s.c_str());
	while (!mystream.eof())
	{
		mystream >> toInsert;
		insert(toLower(toInsert));
	}
	mystream.close();
}

void Trie::load(string s)
{
	clear();
	ifstream mystream;
	string toInsert;
	mystream.open(s.c_str());
	while (!mystream.eof())
	{
		mystream >> toInsert;
		insert(toInsert);
	}
	mystream.close();
}

bool Trie::insert(const string& s)
{
	if (root == NULL)
	{
		root = new Node;
		root->occurrences = 0;
	}
	Node* toTraverse = root;
	traverse(toTraverse, s, true);
	if (toTraverse->endOfWord)
		return false;
	toTraverse->endOfWord = true;
	size++;
	toTraverse->occurrences++;
	return true;
}

bool Trie::contains(const string& s)
{
	if (root == NULL)
		return false;
	Node* toTraverse = root;
	if (!traverse(toTraverse, s))
		return false;
	return (toTraverse->endOfWord);
}

bool Trie::remove(const string& s)
{
	if (root == NULL)
		return false;
	Node* toTraverse = root;
	if (!traverse(toTraverse, s))
		return false;
	toTraverse->endOfWord = false;
	return true;
}

void Trie::clear()
{
	clear(root);
	size = 0;
}

void Trie::print()
{
	if (root)
	{
		cout << "Starting at root...\n";

		print(root);
	}
	else
		cout << "No words exist in this dictionary\n";
}

void Trie::print(Node* node) {
	if (node->occurrences > 0)
	{
		for (vector<char>::iterator it = charsInWord.begin(); it != charsInWord.end(); it++)
		{
			cout << *it;
		}

		cout << "\n";
	}
	for (int i = 0; i < SIZE; i++)
	{
		if (node->children[i])
		{
			charsInWord.push_back(i);
			print(node->children[i]);
			charsInWord.pop_back();
		}
	}
}


void Trie::clear(Node* root)
{
	for (int i = 0; i < SIZE; i++)
	{
		if (root->children[i] != NULL)
			clear(root->children[i]);
	}
	delete root;
}

int Trie::numWords()
{
	return size;
}

int Trie::countNodes()
{
	return countNodes(root);
}

int Trie::countNodes(Node* root)
{
	int count = 1;
	for (int i = 0; i < SIZE; i++)
	{
		if (root->children[i] != NULL)
		{
			count += countNodes(root->children[i]);
		}
	}
	return count;
}

bool Trie::traverse(Node*& root, const string& s, bool create)
{
	for (int i = 0; i < s.length(); i++)
	{
		int index = s[i] - 'a';
		if (root->children[index] == NULL)
		{
			if (create)
				root->children[index] = new Node(root, index);
			else
				return false;
		}
		root = root->children[index];
	}
	return true;
}

Node* Trie::getNode(string s) {
	Node* toGet = root;
	for (int i = 0; i < s.length(); ++i) {
		int index = s[i] - 'a';
		toGet = toGet->children[index];
		if (!toGet) return nullptr;
	}
	return toGet;
}