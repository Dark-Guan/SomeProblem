/*
 * @lc app=leetcode.cn id=679 lang=cpp
 *
 * [679] 24 点游戏
 */
#include <iostream>
#include <vector>
#include <initializer_list>
using namespace std;
// @lc code=start
class Solution
{
public:
    static constexpr int TARGET = 24;
    static constexpr double EPSILON = 1e-6;
    static constexpr int ADD = 1, MULTIPLY = 1, SUBTRACT = 2, DEVIDE = 3;
    bool judgePoint24(vector<int> &nums)
    {
        vector<double> dNums;
        for (const int &num : nums)
        {
            dNums.push_back(static_cast<double>(num));
        }
        return solve(dNums);
    }

    bool solve(vector<double> &dNums)
    {
        if (dNums.size() == 0)
        {
            return false;
        }
        return false;
    }
};
// @lc code=end

int main()
{
    Solution sol;
    vector<int> data = {4, 1, 8, 7};
    cout << sol.judgePoint24(data) << endl;
    data = {1, 2, 1, 2};
    cout << sol.judgePoint24(data) << endl;
    return 0;
}