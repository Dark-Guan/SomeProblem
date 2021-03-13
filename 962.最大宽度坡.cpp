/*
 * @lc app=leetcode.cn id=962 lang=cpp
 *
 * [962] 最大宽度坡
 */
#include <vector>
#include <stack>
#include <iostream>

using namespace std;
// @lc code=start
class Solution
{
public:
    int maxWidthRamp(vector<int> &A)
    {
        if (A.size() == 0)
        {
            return 0;
        }
        stack<int> downS;
        downS.push(0);
        for (int i = 1; i < A.size(); i++)
        {
            if (A[i] <= A[downS.top()])
            {
                downS.push(i);
            }
        }
        int ans = 0;
        for (int i = A.size() - 1; i > 0; i --)
        {
            while ((!downS.empty()) && A[i] >= A[downS.top()])
            {
                ans = max(ans, i - downS.top());
                downS.pop();
            }
            if (i < ans)
            {
                break;
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, char ** args)
{
    vector<int> input;
    Solution s;

    input = {6, 0, 8, 2, 1, 5};
    cout << s.maxWidthRamp(input) << endl; // 4
    input = {9, 8, 1, 0, 1, 9, 4, 0, 4, 1};
    cout << s.maxWidthRamp(input) << endl; // 7
    return 0;
}