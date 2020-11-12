/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int maxLen = 0;
        string max = {};
        string temp = {};
        int index = 0;
        while (head != s.size() && rear != s.size())
        {
            index = temp.find(s[rear]);
            if (index != s.npos)
            {
                if (temp.length() > max.length())
                {
                    max = temp;
                }
                head++;
                rear = head;
                temp.clear();
            }
            else
            {
                temp.push_back(s[rear]);
                rear++;
            }
        }

        if (temp.length() > max.length())
        {
            max = temp;
        }

        return max.length();
    }

private:
    int head{0};
    int rear{0};
};
// @lc code=end

int main()
{
    Solution s;
    cout << s.lengthOfLongestSubstring("pwwkew");
    cout << endl;
}