/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// @lc code=start
class Solution
{
    vector<vector<int>> edges;
    vector<int> degreee;
    vector<int> result;

public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        edges.resize(numCourses);
        degreee.resize(numCourses);
        for (const auto info : prerequisites)
        {
            edges[info[1]].push_back(info[0]);
            ++degreee[info[0]];
        }
        queue<int> que;
        for(int i = 0 ; i< numCourses; i++){
            if(degreee[i] == 0){
                que.push(i);
            }
        }
        while(!que.empty()){
            int front = que.front();
            que.pop();
            result.push_back(front);
            for(int i : edges[front]){
                degreee[i] --;
                if(degreee[i] == 0){
                    que.push(i);
                }
            }
        }

        if(result.size() != numCourses){
            return {};
        }
        return result;
    }
};
// @lc code=end

int main(int argc, char **args)
{
    vector<vector<int>> infos = {{}};
    Solution sol;
    sol.findOrder(2, infos);
    return 0;
}

/*
第一种解法 DFS
class Solution
{
    vector<vector<int>> edges;
    vector<int> visited; // 1 searching 2 end 0 no visited
    vector<int> result;
    bool valid = true;

public:
    void dfs(int u)
    {
        if (!valid || visited[u] == 2)
        {
            return;
        }
        if (visited[u] == 1)
        {
            valid = false;
            return;
        }
        visited[u] = 1;
        for (int vec : edges[u])
        {
            dfs(vec);
        }

        visited[u] = 2;
        result.push_back(u);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        edges.resize(numCourses);
        visited.resize(numCourses);
        for (const auto info : prerequisites)
        {
            edges[info[1]].push_back(info[0]);
        }

        for (int i = 0; i < edges.size(); i++)
        {
            dfs(i);
        }
        
        if(!valid){
            return {};
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
*/