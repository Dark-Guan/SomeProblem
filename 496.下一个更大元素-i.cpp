/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> result;
        stack<int> notFoundNextBig;
        unordered_map<int, int> valToNextBigger;

        for (int val : nums2)
        {
            while (!notFoundNextBig.empty() && val > notFoundNextBig.top())
            {
                valToNextBigger[notFoundNextBig.top()] = val;
                notFoundNextBig.pop();
            }
            notFoundNextBig.push(val);
        }

        while(!notFoundNextBig.empty()){
            valToNextBigger[notFoundNextBig.top()] = -1;
            notFoundNextBig.pop();
        }

        for(int val:nums1){
            if(valToNextBigger.count(val)){
                result.push_back(valToNextBigger[val]);
            } else {
                result.push_back(-1);
            }
        }

        return result;
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    vector<int> reseult = s.nextGreaterElement(nums1, nums2);
    return 0;
}

/*
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> result;
        int i, j = 0;
        for (i = 0; i < nums1.size(); i++)
        {
            bool find = false;
            for (j = 0; j < nums2.size(); j++)
            {
                if (nums1[i] == nums2[j])
                {
                    find = true;
                    continue;
                }
                if (find && nums2[j] > nums1[i])
                {
                    result.push_back(nums2[j]);
                    break;
                }
            }
            if (j == nums2.size())
            {
                result.push_back(-1);
            }
        }
        return result;
    }
};
*/