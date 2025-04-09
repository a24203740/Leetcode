#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <utility>
#include <bitset>

using namespace std;

//structures
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Node { //class only for auto complete
public:
    int val;
    std::vector<Node*> children;
    Node* left;
    Node* right;
    Node* next;

    Node(int _val, std::vector<Node*> _children) {
        val = _val;
        children = _children;
    }
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}

};
class NodeChildren { //Called Node in leetcode but there are multiple vairant
public:
    int val;
    std::vector<NodeChildren*> children;

    NodeChildren() {}

    NodeChildren(int _val) {
        val = _val;
    }

    NodeChildren(int _val, std::vector<NodeChildren*> _children) {
        val = _val;
        children = _children;
    }
};
class NodeLeftRightNext {//Called Node in leetcode but there are multiple vairant
public:
    int val;
    NodeLeftRightNext* left;
    NodeLeftRightNext* right;
    NodeLeftRightNext* next;

    NodeLeftRightNext() : val(0), left(NULL), right(NULL), next(NULL) {}

    NodeLeftRightNext(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    NodeLeftRightNext(int _val, NodeLeftRightNext* _left, NodeLeftRightNext* _right, NodeLeftRightNext* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
