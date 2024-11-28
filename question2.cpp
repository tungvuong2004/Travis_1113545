/*
 * Name: Travis
 * Student ID: 1113545
 * Date of Submission: 11/28/2024
 *
 * Program to manage a task priority queue using a max heap.
 * Features:
 * 1. Add tasks with a given priority.
 * 2. Fetch the task with the highest priority.
 * 3. Display remaining tasks in descending order of priority.
 */

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

// Structure to represent a task
struct Task {
    string name;
    int priority;

    // Constructor
    Task(string n, int p) : name(n), priority(p) {}

    // Comparator for max-heap
    bool operator<(const Task& other) const {
        return priority < other.priority; // Higher priority comes first
    }
};

// Class to manage the priority queue
class TaskPriorityQueue {
private:
    priority_queue<Task> maxHeap; // Max heap to manage tasks

public:
    // Add a task to the queue
    void addTask(const string& taskName, int priority) {
        maxHeap.push(Task(taskName, priority));
    }

    // Get the task with the highest priority
    string getHighestPriorityTask() {
        if (maxHeap.empty()) return "No tasks available.";
        
        Task topTask = maxHeap.top(); // Get the highest-priority task
        maxHeap.pop(); // Remove the task from the heap
        return topTask.name;
    }

    // Get remaining tasks in descending order of priority
    vector<pair<string, int>> getRemainingTasks() {
        vector<pair<string, int>> remainingTasks;
        while (!maxHeap.empty()) {
            Task task = maxHeap.top();
            remainingTasks.emplace_back(task.name, task.priority);
            maxHeap.pop();
        }

        // Rebuild the max heap to maintain state
        for (const auto& task : remainingTasks) {
            maxHeap.push(Task(task.first, task.second));
        }

        return remainingTasks;
    }
};

int main() {
    // Input the number of operations
    int n;
    cout << "Enter the number of operations: ";
    cin >> n;

    TaskPriorityQueue taskQueue;
    string operation;
    vector<string> outputs;

    // Process operations
    for (int i = 0; i < n; ++i) {
        cin >> operation;

        if (operation == "ADD") {
            string taskName;
            int priority;
            cin >> taskName >> priority;
            taskQueue.addTask(taskName, priority);
        } else if (operation == "GET") {
            outputs.push_back(taskQueue.getHighestPriorityTask());
        } else {
            cout << "Invalid operation: " << operation << endl;
        }
    }

    // Print results of "GET" operations
    for (const auto& output : outputs) {
        cout << output << endl;
    }

    // Print remaining tasks
    vector<pair<string, int>> remainingTasks = taskQueue.getRemainingTasks();
    cout << "Remaining tasks: [";
    for (size_t i = 0; i < remainingTasks.size(); ++i) {
        cout << "('" << remainingTasks[i].first << "', " << remainingTasks[i].second << ")";
        if (i < remainingTasks.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
