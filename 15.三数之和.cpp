/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        map<vector<int>, bool> storeVec;
        vector<vector<int>> retVec;
        if (nums.size() < 3)
        {
            return retVec;
        }
        vector<int> tmp;
        while (first < nums.size() - 2)
        {
            if (calcSum(nums) == 0)
            {   
                tmp.clear();
                tmp.push_back(nums[first]);
                tmp.push_back(nums[second]);
                tmp.push_back(nums[third]);
                sort(tmp.begin(), tmp.end());
                // 1
                // if (isDup(retVec,tmp) == false)
                // {
                //     retVec.push_back(tmp);
                // }
                // 2
                // if (storeVec.find(tmp) == storeVec.end())
                // {
                //     storeVec[tmp] = true;
                //     retVec.push_back(tmp);
                // }
                // 3
                // auto result = storeVec.emplace(tmp, true);
                auto result = storeVec.insert(make_pair(tmp,true));
                if(result.second){
                    retVec.push_back(tmp);
                }
            }

            if (second + 1 != third)
            {
                second++;
            }
            else if (third + 1 < nums.size())
            {
                third++;
                second = first + 1;
            }
            else
            {
                first++;
                second = first + 1;
                third = second + 1;
            }

            // 可以尝试一下，两头的指针，往中间靠拢；从而计算出最后的值
        }

        return retVec;
    }

private:
    // 这样的去重是会非常超时
    bool isDup(vector<vector<int>> lists, vector<int> &nums)
    {
        for (int i = 0; i < lists.size(); i++)
        {
            if (isEqual(lists[i], nums) == true)
            {
                return true;
            }
        }
        return false;
    }

    bool isEqual(vector<int> src, vector<int> dest)
    {

        for (int i = 0; i < src.size(); i++)
        {
            if (src[i] != dest[i])
            {
                return false;
            }
        }

        return true;
    }

    int calcSum(vector<int> &nums)
    {
        return nums[first] + nums[second] + nums[third];
    }

    int first{0};
    int second{1};
    int third{2};
};
// @lc code=end

int main()
{
    Solution solution;
    vector<int> input = {-15, 10, 0, -2, 14, -1, -10, -14, 10, 12, 6, -6, 10, 2, -11, -9, 2, 13, 2, -9, -14, -12, -10, -12, 13, 13, -10, -3, 2, -11, 3, -6, 6, 10, 7, 5, -13, 4, -2, 12, 1, -11, 14, -4, 6, -12, -6, -14, 8, 11, -8, 1, 7, -3, 5, 5, -13, 10, 9, -3, 6, -10, 6, -3, 7, -9, -13, 9, 10, 0, -1, -11, 4, -10, -8, -13, -15, 2, -12, 8, -2, -12, -14, -10, -8, 6, 2, -5, -7, -11, 7, 14, -6, -10, -12, 8, -4, -10, -5, 14, -3, 9, -12, 8, 14, -13};
    solution.threeSum(input);
}