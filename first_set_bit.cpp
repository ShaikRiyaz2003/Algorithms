#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter a number:"<<endl;
    cin>>n;
    if(n==0)
        cout<<"No 1 bit";
    else
        cout<<log2(n&-n)+1;
}

/*
Explanation

    6-110->001+1->010
      010
      010->2
     1+1=2
*/