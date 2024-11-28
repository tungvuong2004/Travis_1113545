/*
 * Name: Travis
 * Student ID: 1113545
 * Date of Submission: 11/28/2024
 *
 * Program to merge K sorted arrays into a single sorted array using a Min Priority Queue.
 * Features:
 * 1. Insert the first element of each array into the Min Priority Queue.
 * 2. Extract the smallest element, add it to the result array, and insert the next element from the same array.
 * 3. Repeat until all elements are merged.
 */

import heapq

def merge_k_sorted_arrays(arrays):
    # Create a min-heap
    min_heap = []
    result = []

    # Insert the first element of each array into the heap
    for i, array in enumerate(arrays):
        if array:  # Ensure the array is not empty
            heapq.heappush(min_heap, (array[0], i, 0))  # (value, array_index, element_index)

    # Process the heap
    while min_heap:
        value, array_index, element_index = heapq.heappop(min_heap)
        result.append(value)  # Add the smallest element to the result
        next_element_index = element_index + 1

        # If there are more elements in the same array, add the next element to the heap
        if next_element_index < len(arrays[array_index]):
            heapq.heappush(min_heap, (arrays[array_index][next_element_index], array_index, next_element_index))

    return result

# Input handling
k = int(input("Enter the number of sorted arrays: "))
arrays = []

for _ in range(k):
    array = list(map(int, input("Enter a sorted array: ").split()))
    arrays.append(array)

# Merge the arrays
merged_array = merge_k_sorted_arrays(arrays)

# Print the result
print("Merged Array:", merged_array)
