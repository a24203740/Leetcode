#include "../includes.hpp"
#include <algorithm>
#include <queue>
#include <utility>

using packet = pair<int, int>;           // timestamp, source/destination
using fullpacket = tuple<int, int, int>; // timestamp, source, destination
class Router {
public:
  vector<deque<packet>> queues;
  queue<fullpacket> totalSet;
  set<fullpacket> lookupTable;
  map<int, int> destToQueues;
  int limit;
  Router(int memoryLimit) { 
    limit = memoryLimit; 
    queues.reserve(memoryLimit);
  }

  // void output(int dest) {
  //   cout << "dest " << dest << endl;
  //   if(destToQueues.count(dest) == 0)return;
  //   auto &q = queues[destToQueues[dest]];
  //   for(auto [t, s]: q) {
  //     cout << t << " " << s << endl;
  //   }
  //   cout << "=====" << endl;
  // }

  void removeFirst() {
    if (totalSet.empty())
      return;
    auto tp = totalSet.front();
    lookupTable.erase(tp);
    auto [t, s, d] = tp;
    totalSet.pop();
    auto& qmap = queues[destToQueues[d]];
    auto [t1, s1] = qmap.front();
    qmap.pop_front();
  }

  bool addPacket(int source, int destination, int timestamp) {
    auto tp = make_tuple(timestamp, source, destination);
    if (lookupTable.count(tp)) return false;
    int qidx;
    if (!destToQueues.count(destination)) {
      queues.push_back(deque<packet>());
      qidx = queues.size() - 1;
      destToQueues.emplace(destination, queues.size() - 1);
    } else {
      qidx = destToQueues[destination];
    }
    packet packetPair = make_pair(timestamp, source);
    auto& q = queues[qidx];
    q.emplace_back(timestamp, source);
    totalSet.emplace(tp);
    lookupTable.emplace(tp);
    if (totalSet.size() > limit) {
      removeFirst();
    }
    return true;
  }

  vector<int> forwardPacket() {
    if(totalSet.empty())return vector<int>{};
    auto [t, s, d] = totalSet.front();
    removeFirst();
    return vector<int>{s, d, t};
  }

  int getCount(int destination, int startTime, int endTime) {
    if (!destToQueues.count(destination))
      return 0;
    const auto& l = queues[destToQueues[destination]];
    auto rit = lower_bound(l.begin(), l.end(), make_pair(endTime + 1, 0));
    auto lit = lower_bound(l.begin(), l.end(), make_pair(startTime, 0));
    return rit - lit;
  }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */
