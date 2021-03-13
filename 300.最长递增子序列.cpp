/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */
#include <vector>
#include <iostream>

using namespace std;
// @lc code=start
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> dp;
        dp.resize(nums.size());
        for (int i = 0;i < dp.size(); i++)
        {
            dp[i] = 1;
        }
        int ans = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                    ans = max(dp[i], ans);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, char **args)
{

    Solution s;
    vector<int> input;
    input = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << s.lengthOfLIS(input) << endl; // 4
    input = {0,1,0,3,2,3};
    cout << s.lengthOfLIS(input) << endl; // 4
    input = {7,7,7,7,7,7,7};
    cout << s.lengthOfLIS(input) << endl; // 1
    return 0;
}