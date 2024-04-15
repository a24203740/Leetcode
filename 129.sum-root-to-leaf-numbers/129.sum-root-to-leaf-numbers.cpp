/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
 */
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
using namespace std;
// @lc code=start

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int count;
    void DFS(TreeNode* root, int num)
    {
        if(!root)return;
        int cur = num * 10 + root->val;
        if(!root->left && !root->right)
        {
            count += cur;
            return;
        }
        if(root->left)
        {
            DFS(root->left, cur);
        }
        if(root->right)
        {
            DFS(root->right, cur);
        }
    }
    int sumNumbers(TreeNode* root) {
        count = 0;
        DFS(root, 0);
        return count;
    }
};
// @lc code=end

