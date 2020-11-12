/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */
#include <string>
#include <stack>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool isValid(string s)
    {
        for (char ch : s)
        {
            if (ch == '[' || ch == '{' || ch == '(')
            {
                bracket.push(ch);
            }
            else
            {
                if (bracket.size() == 0)
                {
                    return false;
                }
                if (isMatch(bracket.top(), ch))
                {
                    bracket.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        if (bracket.size() > 0)
        {
            return false;
        }
        return true;
    }

private:
    bool isMatch(char src, char dest)
    {
        if ((src == '(') && (dest == ')'))
        {
            return true;
        }
        if ((src == '{') && (dest == '}'))
        {
            return true;
        }
        if ((src == '[') && (dest == ']'))
        {
            return true;
        }
        return false;
    }

    stack<char> bracket;
};
// @lc code=end

int main(int argc, char **args)
{
    Solution solution;
    solution.isValid("()[]{}");
}