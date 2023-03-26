#include <iostream>
#include "AutoComplText.h"


Trie::TrieNode* Trie::getNewNode(void)
{

    TrieNode* pNode = new TrieNode;
    pNode->isEndOfWord = false;
    pNode->count = 1;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = nullptr;

    return pNode;
}


void Trie::insert(std::string& key)
{
    TrieNode* node = root;                       // node - указатель для движения по дереву

    for (int i = 0; i < key.length(); i++)
    {

        int index = key[i] - 'a';

        if (!node->children[index])
            node->children[index] = getNewNode();
        else
            (node->children[index]->count)++;

        node = node->children[index];
    }

    node->isEndOfWord = true;
}


bool::Trie:: search(std::string& key)
{
    TrieNode* node = root;                         // node - указатель для движения по дереву

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!node->children[index])
            return false;

        node = node->children[index];
    }

    return (node != nullptr && node->isEndOfWord);
}


bool Trie::isEmpty(TrieNode* root)
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i])
            return false;
    return true;
}


Trie::TrieNode* Trie::remove(TrieNode* root, std::string key, int depth)
{

    if (!root)
        return nullptr;

    if (depth == key.size()) {


        if (root->isEndOfWord)
            root->isEndOfWord = false;

        if (isEmpty(root)) {
            delete (root);
            root = nullptr;
        }

        return root;
    }

    int index = key[depth] - 'a';
    root->children[index] = remove(root->children[index], key, depth + 1);

    if (isEmpty(root) && root->isEndOfWord == false) {
        delete (root);
        root = nullptr;
    }

    return root;
}


void Trie::findMinPrefixes(TrieNode* root, char buf[], int ind, std::string& res) 
{

    if (root == nullptr)
        return;

    if (root->count == 1 and ind)
    {
        buf[ind] = '\0';        
        res += buf;
        res += " ";
        std::cout << res << " ";
        return;
    }

    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if (root->children[i] != nullptr)
        {
            buf[ind] = 'a' + i;

            findMinPrefixes(root->children[i], buf, ind + 1, res);
        }
    }
}

void Trie:: findPrefixes(std::string arr[], int n) 
{
    const int size = 200;
    char buf[size];
    TrieNode* root = getNewNode();
    //root->count = 0;
    for (int i = 0; i < n; i++)
        insert(arr[i]);
    std::string str;
    findMinPrefixes(root, buf, 0, str);
   
}

void Trie::showPOSTunicPrefix(std::string& key, int Ind)
{    
    TrieNode* node = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!node->children[index])
            return;
        
        node = node->children[index];
        Ind++;   // подумать убрать с первым ноудом не пройдёт (return)
    }   

    while (node->count == 1 and node->isEndOfWord == false)
    {      
        
        for (int i = 0; i < ALPHABET_SIZE; i++)
        {           

            if (!node->children[i])
                continue;

            if (node->children[i]->count == 1)
            {
                node = node->children[i];
                std::cout << char(i + 'a');
                break;
            }
            else {
                Ind = 0;
                break;
            }
        }       
    }   
}

Trie::TrieNode* Trie::complitWordBook(std::string arr [], int n)
{   
                                                   
    for (int i = 0; i < n; i++)       
        insert(arr[i]);
    return root;

}

void Trie::showPREunicPrefix(std::string& key)
{
    TrieNode* node = root;                     

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!node->children[index])
            return;

        node = node->children[index];

    }

    while (node->count > 1 and node->isEndOfWord == false)
    {
        int i = 0;

        for (; i < ALPHABET_SIZE; i++)
        {

            if (!node->children[i])
                continue;


            if (node->children[i]->count > 1)
            {
                node = node->children[i];
                std::cout << char(i + 'a');
                break;
            }
            else {
                //Ind = 0;
                break;
            }
        }
        if (node->children[i])
        {
            if (!(node->children[i]->count > 1))
                break;
        }

    }
}

void Trie::findAllWordsByPrefix(std::string& key)
{
    TrieNode* node2 = root;                   // root - остается на месте, node2 двигаем по дереву
    int start_index(0);
    for (int i = 0; i < key.length(); i++)    // переход к последнему символу key в дереве
    {
        int index = key[i] - 'a';
        if (!node2->children[index])
            return;        
        node2 = node2->children[index];
        start_index = index;
    }    

    int numb_word = node2->count;                // определяем количество слов соответсвующее key

    while (numb_word)                            // печатаем начало каждого слова
    {
        TrieNode* node = root;

        for (int i = 0; i < key.length(); i++)
        {
            int index = key[i] - 'a';
            if (!node->children[index])
                return;
            std::cout << char(index + 'a');
            node = node->children[index];           
        }

        int word_size = WORD_SIZE;  //  максимальный размер любого слова в словаре
        while (word_size)
        {
            for (int i = 0; i < ALPHABET_SIZE; i++)
            {
                if (node->children[i] != nullptr and node->children[i]->count) // проходим по каждому слову 
                {
                    std::cout << char(i + 'a');
                    if (!node->isEndOfWord)
                        node->count--;
                    node = node->children[i];

                    for (int i = 0; i < ALPHABET_SIZE; i++)
                    {
                        if (node->children[i] != nullptr and (node->isEndOfWord))
                        {
                            node->count--;
                            break;
                        }
                        else  if (node->isEndOfWord)
                        {
                            node->count--;
                            break;
                        }
                    }
                }
            }            
            word_size--;
        }
        std::cout << " ";
        numb_word--;
    }
}