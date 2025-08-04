#include "../includes.hpp"

struct TrieNode {
  bool isEnd;
  map<string, TrieNode *> children;
};

class Solution {
public:
  vector<string> ans;
  void extract(string& folderName, size_t start, TrieNode *cur) {
    auto it = folderName.find('/', start);
    if(it != folderName.npos) {
      folderName[it] = '\0';
    }
    auto next = cur->children.find(folderName.data() + start);
    if (next == cur->children.end()) {
      next = cur->children.emplace(folderName.data() + start, new TrieNode()).first;
      next->second->isEnd = false;
    }
    if (next->second->isEnd) return;
    if (it != folderName.npos) {
      extract(folderName, it+1, next->second);
    } else {
      next->second->isEnd = true;
    }
  }
  void DFS(TrieNode *root, string &acc, const string &cur) {
    auto preEnd = acc.end();
    acc += cur;
    auto newEnd = acc.end();
    if (root->isEnd) {
      ans.push_back(acc);
    } else {
      acc += '/';
      for (auto p : root->children) {
        DFS(p.second, acc, p.first);
      }
      acc.pop_back();
    }
    acc.erase(preEnd, newEnd);
  }
  vector<string> removeSubfolders(vector<string> &folder) {
    sort(folder.begin(), folder.end(), [](const string& a, const string& b) {
      return a.size() < b.size();
    });
    TrieNode *root = new TrieNode();
    for (auto &s : folder) {
      extract(s, 1, root);
    }
    string acc = "";
    acc.reserve(256);
    DFS(root, acc, "");
    return ans;
  }
};
