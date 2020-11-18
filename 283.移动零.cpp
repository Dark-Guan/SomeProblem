/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int numOfZero = 0;
        for (auto it = nums.begin(); it != nums.end();)
        {
            if (*it == 0)
            {
                it = nums.erase(it);
                numOfZero ++ ;
            }
            else
            {
                it++;
            }
        }

        while (numOfZero > 0)
        {
            nums.push_back(0);
            numOfZero--;
        }
    }
};
// @lc code=end

int main()
{
    Solution solution;
    vector<int> vec = {0, 1, 0, 3, 12};

    solution.moveZeroes(vec);
    return 0;
}
