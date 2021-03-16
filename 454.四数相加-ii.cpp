/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */
#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start
class Solution
{
    unordered_map<int, int > ABValue;

public:
    int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D)
    {   
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < B.size(); j++)
            {
                int value = -(A[i] + B[j]);
                ABValue[value] ++;
            }
        }
        int count = 0;
        for (int i = 0; i < C.size(); i++)
        {
            for (int j = 0; j < D.size(); j++)
            {
                int value = C[i] + D[j];
                if(ABValue.count(value)){
                    count +=ABValue[value];
                }
            }
        }
        return count;
    }
};
// @lc code=end
