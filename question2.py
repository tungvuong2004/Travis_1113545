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

import heapq

class TaskPriorityQueue:
    def __init__(self):
        self.heap = []  # Max heap (using negative priority to simulate max heap)

    def add_task(self, task_name, priority):
        # Push a task into the heap with negative priority (to simulate max heap)
        heapq.heappush(self.heap, (-priority, task_name))

    def get_highest_priority_task(self):
        if not self.heap:
            return None
        # Pop the task with the highest priority
        priority, task_name = heapq.heappop(self.heap)
        return task_name

    def get_remaining_tasks(self):
        # Convert the heap to a sorted list (descending order of priority)
        return [(task_name, -priority) for priority, task_name in sorted(self.heap, reverse=True)]

# Input handling
n = int(input("Enter the number of operations: "))
priority_queue = TaskPriorityQueue()
output = []

for _ in range(n):
    operation = input().strip().split()
    if operation[0] == "ADD":
        task_name = operation[1]
        priority = int(operation[2])
        priority_queue.add_task(task_name, priority)
    elif operation[0] == "GET":
        task = priority_queue.get_highest_priority_task()
        if task:
            output.append(task)
        else:
            output.append("No tasks available.")

# Display "GET" outputs
for task in output:
    print(task)

# Display the remaining tasks
remaining_tasks = priority_queue.get_remaining_tasks()
print("Remaining tasks:", remaining_tasks)

