#include "../includes.hpp"

struct Trienode {
  map<string, Trienode*> mp;
  string val;
  bool marked;
  Trienode() {
    val = "";
    marked = false;
  }
  Trienode(const string& v) {
    val = v;
    marked = false;
  }
  map<string, Trienode*>::iterator get(const string& v) {
    auto it = mp.find(v);
    if(it == mp.end()) {
      it = mp.emplace(v, new Trienode(v)).first;
    }
    return it;
  }
};
Trienode* trace(const vector<string>& path, Trienode* root) {
  int n = path.size();
  Trienode* cur = root;
  for(int i = 0; i < n; i++) {
    auto it = cur->get(path[i]);
    cur = it->second;
  }
  return cur;
}

using ll = long long;
class Solution {
  map<ll, Trienode*> signature;
public:
  const ll p = 35, x = 25531, mod = 1e9+7;
  void genTrie(vector<vector<string>> &paths, Trienode* root) {
    int n = paths.size();
    for (int i = 0; i < n; i++) {
      trace(paths[i], root);
    }
  }
  pair<ll, ll> genSignature(Trienode* cur) {
    static int level = 1;
    ll modifer = 1;
    ll hashedVal = 0;
    for (auto p : cur->mp) {
      level++;
      auto [subHash, subMod] = genSignature(p.second);
      level--;
      hashedVal = (hashedVal * subMod) % mod;
      hashedVal = (hashedVal + subHash) % mod;
      modifer = (modifer * subMod) % mod;
    }
    cout << cur->val << " " << level << " ";
    cout << hashedVal << endl;
    auto it = signature.find(hashedVal);
    if(it == signature.end()) {
      signature.emplace(hashedVal, cur);
    }
    else if(hashedVal != 0) {
      cout << cur->val << " marked\n";
      it->second->marked = true;
      cur->marked = true;
    }
    int n = cur->val.size();
    for(int i = 0; i < n; i++) {
      int c = (cur->val[i] - 'a') + 1;
      hashedVal += modifer * c;
      hashedVal %= mod;
      modifer *= p;
      modifer %= mod;
    }
    return {hashedVal, modifer};
  }
  void DFS(vector<vector<string>>& ans, vector<string>& cur, Trienode* curNode) {
    cout << curNode->val << '\n';
    if(curNode->marked)return;
    cout << "not returned\n";
    if(curNode->val != "") {
      cur.push_back(curNode->val);
      ans.push_back(cur);
    }
    for(auto p: curNode->mp) {
      DFS(ans, cur, p.second);
    }
    if(curNode->val != "")cur.pop_back();
  }
  vector<vector<string>> deleteDuplicateFolder(vector<vector<string>> &paths) {
    int n = paths.size();
    Trienode* root = new Trienode();
    genTrie(paths, root);
    genSignature(root);
    vector<vector<string>> ans;
    vector<string> tp;
    DFS(ans, tp, root);
    return ans;
  }
};
