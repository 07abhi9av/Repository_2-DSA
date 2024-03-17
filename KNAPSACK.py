# 0-1 KNAPSACK ALGORITHM
# You are given N items that cannot be broken. Each item has a weight and value associated with it.
# You also have a KnapSack of capacity W.
# Find the maximum value of items you can collect in the KnapSack so that the total weight does not exceed W.
# Input
# First line contains the values N and W.
# Second line contains N integers denoting the weights.
# Last line contains N integers denoting the values.
# Output
# Print the maximum value that can be collected with total weight less than or equal to W.

# Example
# Input:
# 3 5
# 1 2 3
# 1 5 3

# Output:
# 8


def knapsack(N, W, weights, values):
    dp = [[0] * (W + 1) for _ in range(N + 1)]

    for i in range(1, N + 1):
        for w in range(1, W + 1):
            if weights[i - 1] <= w:
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]])
            else:
                dp[i][w] = dp[i - 1][w]

    return dp[N][W]

# Input
N, W = map(int, input().split())
weights = list(map(int, input().split()))
values = list(map(int, input().split()))

# Output
print(knapsack(N, W, weights, values))


SUM ROOT TO LEAF NODES
Given a binary tree, where every node value is a Digit from 1-9. Find the sum of all the numbers which are formed from root to leaf paths.

For example, consider the following Binary Tree. 
63525N4NN74
There are 4 leaves, hence 4 root to leaf paths:

   Path                      Number

  6->3->2                     632

  6->3->5->7                 6357

  6->3->5->4                 6354

  6->5>4                      654   

Answer = 632 + 6357 + 6354 + 654 = 13997
Example
Input:

123456789
Output:

2895


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def construct_binary_tree(input_str):
    def build_tree(index):
        if index >= len(input_str) or input_str[index] == 'N':
            return None
        node = TreeNode(int(input_str[index]))
        node.left = build_tree(2 * index + 1)
        node.right = build_tree(2 * index + 2)
        return node

    return build_tree(0)

def sum_root_to_leaf(root, current_sum=0):
    if not root:
        return 0
    
    current_sum = current_sum * 10 + root.val
    
    if not root.left and not root.right:
        return current_sum
    
    left_sum = sum_root_to_leaf(root.left, current_sum)
    right_sum = sum_root_to_leaf(root.right, current_sum)
    
    return left_sum + right_sum

# Example usage:
input_str = input("Enter the binary tree in level order format with 'N' representing null nodes: ")
root = construct_binary_tree(input_str)
result = sum_root_to_leaf(root)
print("Sum of all numbers formed from root to leaf paths:", result)