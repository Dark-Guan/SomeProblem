/*
 * @lc app=leetcode.cn id=126 lang=cpp
 *
 * [126] 单词接龙 II
 */
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;
// @lc code=start
class Solution
{
    // node 精髓就是存储index 而不是 string， 用map来查询index；用index和map加速；
    unordered_map<string, int> inWordList;
    vector<string> idWord;
    vector<vector<int>> graph;

    const int INF = 1 << 20;

public:
    vector<vector<string>> findLadders(string beginWord,
                                       string endWord,
                                       vector<string> &wordList)
    {
        vector<vector<string>> result;
        // 把数据放入到map中
        int id = 0;

        for (string word : wordList)
        {
            if (!inWordList.count(word))
            {
                inWordList[word] = id;
                id++;
                idWord.push_back(word);
            }
        }
        if (!inWordList.count(endWord))
        {
            return result;
        }
        if (!inWordList.count(beginWord))
        {
            inWordList[beginWord] = id;
            id++;
            idWord.push_back(beginWord);
        }

        // build graph
        graph.resize(idWord.size());
        for (int i = 0; i < idWord.size(); i++)
        {
            for (int j = i + 1; j < idWord.size(); j++)
            {
                if (IsWordNear(idWord[i], idWord[j]))
                {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        const int dest = inWordList[endWord]; // the end point
        queue<vector<int>> qPath;
        vector<int> cost(id, INF);
        qPath.push(vector<int>{inWordList[beginWord]});
        cost[inWordList[beginWord]] = 0; 
        while (!qPath.empty())
        {
            vector<int> now = qPath.front();
            qPath.pop();
            int last = now.back();
            if (last == dest)
            {
                vector<string> temp;
                for (int index : now)
                {
                    temp.push_back(idWord[index]);
                }
                result.push_back(temp);
            }
            else
            {
                for (int i = 0; i < graph[last].size(); i++)
                {
                    int to = graph[last][i];
                    if (cost[last] + 1 <= cost[to])
                    {
                        cost[to] = cost[last] + 1;
                        vector<int> temp(now);
                        temp.push_back(to);
                        qPath.push(temp);
                    }
                }
            }
        }
        return result;
    }

private:
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
    /*
    */
    Solution solution;
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    //   [
    //   ["hit","hot","dot","dog","cog"],
    //   ["hit","hot","lot","log","cog"]
    //   ]
    vector<vector<string>> result = solution.findLadders(beginWord, endWord, wordList);
    
    /*
    Solution solution;
    string beginWord = "hot";
    string endWord = "dog";
    vector<string> swordList = {"hot", "dog", "dot"};
    result = solution.findLadders(beginWord, endWord, wordList);
    // []

    Solution solution;
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "cog", "dot", "dog", "hit", "lot", "log"};
    vector<vector<string>>  result = solution.findLadders(beginWord, endWord, wordList);

    Solution solution;
    string beginWord = "qa";
    string endWord = "sq";
    vector<string>  wordList = {"si", "go", "se", "cm", "so", "ph", "mt", "db", "mb", "sb", "kr", "ln", "tm", "le", "av", "sm", "ar", "ci", "ca", "br", "ti", "ba", "to", "ra", "fa", "yo", "ow", "sn", "ya", "cr", "po", "fe", "ho", "ma", "re", "or", "rn", "au", "ur", "rh", "sr", "tc", "lt", "lo", "as", "fr", "nb", "yb", "if", "pb", "ge", "th", "pm", "rb", "sh", "co", "ga", "li", "ha", "hz", "no", "bi", "di", "hi", "qa", "pi", "os", "uh", "wm", "an", "me", "mo", "na", "la", "st", "er", "sc", "ne", "mn", "mi", "am", "ex", "pt", "io", "be", "fm", "ta", "tb", "ni", "mr", "pa", "he", "lr", "sq", "ye"};
    vector<vector<string>>  result = solution.findLadders(beginWord, endWord, wordList);
    */
    return 0;
}

/*
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

*/