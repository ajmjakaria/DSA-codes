//Author: Abu Jafar Md Jakaria

#include<bits/stdc++.h>
using namespace std;

#define mx 100  // Define the maximum value for n and r
#define p 1000000007  // Define a large prime number for modulo operation to avoid overflow

int dp[mx][mx];

// Function to calculate nCr using dynamic programming with memoization
int nCr(int n, int r)
{
	// Base cases for nCr
	if(n == r) dp[n][r] = 1;  // If n == r, nCr is 1 (only one way to choose all items)
	if(r == 1) dp[n][r] = n;  // If r == 1, nCr is n (n ways to choose one item)
	if(r == 0) dp[n][r] = 1;  // If r == 0, nCr is 1 (only one way to choose none)

	// If the value is not yet computed
	if(dp[n][r] == -1) 
		dp[n][r] = (nCr(n - 1, r - 1) % p + nCr(n - 1, r) % p) % p;
	// Recurrence relation: nCr = (n-1)Cr-1 + (n-1)Cr, with modulo operation for large results

	return dp[n][r];  // Return the computed value of nCr
}

int main()
{
	// Initialize the dp array with -1 indicating uncomputed values
	memset(dp, -1, sizeof(dp));
	
	int n, r; 
	cin >> n >> r;
	
	// Check for valid input where n should be greater than or equal to r
	if(n > r)
		cout << nCr(n, r);  // Call nCr function and print result if input is valid
	else
		cout << "Invalid Input\n";
	
	return 0;
}
