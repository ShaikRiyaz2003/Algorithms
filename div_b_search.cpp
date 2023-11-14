//Working in online GDB

#include<bits/stdc++.h>
using namespace std;
//x=my
float binarydiv(float low,float high,int x,int y){//x/y
    float mid=low+(high-low)/2.0;
    if(mid*y==x)
        return mid;
    if(mid*y>x){
        return binarydiv(low,mid,x,y);
    }
    else
        return binarydiv(mid,high,x,y);
}
int main()
{
    int x,y;
    cin>>x>>y;
    if(y==0){
        cout<<"division by zero 0"<<endl;
        return 0;
    }
    float ans=binarydiv(-32767,32767,x,y);
    cout<<ans<<endl;
    return 0;
}