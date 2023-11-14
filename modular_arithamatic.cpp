#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,m;
    cin>>a>>b>>m;
    cout<<"Modular addition"<<endl;
    a=a%m;
    b=b%m;
    cout<<"Addition:"<<(a+b)%m<<endl;
    cout<<"Substraction:"<<(a-b+m)%m;
    return 0;
}