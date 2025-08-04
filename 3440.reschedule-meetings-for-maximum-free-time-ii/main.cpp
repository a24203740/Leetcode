#include "../includes.hpp"

class Solution {
public:
  int maxFreeTime(int eventTime, vector<int> &startTime, vector<int> &endTime) {
    int lastEndTime = 0;
    vector<int> gaps;
    int n = startTime.size();
    for (int i = 0; i < n; i++) {
      gaps.push_back(startTime[i] - lastEndTime);
      lastEndTime = endTime[i];
    }
    gaps.push_back(eventTime - lastEndTime);
    int gapCount = gaps.size();
    vector<int> prefixMaxGap(gapCount), suffixMaxGap(gapCount);
    prefixMaxGap[0] = gaps[0];
    suffixMaxGap[gapCount - 1] = gaps[gapCount - 1];
    for (int i = 1; i < gapCount; i++) {
      prefixMaxGap[i] = max(prefixMaxGap[i - 1], gaps[i]);
    }
    for (int i = gapCount - 2; i >= 0; i--) {
      suffixMaxGap[i] = max(suffixMaxGap[i + 1], gaps[i]);
    }
    int ans = prefixMaxGap[gapCount - 1]; // single max gap
    for(int i = 0; i < n; i++) {
      int mergeFreeTime = gaps[i] + gaps[i + 1];
      int left = (i > 0) ? prefixMaxGap[i - 1] : 0;
      int right = (i < n - 1) ? suffixMaxGap[i + 2] : 0;
      cout << left << " " << right << endl;
      int eventLength = endTime[i] - startTime[i];
      if(eventLength <= left || eventLength <= right) {
        cout << "Merging " << gaps[i] << " and " << gaps[i + 1] << endl;
        ans = max(ans, mergeFreeTime + eventLength);
      }
      else {
        ans = max(ans, mergeFreeTime);
      }
    }
    return ans;
  }
};
