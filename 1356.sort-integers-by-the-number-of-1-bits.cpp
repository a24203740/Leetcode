class Solution {
public:
    inline int countOne(int x)
    {
        int count = 0;
        for(int i = 0; i < 14; i++)
        {
            if(((1<<i) & x) != 0)
            {
                count ++;
            }
        }
        return count;
    }
    vector<int> sortByBits(vector<int>& arr) {
        int N = arr.size();
        vector<pair<int,int>> numAndOne(N);
        for(int i = 0; i < N; i++)
        {
            numAndOne[i] = make_pair(countOne(arr[i]), arr[i]);
        }
        sort(numAndOne.begin(), numAndOne.end());
        for(int i = 0; i < N; i++)
        {
            arr[i] = numAndOne[i].second;
        }
        return arr;
    }
};