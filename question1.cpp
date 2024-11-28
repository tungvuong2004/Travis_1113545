/*
 * Name: Travis
 * Student ID: 1113545
 * Date of Submission: 11/28/2024
 *
 * Program to calculate the diameter of a binary tree.
 * The diameter of a binary tree is the length of the longest path between any two nodes.
 * The path may or may not pass through the root.
 */

#include <iostream>
#include <queue>
#include <vector>
#include <sstream>
#include <climits>
using namespace std;

// Definition of the binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to build a binary tree from level-order input
TreeNode* buildTree(const vector<int>& nodes) {
    if (nodes.empty() || nodes[0] == -1) return nullptr;

    // Create the root node
    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q; // Queue to manage nodes while constructing the tree
    q.push(root);

    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* current = q.front();
        q.pop();

        // Add left child if it's not null
        if (nodes[i] != -1) {
            current->left = new TreeNode(nodes[i]);
            q.push(current->left);
        }
        i++;

        // Add right child if it's not null
        if (i < nodes.size() && nodes[i] != -1) {
            current->right = new TreeNode(nodes[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

// Helper function to calculate the diameter of the binary tree
int diameterHelper(TreeNode* root, int& diameter) {
    if (!root) return 0; // Base case: if the node is null, height is 0

    // Recursively find the height of the left and right subtrees
    int leftHeight = diameterHelper(root->left, diameter);
    int rightHeight = diameterHelper(root->right, diameter);

    // Update the diameter if the sum of left and right heights is greater
    diameter = max(diameter, leftHeight + rightHeight);

    // Return the height of the current subtree
    return max(leftHeight, rightHeight) + 1;
}

// Function to calculate the diameter of the binary tree
int calculateDiameter(TreeNode* root) {
    int diameter = 0; // Initialize diameter to 0
    diameterHelper(root, diameter); // Helper function to calculate diameter
    return diameter;
}

int main() {
    // Input: Level-order traversal of the binary tree
    string input;
    cout << "Enter level-order traversal (use -1 for null nodes): ";
    getline(cin, input);
    stringstream ss(input);
    vector<int> nodes;
    int value;

    // Parse the input and store it in a vector
    while (ss >> value) {
        nodes.push_back(value);
    }

    // Build the binary tree
    TreeNode* root = buildTree(nodes);

    // Calculate and print the diameter of the binary tree
    int diameter = calculateDiameter(root);
    cout << "Diameter of the binary tree: " << diameter << endl;

    return 0;
}
