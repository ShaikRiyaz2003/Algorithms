#include<bits/stdc++.h>
using namespace std;
int min_sum=INT_MAX;
vector<int>ans[2];// ans[0]->set1 , ans[1]->set2
void solve(vector<int>arr,int idx, vector<int> set1,vector<int> set2, int soset1,int soset2){
    // base condition
    if(idx==arr.size()){
        if(min_sum>fabs(soset1-soset2)){
            min_sum=fabs(soset1-soset2);
            ans[0]=set1;
            ans[1]=set2;
        }
    }
    //for set1
    if(set1.size()<(arr.size()+1)/2){
        set1.push_back(arr[idx]);
        solve(arr,idx+1,set1,set2,soset1+arr[idx],soset2);
        set1.pop_back();
    }
    //for set2
    if(set2.size()<(arr.size()+1)/2){
        set2.push_back(arr[idx]);
        solve(arr,idx+1,set1,set2,soset1,soset2+arr[idx]);
        set2.pop_back();
    }

}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto &i: arr)
        cin>>i;
    solve(arr,0,vector<int>(),vector<int>(),0,0);
// /*
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    cout<<accumulate(ans[i].begin(),ans[i].end(),0)<<endl;
    }
// */
        
    
    for(auto i: ans){
        for(auto j: i)
            cout<<j<<" ";
        cout<<endl;
    cout<<accumulate(i.begin(),i.end(),0)<<endl;
    }
    cout<<min_sum;
 return 0;
}














// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> DP SOLUTION <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<


// #include <bits/stdc++.h>
// using namespace std;

// int N;
// int W[100 + 5];
// long long dp[450 * 100 + 5];

// void solve()
// {
//     int sum = accumulate(W + 1, W + N + 1, 0);
//     memset(dp, 0, sizeof(dp));
//     dp[0] = 1 << 0;
        
//     for (int i = 1; i <= N; ++i)
//         for (int j = sum; j >= 0; --j)
//             if (dp[j])
//                 dp[j + W[i]] |= dp[j] << 1;
    
//     int minDiff = 450 * 100;
//     int teamOneWeight = 0, teamTwoWeight = 0;
//     for (int i = 0; i <= sum; ++i)
//         if (dp[i] & (1ll << (N / 2)))
//         {
//             int diff = abs(i - (sum - i));
//             if (diff < minDiff)
//             {
//                 minDiff = diff;
//                 teamOneWeight = min(i, sum - i);
//                 teamTwoWeight = max(i, sum - i);
//             }
//         }
//     cout << teamOneWeight << " " << teamTwoWeight << endl;
// }

// int main()
// {
//     int T, Case = 0;
//     cin >> T;
//     while ( T-- )
//     {
//         cin >> N;
//         for (int i = 1; i <= N; ++i)
//             cin >> W[i];
        
//         if (++Case > 1)
//             cout << endl;
//         solve();
//     }
// }