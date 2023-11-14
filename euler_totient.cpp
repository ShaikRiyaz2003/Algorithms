#include<bits/stdc++.h>
using namespace std;
//Find no of co-primes below n for n
void solve(int n){
    vector<bool> Isprime(n+1,true);
    Isprime[0]=Isprime[1]=false;
    for(int i=2;i*i<=n;i++){
        if(Isprime[i]){
            for(int j=i*i; j<=n;j=j+i)
                Isprime[j]=false;
        }
    }
    if(Isprime[n]){
        cout<<n-1;
        return;
    }
    float ans=n;
    for(int i=0;i<n+1;i++)
        if(Isprime[i] && n%i==0)
            ans*=(1.0-1.0/i);
    cout<<ans;
    return;
}
int main()
{
    int n;
    cin>>n;
    solve(n);
    return 0;
}