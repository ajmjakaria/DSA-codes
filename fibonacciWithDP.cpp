// Fibonacci series with DP
#include<bits/stdc++.h>
using namespace std;
const int mx = 1e5;
long long mod = 100000007;
long long dp[mx];
long long fibo(int n)
{
    if(n==0 || n==1){
        return n;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    else{
        dp[n] = ((fibo(n-1) %mod )+ (fibo(n-2) % mod)) % mod;
        return dp[n];
    }
}
int main()
{
    memset(dp, -1, sizeof(dp));  
    int n;                
    cin>>n;
    // To print n fibonacci numbers
    for( int i = 0; i < n; i++)
        cout << fibo(i) << " ";
        
    // To print nth fibonacci number
    // cout<<fibo(n)<<endl;
    return 0;
}
