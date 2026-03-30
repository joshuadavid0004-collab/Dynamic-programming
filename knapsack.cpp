#include <iostream>
using namespace std;

// Custom max function (we avoid built-in algorithm library)
// Returns the larger of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {

    // n = number of items
    // W = capacity of the knapsack
    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    // Arrays to store weight and value of each item
    int weight[n], value[n];

    // Input weights
    cout << "Enter weights:\n";
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }

    // Input values
    cout << "Enter values:\n";
    for (int i = 0; i < n; i++) {
        cin >> value[i];
    }

    // Input knapsack capacity
    cout << "Enter knapsack capacity: ";
    cin >> W;

    // DP table:
    // rows = items (0..n)
    // columns = capacity (0..W)
    // dp[i][w] = maximum value using first i items and capacity w
    int dp[n + 1][W + 1];

    // Counter to measure number of operations
    int operations = 0;

    // Build the DP table row by row
    for (int i = 0; i <= n; i++) {        // loop through items
        for (int w = 0; w <= W; w++) {    // loop through capacities
            operations++;                 // count each cell computation

            // Base case:
            // If no items OR capacity = 0 → value = 0
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            }

            // If current item fits into current capacity
            else if (weight[i - 1] <= w) {

                // Option 1: Take the item
                int take = value[i - 1] + dp[i - 1][w - weight[i - 1]];

                // Option 2: Leave the item
                int leave = dp[i - 1][w];

                // Choose the better option
                dp[i][w] = max(take, leave);
            }

            // If item cannot fit → we must skip it
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Final answer is bottom-right cell
    cout << "\nMaximum value = " << dp[n][W] << endl;

    // -------------------------------------------------------
    // Backtracking to find which items were selected
    // -------------------------------------------------------
    cout << "Selected items (index): ";

    int w = W;  // start from full capacity

    // Move backwards through the table
    for (int i = n; i > 0; i--) {

        // If value changed from previous row,
        // it means item i-1 was included
        if (dp[i][w] != dp[i - 1][w]) {
            cout << i - 1 << " ";      // print item index
            w -= weight[i - 1];        // reduce remaining capacity
        }
    }

    // Display performance metric
    cout << "\nOperations performed: " << operations << endl;

    return 0;
}
