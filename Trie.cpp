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

}

bool Node::isWord()
{
	return endWord;
}

void Node::setWord()
{
	endWord = true;
}

// Append new node to given child
void Node::appendChild(char c, Node* child)
{

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

string Trie::findWord(const string& word)
{

}


void Trie::addWord(const string& word)
{

}

void Trie::deleteWord(const string& word)
{

}
