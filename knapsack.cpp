#include <iostream>
using namespace std;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    int weight[n], value[n];

    cout << "Enter weights:\n";
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }

    cout << "Enter values:\n";
    for (int i = 0; i < n; i++) {
        cin >> value[i];
    }

    cout << "Enter knapsack capacity: ";
    cin >> W;

    // DP table
    int dp[n + 1][W + 1];

    int operations = 0;

    // Build table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            operations++;

            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            }
            else if (weight[i - 1] <= w) {
                dp[i][w] = max(
                    value[i - 1] + dp[i - 1][w - weight[i - 1]],
                    dp[i - 1][w]
                );
            }
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << "\nMaximum value = " << dp[n][W] << endl;

    // Trace back selected items
    cout << "Selected items (index): ";
    int w = W;
    for (int i = n; i > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            cout << i - 1 << " ";
            w -= weight[i - 1];
        }
    }

    cout << "\nOperations performed: " << operations << endl;

    return 0;
}