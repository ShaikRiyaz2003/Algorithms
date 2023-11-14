#include<bits/stdc++.h>
using namespace std;
int x,y,d;
void solve(int a,int b){
    if(b==0){
        x=1;
        y=0;
        d=a;
        return;
    }
    solve(b,a%b);
    int x1=y;
    int y1=x-(a/b)*y;
    x=x1;
    y=y1;
}
int main(){
    int a,b;
    while(cin>>a>>b){
        // cout<<solve(a,b)<<endl;
        solve(a,b);
        cout<<x<<" "<<y<<" "<<d<<endl;
    }
}

/*
                ax+by=d=gcd(a,b)
given a,b find x,y
*/