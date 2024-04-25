/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution {
public:
    int binSer(int l, int r, int t)
    {
        if(l >= r)return l;
        long long int mid = (l+r)/2;
        long long int pow = mid*mid;
        if(pow > t)
        {
            return binSer(l, mid, t);
        }
        else if(pow < t)
        {
            return binSer(mid+1, r, t);
        }
        return mid;
    }
    int mySqrt(int x) {
        if(x == 0)return 0;
        long long int ans = binSer(1, 65536, x);
        if(ans * ans == x)return ans;
        return ans-1;
    }
};
// @lc code=end

