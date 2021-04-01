/*
 * @lc app=leetcode.cn id=621 lang=cpp
 *
 * [621] 任务调度器
 */
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
// @lc code=start
class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        unordered_map<char, int> taskCountEach;
        unordered_map<char, int> taskTimeEach;

        for (int i = 0; i < tasks.size(); i++)
        {
            taskCountEach[tasks[i]]++;
            taskTimeEach[tasks[i]] = 0;
        }

        int taskRunTime = 0;
        while (taskCountEach.size())
        {
            char nowTask = 'a';
            int nowTaskTime = 0;
            for (auto iter = taskCountEach.begin(); iter != taskCountEach.end(); iter++)
            {
                if (taskTimeEach[iter->first] == 0 && taskCountEach[iter->first] > nowTaskTime)
                {
                    nowTaskTime = iter->second;
                    nowTask = iter->first;
                }
            }
            if (nowTask != 'a')
            {
                taskCountEach[nowTask]--;
                taskTimeEach[nowTask] = n + 1;
                // cout << nowTask << " -> ";
                if (taskCountEach[nowTask] <= 0)
                {
                    taskCountEach.erase(nowTask);
                }
            }
            else
            {
                // cout << "delay"
                //      << " -> ";
            }

            for (auto iter = taskTimeEach.begin(); iter != taskTimeEach.end(); iter++)
            {
                if (taskTimeEach[iter->first])
                {
                    taskTimeEach[iter->first]--;
                }
            }

            taskRunTime++;
        }
        // cout << endl;
        return taskRunTime;
    }
};
// @lc code=end

int main(int argc, char **args)
{
    Solution sol;
    vector<char> input = {'A', 'A', 'A', 'B', 'B', 'B'};
    cout << sol.leastInterval(input, 2) << endl;
    return 0;
}