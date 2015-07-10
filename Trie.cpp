// Prefix Tree (trie)
// Autocomplete - Displays all words related to the given prefix
// By David Cheung

#include "Trie.h"

using namespace std;

Node::Node(const string& wordSoFar="")
{
	content = wordSoFar;
	endWord = false;
}
Node::~Node()
{
	// Default Destructor
}

string Node::peekContent()
{
	return content;
}

void Node::setContent(char c)
{
    if (content == "")
	{
        content = string(1, c);
    }
	else
	{
        content = content + string(1,c);
	}
}

bool Node::isWord()
{
	return endWord;
}

void Node::setWord(bool state)
{
	endWord = state;
}

// Append new node to given child
void Node::appendChild(char c, Node* child)
{
	children.insert(std::pair<char, Node*>(c, child));
}

map<char, Node*> Node::getChildren()
{
	return children;
}


Trie::Trie()
{
	root = new Node();
}

Trie::~Trie()
{
	delete root;
}


void Trie::addWord(const string& word)
{
	Node* current = root;

	// Empty string
	if(word.size() == 0)
	{
		current->setWord(true);
		return;
	}
    unsigned i;
	// Traverse tree
	for (i = 0; i < word.size(); i++)
	{
        map<char, Node*> child = current->getChildren();
		// Character not present in tree
		if(child.find(word[i]) == child.end())
		{
			Node* temp = new Node(current->peekContent());
			temp->setContent(word[i]);
			current->appendChild(word[i],temp);
			current = temp;
		}
		else // Character found
		{
			current = child[word[i]];
		}
	}
        // Word added
		current->setWord(true);
	return;
}


string Trie::findWord(const string& word)
{
	Node* current = root;
	// Traverse tree
	for(unsigned i = 0; i < word.size(); ++i)
	{
        map<char, Node*> children = current->getChildren();
		if(children.find(word[i]) == children.end()) // Character not found
		{
			return ""; // Empty string
		}
		else
		{
		    //cout << current->isWord() << " " << i << endl;
			current = children[word[i]]; // Access character Node* element
		}
	}

	if(current->isWord() == true)
    {
      	string temp = current->peekContent();
        return temp;
    }
    else
    {
        //cout << current->isWord();
        return "";
    }
}


void Trie::deleteWord(const string& word)
{
    	Node* current = root;
	// Traverse tree
	for(unsigned i = 0; i < word.size(); ++i)
	{
        map<char, Node*> children = current->getChildren();
		if(children.find(word[i]) == children.end()) // Character not found
		{
			return; // Empty string
		}
		else
		{
		    //cout << current->isWord() << " " << i << endl;
			current = children[word[i]]; // Access character Node* element
		}
	}

	current->setWord(false);
	return;
}
