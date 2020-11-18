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
        allWord.push_back(beginWord);

        for (string word : wordList)
        {
            if (word != beginWord && word != endWord)
            {
                allWord.push_back(word);
            }
        }
        allWord.push_back(endWord);

        vector<vector<string>> result;

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
        int minLen = 65535;
        FindPath(dataTree, result, beginWord, endWord, tempVec, minLen);

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
                  string &endWord, vector<string> &tempVec)
    {
        if (beginWord == endWord)
        {
            result.push_back(tempVec);
            return;
        }
        if (dataTree.find(beginWord) != dataTree.end())
        {
            for (pair<string, bool> data : dataTree[beginWord])
            {   
                if(data.second == false){
                    data.second = true;
                    tempVec.push_back(data.first);
                    FindPath(dataTree, result, data.first, endWord, tempVec);
                    tempVec.pop_back();
                    data.second = false;
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

    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "cog", "dot", "dog", "hit", "lot", "log"};
    vector<vector<string>> result = solution.findLadders(beginWord, endWord, wordList);
    return 0;
}