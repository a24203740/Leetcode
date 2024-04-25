/*
 * @lc app=leetcode id=988 lang=cpp
 *
 * [988] Smallest String Starting From Leaf
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
    deque<char> smallest;
    bool first;
    void DFS(TreeNode* cur, deque<char>& str)
    {
        if(!cur)return;
        str.push_front(cur->val + 'a');
        if(!cur->left && !cur->right)
        {
            if(first || lexicographical_compare(str.begin(), str.end(),
                smallest.begin(), smallest.end()))
            {
                smallest = str;
                first = false;
            }
            str.pop_front();
            return;
        }
        else
        {
            if(cur->left)DFS(cur->left, str);
            if(cur->right)DFS(cur->right, str);
        }
        str.pop_front();
        return;
    }
    string smallestFromLeaf(TreeNode* root) {
        first = true;
        deque<char> tp;
        DFS(root, tp);
        return string(smallest.begin(), smallest.end());
    }
};
// @lc code=end

