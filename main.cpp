// Demonstration of autocompletion using the Trie class.
// By David Cheung

#include "Trie.h"
#include "test.h"
#include <iostream>
#include <fstream>


using namespace std;


int main(int argc, char **argv)
{
    test();
    // Open input file stream
    ifstream wordList("wordlist.txt", ifstream::in);
    Trie* trie = new Trie();

    string strBuff;

    // Read in file of default words
    while(getline(wordList, strBuff))
    {
        trie->addWord(strBuff);
    }

    cout << "Enter prefix and press enter: " << endl;
    cin >> strBuff;

        // Display all words starting with prefix
        vector<string> test = trie->autocomplete(strBuff);
        for(unsigned i = 0; i < test.size(); i++)
        {
            cout << test[i] << endl;
        }

    delete trie;
}
