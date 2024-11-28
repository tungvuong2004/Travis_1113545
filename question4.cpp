/*
 * Name: Travis
 * Student ID: 1113545
 * Date of Submission: 11/28/2024
 *
 * Program to schedule tasks with deadlines using a Max Priority Queue.
 * Features:
 * 1. Prioritize tasks with higher profit.
 * 2. Ensure deadlines are respected while maximizing profit.
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// Structure to represent a task
struct Task {
    int profit;   // Profit of the task
    int deadline; // Deadline of the task

    // Constructor
    Task(int p, int d) : profit(p), deadline(d) {}
};

// Comparator for sorting tasks by profit in descending order
bool compareTasks(const Task& t1, const Task& t2) {
    return t1.profit > t2.profit;
}

// Function to schedule tasks to maximize profit
pair<int, vector<int>> scheduleTasks(vector<Task>& tasks, int n) {
    // Step 1: Sort tasks by profit in descending order
    sort(tasks.begin(), tasks.end(), compareTasks);

    // Step 2: Initialize variables
    int maxDeadline = 0;
    for (const auto& task : tasks) {
        maxDeadline = max(maxDeadline, task.deadline);
    }

    vector<int> timeSlots(maxDeadline + 1, -1); // Slots for tasks (-1 indicates free slot)
    vector<int> scheduledTasks; // To store profits of scheduled tasks
    int totalProfit = 0;

    // Step 3: Schedule tasks
    for (const auto& task : tasks) {
        // Try to schedule the task in the latest available slot before its deadline
        for (int slot = task.deadline; slot > 0; --slot) {
            if (timeSlots[slot] == -1) {
                timeSlots[slot] = task.profit; // Assign the task to this slot
                scheduledTasks.push_back(task.profit); // Record the profit
                totalProfit += task.profit; // Add the profit to the total
                break;
            }
        }
    }

    return {totalProfit, scheduledTasks};
}

int main() {
    // Input: Number of tasks
    int n;
    cout << "Enter the number of tasks: ";
    cin >> n;

    vector<Task> tasks;

    // Input: Profit and deadline for each task
    cout << "Enter profit and deadline for each task (separated by a space):" << endl;
    for (int i = 0; i < n; i++) {
        int profit, deadline;
        cin >> profit >> deadline;
        tasks.emplace_back(profit, deadline);
    }

    // Schedule tasks and calculate maximum profit
    auto result = scheduleTasks(tasks, n);

    // Output the results
    cout << "Maximum Profit: " << result.first << endl;
    cout << "Scheduled Tasks: [";
    for (size_t i = 0; i < result.second.size(); i++) {
        cout << result.second[i];
        if (i < result.second.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
