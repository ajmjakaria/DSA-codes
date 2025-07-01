#include<bits/stdc++.h>
using namespace std;

#define mx 1000  // Define the maximum size for memoization array
int dp[mx][mx];

int counts(int coins[], int n, int target_amount)
{
	// Base case: If target amount is 0, there's one way to make it (by choosing no coins)
	if (target_amount == 0) 
		dp[n][target_amount] = 1;

	// Base case: If target amount is negative or no coins are left, no solution exists
	if (target_amount < 0 || n == 0) 
		dp[n][target_amount] = 0;

	// Check if the result has already been computed (memoization)
	if(dp[n][target_amount] == -1)
		// Recursive relation: either include the current coin or exclude it
		dp[n][target_amount] = counts(coins, n, target_amount - coins[n-1]) + 
		                       counts(coins, n - 1, target_amount);

	return dp[n][target_amount];
}

int main()
{
	int coins[] = {1, 2, 3};  // Array representing the coin denominations
	int n = 3;  // Number of coin types
	int target_amount = 5;  // Target amount to achieve with coins

	// Initialize dp array with -1 to indicate uncomputed values
	memset(dp, -1, sizeof(dp));

	// Call the counts function to get the number of ways to make the target amount
	cout << counts(coins, n, target_amount) << endl;

	return 0;
}
