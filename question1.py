/*
 * Name: Travis
 * Student ID: 1113545
 * Date of Submission: 11/28/2024
 *
 * Program to calculate the diameter of a binary tree.
 * The diameter of a binary tree is the length of the longest path between any two nodes.
 * The path may or may not pass through the root.
 */

class TreeNode:
    def __init__(self, value):
        self.val = value
        self.left = None
        self.right = None

def build_tree(level_order):
    if not level_order or level_order[0] == -1:
        return None
    root = TreeNode(level_order[0])
    queue = [root]
    i = 1
    while i < len(level_order):
        current = queue.pop(0)
        if level_order[i] != -1:
            current.left = TreeNode(level_order[i])
            queue.append(current.left)
        i += 1
        if i < len(level_order) and level_order[i] != -1:
            current.right = TreeNode(level_order[i])
            queue.append(current.right)
        i += 1
    return root

def diameter_of_binary_tree(root):
    diameter = [0]  # Use a list to store the diameter as a mutable object

    def height(node):
        if not node:
            return 0
        left_height = height(node.left)
        right_height = height(node.right)
        # Update diameter as the number of nodes on the longest path
        diameter[0] = max(diameter[0], left_height + right_height + 1)
        return 1 + max(left_height, right_height)

    height(root)  # Initiates the height calculation and updates the diameter
    return diameter[0]

# Input handling
level_order = list(map(int, input("Enter the level-order traversal of the tree (comma-separated): ").replace(",", " ").split()))
root = build_tree(level_order)

# Calculate and print the diameter
print(diameter_of_binary_tree(root))

