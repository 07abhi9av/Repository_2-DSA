0-1 KNAPSACK ALGORITHM
You are given N items that cannot be broken. Each item has a weight and value associated with it.
You also have a KnapSack of capacity W.
Find the maximum value of items you can collect in the KnapSack so that the total weight does not exceed W.
Input
First line contains the values N and W.
Second line contains N integers denoting the weights.
Last line contains N integers denoting the values.
Output
Print the maximum value that can be collected with total weight less than or equal to W.

Example
Input:
3 5
1 2 3
1 5 3

Output:
8


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