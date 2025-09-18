#include <bits/stdc++.h>
using namespace std;

struct Task {
    int userId;
    int taskId;
    int priority;
    Task() = default;
    Task(int u, int t, int p) : userId(u), taskId(t), priority(p) {}
    // We want the set to have highest priority first.
    // If priorities tie, choose larger taskId first.
    bool operator<(const Task &other) const {
        if (priority != other.priority) return priority > other.priority;
        return taskId > other.taskId;
    }
};

class TaskManager {
    // map: taskId -> (userId, priority)
    unordered_map<int, pair<int,int>> mp;
    // ordered set of tasks by (priority desc, taskId desc)
    set<Task> s;

public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto &t : tasks) {
            int user = t[0], id = t[1], pr = t[2];
            mp[id] = {user, pr};
            s.insert(Task(user, id, pr));
        }
    }

    void add(int userId, int taskId, int priority) {
        mp[taskId] = {userId, priority};
        s.insert(Task(userId, taskId, priority));
    }

    void edit(int taskId, int newPriority) {
        auto it = mp.find(taskId);
        if (it == mp.end()) return; // problem statement guarantees existence; defensive
        int user = it->second.first;
        int oldP = it->second.second;
        // remove old Task from set
        s.erase(Task(user, taskId, oldP));
        // update map and set
        it->second.second = newPriority;
        s.insert(Task(user, taskId, newPriority));
    }

    void rmv(int taskId) {
        auto it = mp.find(taskId);
        if (it == mp.end()) return; // defensive
        int user = it->second.first;
        int pr = it->second.second;
        s.erase(Task(user, taskId, pr));
        mp.erase(it);
    }

    int execTop() {
        if (s.empty()) return -1;
        auto it = s.begin();            // highest priority, then highest taskId
        int user = it->userId;
        int id = it->taskId;
        s.erase(it);
        mp.erase(id);
        return user;
    }
};
