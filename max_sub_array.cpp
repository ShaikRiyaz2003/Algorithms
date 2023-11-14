#include<bits/stdc++.h>
using namespace std;
// kadane's algorithm
int main()
{
    int n;
    cin>>n;
    int * arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int max=0,temp=0;
    for(int i=0;i<n;i++){
        temp+=arr[i];
        if(max<temp)
            max=temp;
        if(temp<0)
            temp=0;
    }
    cout<<max<<endl;
}

/* Explanation

arr= 5 3 -2 7 3
max=0 5 8 13 16
temp= 0 5 8 6 13 16

arr = 5 3 -20 9 2
max =5 8 9 11
temp=5 8 -12->0 9 11

*/