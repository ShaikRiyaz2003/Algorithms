#include <bits/stdc++.h>
using namespace std;
int dp [1000] = {0};
int minCoins(int N, int M,int coins[])
{
    for(int i = 0;i<=N;i++)
        dp[i] = INT_MAX;
    dp[0] = 0;
    for(int i = 1;i<=N;i++)
    {
        for(int j = 0;j<M;j++)
        {
            if(coins[j] <= i)
            {
                dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
            }
        }
    }
    return dp[N];
}
int main() 
{
    int n;
    cin>>n;
    do
    {
        int sum ,total_coins;
        cin>>sum>>total_coins;
        int coins[total_coins];
        for(int i=0;i<total_coins;i++)
        cin>>coins[i];
        cout<<"Minimum coins reqired: "<< minCoins(sum, total_coins,coins);
        n--;
    }while(n!=0);

}


/*

0 1 2 3 4 ... n
*/