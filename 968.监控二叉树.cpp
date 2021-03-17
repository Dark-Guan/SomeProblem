/*
 * @lc app=leetcode.cn id=968 lang=cpp
 *
 * [968] 监控二叉树
 */
#include <iostream>
#include <unordered_map>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
    int INTMAX = 2 << 20;
    struct Status
    {
        int a, b, c;
    };

    Status dfs(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {INTMAX / 2, 0, 0};
        }

        auto [la, lb, lc] = dfs(root->left);
        auto [ra, rb, rc] = dfs(root->right);
        //root 必须放置摄像头的情况下，覆盖整棵树需要的摄像头数目。
        int a = lc + rc + 1; 
        // 覆盖整棵树需要的摄像头数目，无论 root 是否放置摄像头。
        int b = min(a, min(la + rb, lb + ra)); 
        // 覆盖两棵子树需要的摄像头数目，无论节点 root 本身是否被监控到。
        int c = min(a, lb + rb); 

        return {a, b, c};
    }

public:
    int minCameraCover(TreeNode *root)
    {
        auto result = dfs(root);
        return result.b;
    }
};
// @lc code=end
