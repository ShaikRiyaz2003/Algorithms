#include<bits/stdc++.h>
using namespace std;
vector<int> modified_count(vector<int>arr,int n,int p){
    vector<int>count(10,0);
    vector<int>ans(n);
    for(int i=0;i<n;i++)
        count[(arr[i]/p)%10]++;
    for(int i=1;i<10;i++)
        count[i]+=count[i-1];
    for(int i=n-1;i>=0;i--){
        ans[--count[(arr[i]/p)%10]]=arr[i];
    }
    return ans;
}
void solve(vector<int>arr,int n){
    int max=*max_element(arr.begin(),arr.end());
    for(int p=1;max/p!=0;p=p*10)
        arr=modified_count(arr,n,p);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
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