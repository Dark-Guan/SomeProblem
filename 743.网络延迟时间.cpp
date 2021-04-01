/*
 * @lc app=leetcode.cn id=743 lang=cpp
 *
 * [743] 网络延迟时间
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution
{
    unordered_map<int, int> dist;

public:
    int networkDelayTime(vector<vector<int>> &times, int N, int K)
    {
        unordered_map<int, vector<pair<int, int>>> graph;
        for (int i = 0; i < times.size(); i++)
        {
            if (!graph.count(times[i][0]))
            {
                vector<pair<int, int>> tempRoads;
                graph[times[i][0]] = tempRoads;
            }
            pair<int, int> tempRoad = make_pair(times[i][1], times[i][2]);
            graph[times[i][0]].push_back(tempRoad);
        }
        // sort 排序之后会更加快
        for (int i = 1; i <= N; i++)
        {
            dist[i] = INT_MAX;
        }

        // Dijkstra's
        dist[K] = 0;

        vector<bool> seen(N + 1, false);
        while (true)
        {
            int candNode = -1;
            int candDist = INT_MAX;
            for (int i = 1; i <= N; i++)
            {
                if (!seen[i] && dist[i] < candDist)
                {
                    candNode = i;
                    candDist = dist[i];
                }
            }
            if (candNode < 0)
            {
                break;
            }

            seen[candNode] = true;
            if (graph.count(candNode))
            {
                for (auto info : graph[candNode])
                {
                    dist[info.first] = min(dist[info.first], dist[candNode] + info.second);
                }
            }
        }

        int ans = 0;
        for (auto cost : dist)
        {
            if (cost.second == INT_MAX)
            {
                return -1;
            }
            ans = max(ans, cost.second);
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, char **args)
{

    vector<vector<int>> times = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    Solution solution;
    cout << solution.networkDelayTime(times, 4, 2) << endl;
    ;

    return 0;
}


/* dfs
class Solution
{
    unordered_map<int, int> dist;

public:
    int networkDelayTime(vector<vector<int>> &times, int N, int K)
    {
        unordered_map<int, vector<pair<int, int>>> graph;
        for (int i = 0; i < times.size(); i++)
        {
            if (!graph.count(times[i][0]))
            {
                vector<pair<int, int>> tempRoads;
                graph[times[i][0]] = tempRoads;
            }
            pair<int, int> tempRoad = make_pair(times[i][1], times[i][2]);
            graph[times[i][0]].push_back(tempRoad);
        }

        // sort 排序之后会更加快
        for (int i = 1; i <= N; i++)
        {
            dist[i] = INT_MAX;
        }
        dfs(graph, K, 0);

        int ans = 0;
        for (auto cost : dist)
        {
            if (cost.second == INT_MAX)
            {
                return -1;
            }
            ans = max(ans, cost.second);
        }
        return ans;
    }

    void dfs(unordered_map<int, vector<pair<int, int>>> &graph, int node, int elapsed)
    {
        if (elapsed >= dist[node]) // 剪枝加速；
        {
            return;
        }
        dist[node] = elapsed;
        if (graph.count(node))
        {
            for (auto it : graph[node])
            {
                dfs(graph, it.first, elapsed + it.second);
            }
        }
    }
};
*/

/* 还可以用优先队列来做加速，每次选到的边都是最小的；优先的map
class Solution
{
    unordered_map<int, int> dist;

public:
    int networkDelayTime(vector<vector<int>> &times, int N, int K)
    {
        unordered_map<int, vector<pair<int, int>>> graph;
        for (int i = 0; i < times.size(); i++)
        {
            if (!graph.count(times[i][0]))
            {
                vector<pair<int, int>> tempRoads;
                graph[times[i][0]] = tempRoads;
            }
            pair<int, int> tempRoad = make_pair(times[i][1], times[i][2]);
            graph[times[i][0]].push_back(tempRoad);
        }
        // sort 排序之后会更加快
        for (int i = 1; i <= N; i++)
        {
            dist[i] = INT_MAX;
        }

        // Dijkstra's
        dist[K] = 0;

        vector<bool> seen(N + 1, false);
        while (true)
        {
            int candNode = -1;
            int candDist = INT_MAX;
            for (int i = 1; i <= N; i++)
            {
                if (!seen[i] && dist[i] < candDist)
                {
                    candNode = i;
                    candDist = dist[i];
                }
            }
            if (candNode < 0)
            {
                break;
            }

            seen[candNode] = true;
            if (graph.count(candNode))
            {
                for (auto info : graph[candNode])
                {
                    dist[info.first] = min(dist[info.first], dist[candNode] + info.second);
                }
            }
        }

        int ans = 0;
        for (auto cost : dist)
        {
            if (cost.second == INT_MAX)
            {
                return -1;
            }
            ans = max(ans, cost.second);
        }
        return ans;
    }
};
*/

/*
还可以用优先队列

class Solution {
    public int networkDelayTime(int[][] times, int N, int K) {
        Map<Integer, List<int[]>> graph = new HashMap();
        for (int[] edge: times) {
            if (!graph.containsKey(edge[0]))
                graph.put(edge[0], new ArrayList<int[]>());
            graph.get(edge[0]).add(new int[]{edge[1], edge[2]});
        }
        PriorityQueue<int[]> heap = new PriorityQueue<int[]>(
                (info1, info2) -> info1[0] - info2[0]);
        heap.offer(new int[]{0, K});

        Map<Integer, Integer> dist = new HashMap();

        while (!heap.isEmpty()) {
            int[] info = heap.poll();
            int d = info[0], node = info[1];
            if (dist.containsKey(node)) continue;
            dist.put(node, d);
            if (graph.containsKey(node))
                for (int[] edge: graph.get(node)) {
                    int nei = edge[0], d2 = edge[1];
                    if (!dist.containsKey(nei))
                        heap.offer(new int[]{d+d2, nei});
                }
        }

        if (dist.size() != N) return -1;
        int ans = 0;
        for (int cand: dist.values())
            ans = Math.max(ans, cand);
        return ans;
    }

作者：LeetCode
链接：https://leetcode-cn.com/problems/network-delay-time/solution/wang-luo-yan-chi-shi-jian-by-leetcode/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
