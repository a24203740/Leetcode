/*
 * @lc app=leetcode id=623 lang=cpp
 *
 * [623] Add One Row to Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void DFS(TreeNode* root, int val, int targetDepth, int curDepth)
    {
        if(!root)return;
        if(curDepth == targetDepth - 1)
        {
            TreeNode* newLeft = new TreeNode(), *newRight = new TreeNode();
            newLeft -> val = val;
            newRight -> val = val;
            newLeft -> left = root -> left;
            newRight -> right = root -> right;
            root->left = newLeft;
            root->right = newRight;
            return;
        }
        else
        {
            if(root->left)
            {
                DFS(root->left, val, targetDepth, curDepth+1);
            }
            if(root->right)
            {
                DFS(root->right, val, targetDepth, curDepth+1);
            }
        }
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1)
        {
            TreeNode* newRoot = new TreeNode();
            newRoot->left = root;
            newRoot->val = val;
            return newRoot;
        }
        DFS(root, val, depth, 1);
        return root;
    }
};
// @lc code=end

