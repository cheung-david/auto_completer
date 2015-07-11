// Prefix Tree (trie)
// Autocomplete - Displays all words related to the given prefix
// By David Cheung

#include <map>
#include <string>
#include <iostream>
#include <vector>

// Trie Node
class Node{
public:
	// Constructors/destructor
	Node(const std::string& wordSoFar);
	~Node();

	// Getters and setters
	std::string peekContent();
	void setContent(char c);
	void setWord(bool state);
	bool isWord();
	void appendChild(char c, Node* child);

	std::map<char, Node*> getChildren();

private:
	std::string content;
	bool endWord;
	std::map<char, Node*> children;
};

class Trie{
public:
	// Constructors/destructor
	Trie();
	~Trie();

	// Member functions
	void addWord(const std::string& word);
    std::string findWord(const std::string& word);
	void deleteWord(const std::string& word);
	std::vector<std::string> nodesAfterPrefix(Node* current);
    std::vector<std::string> autocomplete(const std::string& prefix);

private:
	Node* root;
};


