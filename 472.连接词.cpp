/*
 * @lc app=leetcode.cn id=472 lang=cpp
 *
 * [472] 连接词
 */
#include <string>
#include <vector>

using namespace std;

// @lc code=start
bool stringCompare(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

class TireNode
{
public:
    TireNode()
    {
        memset(next, 0, sizeof(TireNode *) * 26);
        isEnd = false;
    }

    bool isEnd;
    TireNode *next[26];
};

class Tire
{
public:
    Tire()
    {
        root = new TireNode;
    }

    void insert(string &word)
    {
        TireNode *current = root;
        for (char c : word)
        {
            int index = c - 'a';
            if (current->next[index] == NULL)
            {
                current->next[index] = new TireNode;
            }
            current = current->next[index];
        }

        current->isEnd = true;
    }

    bool isConcatenatedWord(string &word)
    {
        vector<bool> visited(word.size(), false);

        return DFS(word, 0, visited);
    }

    bool DFS(string &work, int start, vector<bool> &visited)
    {
        int i, size = work.size();
        TireNode *current = root;

        if (start == size)
        {
            return true;
        }

        if (visited[start])
        {
            return false;
        }

        for (i = start; i < size; i++)
        {
            int index = work[i] - 'a';
            if (current->next[index] == nullptr)
            {
                break;
            }

            current = current->next[index];
            if (current->isEnd)
            {
                if (DFS(work, i + 1, visited))
                {
                    return true;
                }
            }
        }

        visited[start] = true;
        return false;
    }

    TireNode *root;
};

class Solution
{
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
    {
        vector<string> concatenatedWorks;
        Tire tire;
        sort(words.begin(), words.end(), stringCompare);

        auto iter = words.begin();
        if (*iter == "")
        {
            iter++;
        }

        for (; iter != words.end(); iter++)
        {
            if (tire.isConcatenatedWord(*iter))
            {
                concatenatedWorks.push_back(*iter);
            }
            tire.insert(*iter);
        }
        return concatenatedWorks;
    }
};
// @lc code=end

int main(int argc, char **args)
{

    Solution s;
    vector<string> strs = {"cat", "cats", "catsdogcats", "dog", "dogcatsdog", "hippopotamuses", "rat", "ratcatdogcat"};
    vector<string> result = s.findAllConcatenatedWordsInADict(strs);
    return 0;
}