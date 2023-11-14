#include<bits/stdc++.h>
using namespace std;
vector<float> solve(vector<float> arr, int n){
    vector<float>bucket[10];
    int k=0,index;
    for(int i=0;i<n;i++){
        index = arr[i]*10; 
        bucket[index].push_back(arr[i]);
    }
    for(int i=0;i<10;i++)
        sort(bucket[i].begin(),bucket[i].end());
    for(int i=0;i<10;i++)
        for(int j=0;j<bucket[i].size();j++)
            arr[k++]=bucket[i][j];
    return arr;
}
int main()
{
    int n;
    cin>>n;
    vector<float> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
      
    
    // solve(arr,n);
    arr=solve(arr,n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}