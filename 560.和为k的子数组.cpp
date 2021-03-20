/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为K的子数组
 */
#include <vector>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int result = 0;
        unordered_map<int, int> sum2num;
        int sum = 0;
        sum2num[0] = 1;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(sum2num.count(sum -k)){
                result += sum2num[sum - k];
            }
            sum2num[sum] ++;
        }
        return result;
    }
};
// @lc code=end

