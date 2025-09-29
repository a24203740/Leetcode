#include "../includes.hpp"

using pii = pair<int, int>;
class TaskManager {
public:
  map<pii, int> tasksMap; // priority -> taskID, userID
  unordered_map<int, map<pii, int>::iterator> taskIdMap; // taskID -> iterator
  TaskManager(vector<vector<int>> &tasks) {
    taskIdMap.reserve(tasks.size() + 1);
    for (auto &task : tasks) {
      int userId = task[0], taskId = task[1], priority = task[2];
      auto it = tasksMap.emplace(make_pair(priority, taskId), userId).first;
      taskIdMap[taskId] = it;
    }
  }
  void add(int userId, int taskId, int priority) {
    auto it = tasksMap.emplace(make_pair(priority, taskId), userId).first;
    taskIdMap[taskId] = it;
  }

  void edit(int taskId, int newPriority) {
    auto oldIt = taskIdMap[taskId];
    int oldPriority = oldIt->first.first;
    if (oldPriority == newPriority)
      return;
    int userId = oldIt->second;
    tasksMap.erase(oldIt);
    auto newIt = tasksMap.emplace(make_pair(newPriority, taskId), userId).first;
    taskIdMap[taskId] = newIt;
  }

  void rmv(int taskId) {
    auto oldIt = taskIdMap[taskId];
    tasksMap.erase(oldIt);
    taskIdMap.erase(taskId);
  }

  int execTop() {
    auto highestTask = tasksMap.rbegin();
    if (highestTask == tasksMap.rend())
      return -1;
    int priority = highestTask->first.first;
    int taskId = highestTask->first.second;
    int userId = highestTask->second;
    this->rmv(taskId);
    return userId;
  }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
