/*
 * @lc app=leetcode.cn id=554 lang=cpp
 *
 * [554] 砖墙
 */
#include <vector>
#include <unordered_map>

using namespace std;
// @lc code=start
class Solution {
public:
    int leastBricks(vector<vector<int> >& wall) {
        unordered_map<int, int> wallSum;
        for(int i =0; i < wall.size(); i++){
            int sum = 0;
            for(int j =0; j < wall[i].size() - 1; j++){
                sum += wall[i][j];
                wallSum[sum] ++;
            }
        }
        int result = 0;
        for(auto &a : wallSum){
            result = max(result, a.second);
        }

        return wall.size() - result;
    }
};
// @lc code=end

