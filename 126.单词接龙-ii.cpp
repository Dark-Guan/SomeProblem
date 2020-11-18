/*
 * @lc app=leetcode.cn id=126 lang=cpp
 *
 * [126] 单词接龙 II
 */
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<string>> findLadders(string beginWord,
                                       string endWord,
                                       vector<string> &wordList)
    {
        map<string, map<string, bool>> dataTree;
        vector<string> allWord;
        bool isEndWordFind = false;
        allWord.push_back(beginWord);

        for (string word : wordList)
        {
            if (word == endWord)
            {
                isEndWordFind = true;
            }

            if (word != beginWord && word != endWord)
            {
                allWord.push_back(word);
            }
        }
        allWord.push_back(endWord);

        vector<vector<string>> result;
        if (isEndWordFind == false)
        {
            return result;
        }
        // build data tree
        for (int i = 0; i < allWord.size(); i++)
        {
            for (int j = i + 1; j < allWord.size(); j++)
            {
                if (IsWordNear(allWord[i], allWord[j]))
                {
                    AddToMap(dataTree, allWord[i], allWord[j]);
                    AddToMap(dataTree, allWord[j], allWord[i]);
                }
            }
        }
        vector<string> tempVec;
        tempVec.push_back(beginWord);
        set<string> setForDup;

        int minLen = 65535;
        FindPath(dataTree, result, beginWord, endWord, tempVec, setForDup, minLen);

        // for (auto it = result.begin(); it != result.end(); it++)
        // {
        //     if (it->size() < minLen)
        //     {
        //         minLen = it->size();
        //     }
        // }
        // delete the len vector
        for (auto it = result.begin(); it != result.end();)
        {
            if (it->size() > minLen)
            {
                it = result.erase(it);
            }
            else
            {
                it++;
            }
        }
        return result;
    }

private:
    void FindPath(map<string, map<string, bool>> &dataTree,
                  vector<vector<string>> &result,
                  string &beginWord,
                  string &endWord, vector<string> &tempVec, set<string> &setForDup, int &minLen)
    {   
        if(tempVec.size() > minLen){
            return;
        }
        
        if (beginWord == endWord)
        {
            if(tempVec.size() < minLen){
                minLen = tempVec.size();
            }
            result.push_back(tempVec);
            return;
        }
        if (dataTree.find(beginWord) != dataTree.end())
        {
            for (pair<string, bool> data : dataTree[beginWord])
            {
                if (setForDup.find(data.first) == setForDup.end())
                {
                    setForDup.insert(data.first);
                    tempVec.push_back(data.first);
                    FindPath(dataTree, result, data.first, endWord, tempVec, setForDup, minLen);
                    tempVec.pop_back();
                    setForDup.erase(data.first);
                }
            }
        }
    }

    void AddToMap(map<string, map<string, bool>> &dataTree,
                  string src, string des)
    {
        if (dataTree.find(src) != dataTree.end())
        {
            dataTree[src].insert(make_pair(des, false));
        }
        else
        {
            map<string, bool> tempMap;
            tempMap.insert(make_pair(des, false));
            dataTree.insert(make_pair(src, tempMap));
        }
    }

    bool IsWordNear(string &src, string &dec)
    {
        int count = 0;
        for (int i = 0; i < src.size(); i++)
        {
            if (src[i] != dec[i])
            {
                count++;
                if (count > 1)
                {
                    return false;
                }
            }
        }
        if (count == 1)
        {
            return true;
        }
        return false;
    }
};
// @lc code=end

int main()
{
    Solution solution;
    // string beginWord = "hit";
    // string endWord = "cog";
    // vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    // vector<string> wordList = {"hot", "dot", "dog", "lot", "log", };

    // string beginWord = "hot";
    // string endWord = "dog";
    // vector<string> wordList = {"hot", "dog", "dot"};

    // string beginWord = "hit";
    // string endWord = "cog";
    // vector<string> wordList = {"hot", "cog", "dot", "dog", "hit", "lot", "log"};
    string beginWord = "qa";
    string endWord  = "sq";
    vector<string> wordList = {"si", "go", "se", "cm", "so", "ph", "mt", "db", "mb", "sb", "kr", "ln", "tm", "le", "av", "sm", "ar", "ci", "ca", "br", "ti", "ba", "to", "ra", "fa", "yo", "ow", "sn", "ya", "cr", "po", "fe", "ho", "ma", "re", "or", "rn", "au", "ur", "rh", "sr", "tc", "lt", "lo", "as", "fr", "nb", "yb", "if", "pb", "ge", "th", "pm", "rb", "sh", "co", "ga", "li", "ha", "hz", "no", "bi", "di", "hi", "qa", "pi", "os", "uh", "wm", "an", "me", "mo", "na", "la", "st", "er", "sc", "ne", "mn", "mi", "am", "ex", "pt", "io", "be", "fm", "ta", "tb", "ni", "mr", "pa", "he", "lr", "sq", "ye" };
    vector<vector<string>> result = solution.findLadders(beginWord, endWord, wordList);
    return 0;
}
