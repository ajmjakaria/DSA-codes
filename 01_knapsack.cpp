#include<bits/stdc++.h>
using namespace std;
int dp[10][10];

int knapsack_01(int n, int w, int profit[], int wt[])
{
	if(n == 0 || w == 0) return 0; //base case
	if(dp[n][w] != -1) return dp[n][w];
 
	if(wt[n-1] > w) 
		return dp[n][w] = knapsack_01(n-1, w, profit, wt);
	else
		return dp[n][w] = max(knapsack_01(n-1, w, profit, wt),
			profit[n-1]+knapsack_01(n-1, w-wt[n-1], profit, wt));
}
int main()
{
	int profit[] = {1, 7, 11};
	int wt[] = {1,2,3};
	int w = 5;
	memset(dp, -1, sizeof(dp));
	int n = sizeof(profit)/sizeof(profit[0]);
	cout << knapsack_01(n, w, profit, wt) << endl;
	return 0;
}
