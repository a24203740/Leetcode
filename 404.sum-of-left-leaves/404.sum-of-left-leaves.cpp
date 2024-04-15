/*
 * @lc app=leetcode id=404 lang=cpp
 *
 * [404] Sum of Left Leaves
 */
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// @lc code=start
class Solution {
public:
    bool isLeaf(TreeNode* cur)
    {
        if(cur == nullptr)return false;
        if(cur -> left == nullptr && cur->right == nullptr)
        {
            return true;
        }
        return false;
    }
    int DFS(TreeNode* root)
    {
        int count = 0;
        if(root == nullptr)
        {
            return 0;
        }
        if(isLeaf(root->left))
        {
            count += root->left->val;
        }
        else if(!root->left)
        {
            count += DFS(root->left);
        }
        if(!root->right && !isLeaf(root->right))
        {
            count += DFS(root->right);
        }
        return count;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return DFS(root);
    }
};
// @lc code=end

