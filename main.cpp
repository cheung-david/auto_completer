// Demonstration of autocompletion using the Trie class.
// By David Cheung

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

        // Invalid
        cout << trie->findWord("Random") << endl;

        // Invalid
        cout << trie->findWord("Davidd") << endl;

        // Invalid
        cout << trie->findWord("Test") << endl;


        // Valid
        cout << trie->findWord("Testing") << endl;

        // Valid
        cout << trie->findWord("David") << endl;

        // Valid
        cout << trie->findWord("Ball") << endl;

        trie->deleteWord("Testing");

        cout << trie->findWord("Testing") << endl;

        // Display all words starting with D
        vector<string> test = trie->autocomplete("D");
        for(unsigned i = 0; i < test.size(); i++)
        {
            cout << test[i] << endl;
        }

    delete trie;
}
