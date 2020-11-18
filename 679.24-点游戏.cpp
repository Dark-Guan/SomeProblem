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
    bool judgePoint24(vector<int> &nums)
    {
        this->state = new bool[nums.size()];
        for (int i = 0; i < nums.size(); i++)
        {
            this->state[i] = false;
        }
        vector<int> currSeq;
        int index = 0;
        return calPoint24(nums, currSeq, state, index);
    }

    ~Solution()
    {
        delete[] state;
    }

private:
    bool calPoint24(vector<int> &nums,
                    vector<int> currSeq,
                    bool *state, int &index)
    {
        if (currSeq.size() == nums.size())
        {
            if (calValue24(currSeq))
            {
                return true;
            }
            return false;
        }
        while (state[index] == false)
        {
            currSeq.push_back(nums[index]);
            state[index] = true;
            if (calPoint24(nums, currSeq, state, index) == true)
            {
                return true;
            }
            currSeq.pop_back();
            state[index] = false;
            index = (index + 1) % nums.size();
        }
        return false;
    }

    bool calValue24(vector<int> &currSeq)
    {
        float sum = 0;
        for (int i = 0; i < 4; i++)
        {
            sum = cal(currSeq[0], currSeq[1], i);
            for (int j = 0; j < 4; j++)
            {
                sum = cal(sum, currSeq[2], j);
                for (int k = 0; k < 4; k++)
                {
                    sum = cal(sum, currSeq[3], k);
                    if ((int)sum == 24)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    float cal(float src, float dest, int type)
    {
        switch (type)
        {
        case 0:
            return src + dest;
        case 1:
            return src - dest;
        case 2:
            return src * dest;
        case 3:
            return src / dest;
        default:
            break;
        }
    }

    bool *state{nullptr};
};
// @lc code=end

int main()
{
    Solution sol;
    vector<int> data = {4, 1, 8, 7};
    cout << sol.judgePoint24(data) << endl;
    return 0;
}