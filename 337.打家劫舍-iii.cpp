/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
 */
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

struct robState
{
    int beRobbed;
    int notBeRobbed;
};

class Solution
{
    robState dfs(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {0, 0};
        }
        robState l = dfs(root->left);
        robState r = dfs(root->right);
        int beRobbed = root->val + l.notBeRobbed + r.notBeRobbed;
        int notBeRobbed = max(l.beRobbed, l.notBeRobbed) + max(r.beRobbed, r.notBeRobbed);

        return {beRobbed, notBeRobbed};
    }

public:
    int rob(TreeNode *root)
    {
        robState state = dfs(root);

        return max(state.beRobbed, state.notBeRobbed);
    }
};
// @lc code=end

int main(int argc, char **args)
{
    return 0;
}

/*
class Solution
{
    unordered_map<TreeNode *, int> beRobbed, notBeRobbed;

    void dfs(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        dfs(root->left);
        dfs(root->right);
        beRobbed[root] = root->val + notBeRobbed[root->left] + notBeRobbed[root->right];
        notBeRobbed[root] = max(beRobbed[root->left], notBeRobbed[root->left]) + max(beRobbed[root->right], notBeRobbed[root->right]);
    }

public:
    int rob(TreeNode *root)
    {
        dfs(root);

        return max(beRobbed[root], notBeRobbed[root]);
    }
};
*/
