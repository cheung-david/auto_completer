#include "Trie.h"
#include <iostream>
#include <fstream>


using namespace std;


int main(int argc, char **argv)
{
    Trie* trie = new Trie();

    trie->addWord("Testing");
    trie->addWord("Ball");
    trie->addWord("David");
    trie->addWord("Dragon");
    trie->addWord("Duck");


        cout << trie->findWord("Random") << endl;

        cout << trie->findWord("Davidd") << endl;

        cout << trie->findWord("Test") << endl;


        // Valid
        cout << trie->findWord("Testing") << endl;

        // Valid
        cout << trie->findWord("David") << endl;

        // Valid
        cout << trie->findWord("Ball") << endl;

        trie->deleteWord("Testing");

        cout << trie->findWord("Testing") << endl;


    delete trie;
}
