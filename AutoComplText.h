#pragma once
#include <iostream>
#include <string>



const int ALPHABET_SIZE = 26;
const int WORD_SIZE = 10;

class Trie
{
public:
struct TrieNode
{
    TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord; 
    int count = 0;
    bool pass = false;

};
Trie() {};
~Trie() {
    if (root != nullptr) { delete root; root = nullptr; }
}

TrieNode* getNewNode(void);
void insert(std::string&);
bool search(std::string&);
bool isEmpty(TrieNode*);
TrieNode* remove(TrieNode*, std::string, int depth = 0);
void findMinPrefixes(TrieNode*, char[], int, std::string&);
void findPrefixes(std::string arr[], int n);
void showPOSTunicPrefix(std::string&, int = 0);
TrieNode* complitWordBook(std::string[], int);
void showPREunicPrefix(std::string& key);
void findAllWordsByPrefix(std::string& key);

private:
    TrieNode* root = getNewNode();
};