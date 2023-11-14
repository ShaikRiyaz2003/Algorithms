#include<bits/stdc++.h>
using namespace std;
vector<int> sieve(int n){
    vector<bool> Isprime(n+1,true);
    vector<int>ans;
    Isprime[0]=Isprime[1]=false;
    for(int i=2;i*i<=n;i++){
        if(Isprime[i]){
            for(int j=i*i; j<=n;j=j+i)
                Isprime[j]=false;
        }
    }
    for(int i=0;i<n+1;i++)
        if(Isprime[i])
            ans.push_back(i);
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int> ans =sieve(n);
    for(auto i: ans)
        cout<<i<<" ";
 return 0;
}