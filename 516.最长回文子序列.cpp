/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
 */
#include <string>
using namespace std;

// @lc code=start
class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        string result;

        // 从单个字节开始

        // 从相同的两个字节开始
        
        string reuslt1;
    }

private:
    bool isCorrect(string str)
    {
        int head = 0;
        int tail = str.size() - 1;
        while (true)
        {
            if ((tail > head) && (str[head] == str[tail]))
            {
                tail--;
                head++;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

int main()
{
    Solution sol;
    sol.longestPalindromeSubseq("bbbab");
}