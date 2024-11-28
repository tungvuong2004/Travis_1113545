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

import heapq

def schedule_tasks_with_deadlines(tasks):
    # Sort tasks by profit in descending order
    tasks.sort(key=lambda x: x[0], reverse=True)

    # Find the maximum deadline
    max_deadline = max(task[1] for task in tasks)

    # Initialize a result array to track scheduled tasks
    result = [None] * max_deadline

    total_profit = 0

    for profit, deadline in tasks:
        # Try to schedule the task in the latest available slot before or on its deadline
        for i in range(min(deadline, max_deadline) - 1, -1, -1):
            if result[i] is None:
                result[i] = profit
                total_profit += profit
                break

    # Filter out None values to get the list of scheduled tasks
    scheduled_tasks = [task for task in result if task is not None]

    return total_profit, scheduled_tasks

# Input handling
n = int(input("Enter the number of tasks: "))
tasks = []

for _ in range(n):
    profit, deadline = map(int, input("Enter profit and deadline: ").split())
    tasks.append((profit, deadline))

# Schedule tasks
max_profit, scheduled_tasks = schedule_tasks_with_deadlines(tasks)

# Output results
print("Maximum Profit:", max_profit)
print("Scheduled Tasks:", scheduled_tasks)
