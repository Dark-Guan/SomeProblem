/*
 * @lc app=leetcode.cn id=593 lang=cpp
 *
 * [593] 有效的正方形
 */
#include <vector>
#include <iostream>

using namespace std;

// @lc code=start
const double ERRPR = 1e-7;
class Solution
{
    double dist(vector<int> &p1, vector<int> &p2)
    {
        return (p2[1] - p1[1]) * (p2[1] - p1[1]) + (p2[0] - p1[0]) * (p2[0] - p1[0]);
    }

    bool SortFunc(vector<int> &p1, vector<int> &p2)
    {
        bool result = p2[0] == p1[0] ? (p1[1] - p2[1]) : (p1[0] - p2[0]);
        return result;
    }
    bool DoubleEqual(double d1, double d2)
    {
        double temp = d1 - d2;
        if (temp > -ERRPR && temp < ERRPR)
        {
            return true;
        }
        return false;
    }

public:
    bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4)
    {
        vector<vector<int>> points = {p1, p2, p3, p4};
        sort(points.begin(), points.end(),
             [=](vector<int> p1, vector<int> p2) {
                 if (p2[0] == p1[0])
                 {
                     if (p2[1] >= p1[1])
                     {
                         return true;
                     }
                     else
                     {
                         return false;
                     }
                 }
                 else
                 {
                     if (p2[0] >= p1[0])
                     {
                         return true;
                     }
                     else
                     {
                         return false;
                     }
                 }
             });
        double zero = 0.0;
        double temp = dist(points[0], points[1]);

        return dist(points[0], points[1]) != 0 && DoubleEqual(dist(points[0], points[1]), dist(points[1], points[3])) &&
               DoubleEqual(dist(points[1], points[3]), dist(points[3], points[2])) &&
               DoubleEqual(dist(points[3], points[2]), dist(points[2], points[0])) &&
               DoubleEqual(dist(points[0], points[3]), dist(points[1], points[2]));
    }
};

// @lc code=end

int main(int argc, char **args)
{
    Solution s;
    vector<int> p1 = {0, 0};
    vector<int> p2 = {1, 1};
    vector<int> p3 = {1, 0};
    vector<int> p4 = {0, 1};
    bool result = s.validSquare(p1, p2, p3, p4);
    std::cout << result << std::endl;
    return 0;
}
