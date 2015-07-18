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
        cout << "Prefix Tree - Autocompletion" << endl;
        cout << "Enter a command (without quotations) followed by the word." << endl << endl;
        cout << "Enter \"?\" to see all commands: ";
        while(strBuff != "q")
        {
            cin >> strBuff;
            cout << endl;
            if(strBuff == "?")
            {
                cout << "Commands: \"add\" to add a word, \"delete\" to delete a word " << endl;
                cout << " \"nodes\" to see the number of words in the list or" << endl;
                cout << "\"prefix\" to find all possible autocompletions for the given prefix." << endl;
                cout << "\"q\" to quit." << endl << endl;
            }
            else if(strBuff == "add")
            {
                cin >> strBuff;
                trie->addWord(strBuff);
                cout << "Added.";
            }
            else if(strBuff == "delete")
            {
                cin >> strBuff;
                trie->deleteWord(strBuff);
                cout << "Deleted.";
            }
            else if(strBuff == "prefix")
            {
                cin >> strBuff;

                // Display all words starting with prefix
                vector<string> defaultList = trie->autocomplete(strBuff);
                if(defaultList.size() == 0)
                    cout << "No matching prefix" << endl;

                for(unsigned i = 0; i < defaultList.size(); i++)
                {
                    cout << defaultList[i] << endl;
                }
            }
            else if(strBuff == "nodes")
            {
                cout << "Number of nodes: " << trie->getNodes() << endl;
            }
            else
            {
                cout << "Invalid command entered. Try again." << endl;
            }
            cout << endl;
        }



    delete trie;
}
