// Test function
// Test basic cases for class methods.
// By David Cheung

#include "test.h"

using namespace std;


void test()
{
    Trie* trie = new Trie();
    trie->addWord("Testing");
    trie->addWord("Ball");
    trie->addWord("David");
    trie->addWord("Dragon");
    trie->addWord("Duck");


        // Invalid
        assert(trie->findWord("Random") == "");

        assert(trie->findWord("Davidd") == "");

        assert(trie->findWord("Test") == "");

        // Valid
        assert(trie->findWord("Testing") == "Testing");

        assert(trie->findWord("David") == "David");

        assert(trie->findWord("Ball") == "Ball");

        trie->deleteWord("Testing");

        assert(trie->findWord("Testing") == "");

    delete trie;
}

