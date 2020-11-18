/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */
#include <iostream>
#include <vector>
#include <stack>

using namespace std;
// @lc code=start
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        stack<int> upStack;
        for (int num : nums)
        {
            if (upStack.size() > 0)
            {
                if (upStack.top() > num)
                {
                    return num;
                }
                else
                {
                    upStack.push(num);
                }
            }
            else
            {
                upStack.push(num);
            }
        }
        while (upStack.size() > 1)
        {
            upStack.pop();
        }
        return upStack.top();
    }
};
// @lc code=end

int main()
{
    vector<int> vec = {4, 5, 6, 7, 0, 1, 2};
    Solution solution;
    cout << solution.findMin(vec) << endl;
    return 1;
}
