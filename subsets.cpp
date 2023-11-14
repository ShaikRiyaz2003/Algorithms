#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> ans;
void solve(vector<int>arr,vector<int> temp, int idx){
    if(idx==arr.size()){
        ans.push_back(temp);
        return;
    }
    temp.push_back(arr[idx]);
    solve(arr,temp,idx+1);
    temp.pop_back();
    solve(arr,temp,idx+1);
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto &i: arr)
        cin>>i;
    solve(arr,vector<int>(),0);
    for(auto i: ans){
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}