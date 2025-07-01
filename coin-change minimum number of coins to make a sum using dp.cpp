//Author: Abu Jafar Md Jakaria
//coin change-count minimum number of coins to make a sum using dp
#include<bits/stdc++.h>
using namespace std;
#define mx 1000
int dp[mx][mx];

int minCoins(int coins[], int n, int target_amount)
{
	if (target_amount == 0) return 0; // make the sum already
	if(target_amount < 0 || n == 0) return 1e9; // impossible to make sum

	if(dp[n][target_amount] == -1)
		dp[n][target_amount]= min(minCoins(coins, n, target_amount-coins[n-1])+1,
			minCoins(coins, n-1, target_amount));

	return dp[n][target_amount];
}

int main()
{
	int coins[] = {1, 2, 3};
	int n = 3;
	int target_amount = 5;
	memset(dp, -1, sizeof(dp));

	cout << minCoins(coins, n, 5) << endl;
	return 0;
}
