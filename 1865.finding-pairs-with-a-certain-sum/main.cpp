#include "../includes.hpp"

class FindSumPairs {
public:
  unordered_map<int, int> mp;
  vector<int> nums, ref;
  FindSumPairs(vector<int> &nums1, vector<int> &nums2) {
    nums = nums1;
    ref = nums2;
    for(auto x : nums2) {
      auto it = mp.find(x);
      if(it == mp.end()) {
        it = mp.emplace(x, 0).first;
      }
      it->second++;
    }
  }

  void add(int index, int val) {
    int v = ref[index];
    int nv = ref[index] + val;
    auto it = mp.find(v);
    ref[index] += val;
    it->second--;
    it = mp.find(nv);
    if(it == mp.end()) {
      it = mp.emplace(nv, 0).first;
    }
    it->second++;
  }

  int count(int tot) {
    int ans = 0;
    for(auto x : nums) {
      auto it = mp.find(tot - x);
      if(it != mp.end()) {
        ans += it->second;
      }
    }
    return ans;
  }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
