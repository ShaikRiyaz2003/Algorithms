#include<bits/stdc++.h>
using namespace std;
void solve(vector<int>arr,int n){
    int max = *max_element(arr.begin(),arr.end());
    int min = *min_element(arr.begin(),arr.end());
    vector<int>count(max-min+1);
    for(int i=0;i<arr.size();i++)
        count[arr[i]-min]++;
    for(int i=1;i<count.size();i++)
        count[i]+=count[i-1];
    vector<int>ans(n);
    for(int i=n-1;i>=0;i--){
        ans[--count[arr[i]-min]]=arr[i];
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    solve(arr,n); 
 return 0;
}