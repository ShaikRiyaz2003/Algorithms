#include<bits/stdc++.h>
// collatz conjecture
using namespace std;
int cyclelength(int n){
    int c=0;
    while(true){
        c++;
        if(n==1)
            break;
        (n%2!=0)?n=(3*n+1):n/=2;
    }
    return c;
}
int main(){
    int x,y,mx,mn,i=0,c;
    while(cin>>x>>y){
        mn=min(x,y),mx=max(x,y);
        c=0;
        for(int k=mn;k<=mx;k++)
            c=max(c,cyclelength(k));
        cout<<mn<<" "<<mx<<" "<<c<<endl;
    }
}