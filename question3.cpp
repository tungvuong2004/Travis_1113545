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

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Custom structure to represent heap elements
struct HeapNode {
    int value;     // Value of the element
    int arrayIdx;  // Index of the array
    int elemIdx;   // Index of the element in the array

    // Comparator for the Min Priority Queue
    bool operator>(const HeapNode& other) const {
        return value > other.value;
    }
};

// Function to merge K sorted arrays
vector<int> mergeKSortedArrays(vector<vector<int>>& arrays) {
    // Min heap to store the elements
    priority_queue<HeapNode, vector<HeapNode>, greater<HeapNode>> minHeap;

    // Step 1: Insert the first element of each array into the Min Priority Queue
    for (int i = 0; i < arrays.size(); i++) {
        if (!arrays[i].empty()) { // Ensure the array is not empty
            minHeap.push({arrays[i][0], i, 0});
        }
    }

    // Result array to store the merged sorted elements
    vector<int> result;

    // Step 2: Process the heap until it is empty
    while (!minHeap.empty()) {
        // Extract the smallest element
        HeapNode top = minHeap.top();
        minHeap.pop();
        result.push_back(top.value);

        // Insert the next element from the same array into the heap
        if (top.elemIdx + 1 < arrays[top.arrayIdx].size()) {
            minHeap.push({arrays[top.arrayIdx][top.elemIdx + 1], top.arrayIdx, top.elemIdx + 1});
        }
    }

    return result;
}

int main() {
    // Input number of sorted arrays
    int K;
    cout << "Enter the number of sorted arrays: ";
    cin >> K;

    vector<vector<int>> arrays(K);

    // Input each sorted array
    for (int i = 0; i < K; i++) {
        cout << "Enter elements of array " << i + 1 << " separated by spaces (end with -1): ";
        int val;
        while (cin >> val && val != -1) {
            arrays[i].push_back(val);
        }
    }

    // Merge the sorted arrays
    vector<int> mergedArray = mergeKSortedArrays(arrays);

    // Output the merged array
    cout << "Merged Array: [";
    for (size_t i = 0; i < mergedArray.size(); i++) {
        cout << mergedArray[i];
        if (i < mergedArray.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
