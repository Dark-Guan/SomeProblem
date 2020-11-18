/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */
#include <iostream>
#include <string>

using namespace std;
// @lc code=start

const int TRIE_CHILD_LEN = 26;

struct TrieData
{
    char data;
    bool isWord{false};
    TrieData *next[TRIE_CHILD_LEN];
    TrieData()
    {
        for (int i = 0; i < TRIE_CHILD_LEN; i++)
        {
            next[i] = nullptr;
        }
    }

    ~TrieData()
    {
        for (int i = 0; i < TRIE_CHILD_LEN; i++)
        {
            delete next[i];
        }
    }
};

class Trie
{
public:
    /** Initialize your data structure here. */
    Trie()
    {
        
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        char head = word[0];
        if (this->trie[GetTireIndex(head)] == nullptr)
        {
            this->trie[GetTireIndex(head)] = new TrieData();
            this->trie[GetTireIndex(head)]->data = head;
        }

        TrieData *tempTire = this->trie[GetTireIndex(head)];
        for (int i = 1; i < word.size(); i++)
        {
            if (tempTire->next[GetTireIndex(word[i])] == nullptr)
            {
                tempTire->next[GetTireIndex(word[i])] = new TrieData();
                tempTire = tempTire->next[GetTireIndex(word[i])];
                tempTire->data = word[i];
            }
            else
            {
                tempTire = tempTire->next[GetTireIndex(word[i])];
            }
        }
        tempTire->isWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {   
        if(this->trie == nullptr){
            return false;
        }

        char head = word[0];
        if (this->trie[GetTireIndex(head)] == nullptr)
        {
            return false;
        }

        TrieData *tempTire = this->trie[GetTireIndex(head)];
        for (int i = 1; i < word.size(); i++)
        {
            if (tempTire->next[GetTireIndex(word[i])] == nullptr)
            {
                return false;
            }
            else
            {
                tempTire = tempTire->next[GetTireIndex(word[i])];
            }
        }
        if (tempTire->isWord){
            return true;
        }
        return false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        if(this->trie == nullptr){
            return false;
        }
        
        char head = prefix[0];
        if (this->trie[GetTireIndex(head)] == nullptr)
        {
            return false;
        }

        TrieData *tempTire = this->trie[GetTireIndex(head)];
        for (int i = 1; i < prefix.size(); i++)
        {
            if (tempTire->next[GetTireIndex(prefix[i])] == nullptr)
            {
                return false;
            }
            else
            {
                tempTire = tempTire->next[GetTireIndex(prefix[i])];
            }
        }
        return true;
    }

    ~Trie()
    {
        for (int i = 0; i < TRIE_CHILD_LEN; i++)
        {
            delete this->trie[i];
        }
    }

private:
    TrieData *trie[TRIE_CHILD_LEN]{0};

    int GetTireIndex(char ch)
    {
        return ch - 'a';
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

int main()
{
    Trie trie;
    trie.insert("app");
    trie.insert("apple");
    cout << trie.search("apple") << endl;   // 返回 true
    cout << trie.search("a") << endl;   // 返回 true
    cout << trie.search("app") << endl;     // 返回 false
    cout << trie.startsWith("app") << endl; // 返回 true
    trie.insert("app");
    cout << trie.search("app") << endl; // 返回 true

    // cout << trie.search("a") << endl;


    return 0;
}
