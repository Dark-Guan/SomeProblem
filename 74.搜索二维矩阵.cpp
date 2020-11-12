/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.size() == 0)
        {
            return false;
        }
        for (int i = matrix.size() - 1; i >= 0; i--)
        {
            vector<int> &tmp = matrix[i];
            if (tmp.size() > 0 && tmp[0] <= target)
            {
                return bianryFind(matrix[i], target);
            }
        }
        return false;
    }

private:
    bool bianryFind(vector<int> &vec, int target)
    {
        int start = 0;
        int end = vec.size() - 1;
        int mid;

        while (true)
        {
            mid = (start + end) / 2;
            if (vec[mid] == target)
            {
                return true;
            }
            else if (start >= end)
            {
                return false;
            }
            else if (target < vec[mid])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return false;
    }
};
// @lc code=end

int main(int argc, char **args)
{
    Solution solution;
    // vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}};
    // int target = 3;
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}};
    int target = 13;
    // vector<vector<int>> matrix = {{}};
    solution.searchMatrix(matrix, target);
}