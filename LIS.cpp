#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>arr, int n){
    vector<int>lis(n,1);
    for(int i=1;i<n;i++)
        for(int j=0;j<i;j++)
            if(arr[i]>arr[j]&&lis[i]<lis[j]+1)
                lis[i]=1+lis[j+1];
    // for(auto i: lis)
    //     cout<<i<<" ";
    
    return *max_element(lis.begin(),lis.end());

}
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i : arr)
        cin>>i;
    int LIS = solve(arr,n);
    cout<<"LIS count="<<LIS;
    return 0;
}