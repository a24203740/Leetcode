class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto first = lower_bound(nums.begin(), nums.end(), target);
        auto second = upper_bound(nums.begin(), nums.end(), target);
        vector<int> ans;
        if(first != nums.end() && *first == target)
        {
            ans.push_back(distance(nums.begin(), first));
            ans.push_back(distance(nums.begin(), second) - 1);
        }
        else
        {
            ans.assign(2, -1);
        }
        return ans;
    }
};