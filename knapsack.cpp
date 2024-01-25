#include <iostream>
#include <vector>

// Structure to represent an item
struct Item {
    int weight;
    int value;
};

// Function to solve the 0/1 Knapsack problem using dynamic programming
int knapsack(const std::vector<Item>& items, int capacity) {
    int n = items.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= capacity; ++w) {
            if (items[i - 1].weight <= w) {
                dp[i][w] = std::max(dp[i - 1][w], items[i - 1].value + dp[i - 1][w - items[i - 1].weight]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    std::vector<Item> items = {{2, 3}, {3, 4}, {4, 5}, {5, 6}};
    int capacity = 5;

    int maxValue = knapsack(items, capacity);

    std::cout << "Maximum value in Knapsack: " << maxValue << std::endl;

    return 0;
}