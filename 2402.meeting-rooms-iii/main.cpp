#include "../includes.hpp"

using ll = long long;
using pii = pair<ll, int>;
class Solution {
public:
  int mostBooked(int n, vector<vector<int>> &meetings) {
    priority_queue<pii, vector<pii>, greater<pii>> usingRoom;
    vector<int> roomUsedCount(n, 0);
    bitset<128> unusedRooms;
    unusedRooms.set(); // All rooms are initially unused
    auto getFirstUnusedRoom = [&unusedRooms, n]() {
      int pos = unusedRooms._Find_first();
      if(pos >= n) {
        return -1;
      }
      return pos;
    };
    int N = meetings.size();
    sort(
        meetings.begin(), meetings.end(),
        [](const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; });
    for (int i = 0; i < N; i++) {
      ll st = meetings[i][0];
      while (!usingRoom.empty()) {
        auto [endTime, roomIndex] = usingRoom.top();
        if(endTime > st)break;

        unusedRooms.set(roomIndex); // Mark room as unused
        usingRoom.pop();
      }
      ll duration = meetings[i][1] - meetings[i][0];
      int firstUnusedRoom = getFirstUnusedRoom();
      // directly using a unused room
      if (firstUnusedRoom != -1) {
        unusedRooms.reset(firstUnusedRoom); // Mark room as used
        roomUsedCount[firstUnusedRoom]++;
        // cout << "Meeting " << i << " in room " << firstUnusedRoom << " from "
        //      << st << " to " << st + duration << endl;
        usingRoom.push({st + duration, firstUnusedRoom});
        continue;
      }
    
      // used a room that is currently in use (wait until it is free)
      auto [endTime, roomIndex] = usingRoom.top();
      usingRoom.pop();
      roomUsedCount[roomIndex]++;
      st = endTime; // Wait until the room is free
      usingRoom.push({st + duration, roomIndex});
      // cout << "Meeting " << i << " in room " << roomIndex << " from "
      //      << st << " to " << st + duration << endl;
    }
    int ans = 0, maxVal = 0;
    for (int i = 0; i < n; i++) {
      if (roomUsedCount[i] > maxVal) {
        maxVal = roomUsedCount[i];
        ans = i;
      }
    }
    return ans;
  }
};
