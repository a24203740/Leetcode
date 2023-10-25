/*
 * @lc app=leetcode id=779 lang=cpp
 *
 * [779] K-th Symbol in Grammar
 */

// @lc code=start
class Solution {
public:
    int kthGrammar(int n, int k) {
        k--;
        int ans = 0;
        for(int i = 0; i < 32; i++)
        {
            if((k>>i) & 1 == 1)
            {
                ans ^= 1;
            } 
        }
        return ans;
    }
};

/*

left half of the n+1th row is same as nth row.
right half of the n+1th row is complement of nth row.

so, if k is in left half, it is same as kth symbol in n-1th row.
if k is in right half, it is complement of k-(s/2)th symbol in nth row.
    where, s is size of nth row.
    and so, k-(s/2)th symbol in nth row is same as k-(s/2)th symbol in n-1th row.

we can use this to recursively find the answer. But we use a trick to avoid recursion.

let say, k is 21, we can write it as 16+4+1.
in 6th row, we don't know the answer of 21th symbol, but we know 21 is in right half.
so k is complement of 21 - 16 = 5th symbol in 6th row.
we can use the same way to find 5th symbol in 6th row, by substrating 4 from 5, and so on.

that is, if we keep substacting the highest power of 2 from k, we will eventually reach index 0.
and the time we subtracted, is the number of times we need to flip the 0, 
    and also the count of 1 in binary representation of k.

so all we need is to count the number of 1 in binary representation of k, 
    if the count is odd, answer is 1, since we filp 0 for odd number of times.
    and vice versa.


*/
// @lc code=end

