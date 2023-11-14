#include<bits/stdc++.h>
using namespace std;
int solve(string from, string to){
    int flen=from.size(),tlen=to.size();
    if(flen==0)
        return tlen;
    if(tlen==0)
        return flen;
    vector<vector<int>> dp(flen+1,vector<int>(tlen+1,0));
    for(int i=0;i<=flen;i++)
        dp[i][0]=i;
    for(int i=0;i<=tlen;i++)
        dp[0][i]=i;
    for(int i=1;i<=flen;i++){
        for(int j=1;j<=tlen;j++){
            if(from[i-1]==to[j-1])
                dp[i][j]=dp[i-1][j-1];
            else
                dp[i][j]=1+
                    min(dp[i-1][j-1],min(
                        dp[i][j-1],dp[i-1][j]
                    ));
        }
    }
    return dp[flen][tlen];
    //Showing DP array

    // for (int i = 0; i < flen; i++)
    // {
    //     for (int j = 0; j < tlen; j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
        
    // }
    
}
int main()
{
    string from,to;
    cin>>from>>to;
    cout<<solve(from,to);
    return 0;
}