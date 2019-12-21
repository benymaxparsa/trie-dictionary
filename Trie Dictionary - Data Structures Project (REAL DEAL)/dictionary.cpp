#include "Dictionary.h"

void Dictionary::load(string file) {
    dictionary.clear();
    dictionary = Trie(file);
}

bool Dictionary::isLegalWord(string word) {
    return dictionary.contains(word);
}

int Dictionary::numWords() {
    return dictionary.numWords();
}

void Dictionary::print()
{
    dictionary.print();
}
