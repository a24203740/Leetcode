#include "../includes.hpp"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

class Solution {
private:
  vector<int> level;
  int deepestLevel;
  vector<vector<TreeNode*>> ancestors;
  vector<TreeNode*> deepestLeaves;

public:
  void buildAncestors(TreeNode *cur, TreeNode* par) {
    TreeNode* ancestor = par;
    int level = 0;
    while (ancestor != nullptr) {
      ancestors[cur->val][level] = ancestor;
      ancestor = ancestors[ancestor->val][level];
      level++;
    }
    if (cur->left) {
      buildAncestors(cur->left, cur);
    }
    if (cur->right) {
      buildAncestors(cur->right, cur);
    }
  }
  void buildLevel(TreeNode *cur, int l) {
    deepestLevel = max(deepestLevel, l);
    level[cur->val] = l;
    if (cur->left) {
      buildLevel(cur->left, l + 1);
    }
    if (cur->right) {
      buildLevel(cur->right, l + 1);
    }
  }
  void buildDeepestLeaves (TreeNode* cur, int l) {
    if (l == deepestLevel) {
      deepestLeaves.push_back(cur);
    }
    if (cur->left) {
      buildDeepestLeaves(cur->left, l + 1);
    }
    if (cur->right) {
      buildDeepestLeaves(cur->right, l + 1);
    }
  }
  TreeNode* findLCA(TreeNode* a, TreeNode* b) {
    if (level[a->val] < level[b->val]) {
      swap(a, b);
    }
    int diff = level[a->val] - level[b->val];
    for (int i = 0; i < 12; i++) {
      if ((diff >> i) & 1) {
        a = ancestors[a->val][i];
      }
    }
    if (a == b) {
      return a;
    }
    for (int i = 11; i >= 0; i--) {
      if (ancestors[a->val][i] != ancestors[b->val][i]) {
        a = ancestors[a->val][i];
        b = ancestors[b->val][i];
      }
    }
    return ancestors[a->val][0];
  }
  TreeNode *lcaDeepestLeaves(TreeNode *root) {
    ancestors.assign(1005, vector<TreeNode*>(12, nullptr));
    level.assign(1005, -1);
    deepestLevel = 0;
    buildAncestors(root, nullptr);
    buildLevel(root, 0);
    buildDeepestLeaves(root, 0);
    if (deepestLeaves.size() < 2) {
      return deepestLeaves[0];
    }
    TreeNode* lca = findLCA(deepestLeaves[0], deepestLeaves[1]);
    for (int i = 2; i < deepestLeaves.size(); i++) {
      lca = findLCA(lca, deepestLeaves[i]);
    }
    return lca;
  }
};
