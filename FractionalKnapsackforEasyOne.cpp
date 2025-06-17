#include <bits/stdc++.h>
using namespace std;

// Function to calculate value/weight ratio and sort accordingly
void fractionalKnapsack(int n, float value[], float weight[], float capacity) {
    int index[n];
    for (int i = 0; i < n; i++)
        index[i] = i;

    // Sort items by value/weight ratio in descending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            float r1 = value[index[i]] / weight[index[i]];
            float r2 = value[index[j]] / weight[index[j]];
            if (r1 < r2) {
                swap(index[i], index[j]);
                
                // int temp = index[i];
                // index[i] = index[j];
                // index[j] = temp;
            }
        }
    }

    float totalValue = 0.0;

    cout << "Items taken (value, weight taken):\n";

    for (int i = 0; i < n && capacity > 0; i++) {
        int item = index[i];
        if (weight[item] <= capacity) {
            // Take full item
            capacity -= weight[item];
            totalValue += value[item];
            cout << value[item] << " " << weight[item] << endl;
        } else {
            // Take fraction of item
            float fraction = capacity / weight[item];
            totalValue += value[item] * fraction;
            cout << value[item] << " " << capacity << " (fraction taken)\n";
            capacity = 0; // Knapsack full
        }
    }

    cout << "\nMaximum total value: " << totalValue << endl;
}

int main() {
    int n = 3;
    float value[] = {60, 100, 120};
    float weight[] = {10, 20, 30};
    float capacity = 50;

    fractionalKnapsack(n, value, weight, capacity);
    return 0;
}
