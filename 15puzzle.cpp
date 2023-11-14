#include <bits/stdc++.h>

using namespace std;

int check[4][4]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0};
string final;
void copy(int a[10][10],int b[10][10]){
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            a[i][j]=b[i][j];
}

bool check_list(int a[10][10]){
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            if(a[i][j]!=check[i][j])
                return false;
    return true; 
}

int miss_place(int a[10][10]){
    int count=0;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            if(a[i][j]!=check[i][j])
                count++;
    return count;
} 

void move(int a[10][10],int x,int y,int c){
    if(check_list(a))
        return;
    c+=1;
    string s="";
    int X,Y,miss;
    X=x;
    Y=y;
    int temp[10][10],temp1[10][10];
    copy(temp,a);
    int max=99999;
    if(x!=0){
        swap(temp[x][y],temp[x-1][y]);
        miss=miss_place(temp);
        if(miss<max){
            max=miss; 
            X=x-1;
            Y=y;
            s="U"; 
            copy(temp1,temp);
        } 
    }
    copy(temp,a);
    if(x!=3){
        swap(temp[x][y],temp[x+1][y]);
        miss=miss_place(temp);
        if(miss<max){
            max=miss;
            X=x+1;
            Y=y;
            s="D";
            copy(temp1,temp);
        }
    }
    copy(temp,a);
    if(y!=0){
        swap(temp[x][y],temp[x][y-1]);
        miss=miss_place(temp);
        if(miss<max){
            max=miss;
            X=x;
            Y=y-1;
            s="L";
            copy(temp1,temp);
        }
    }
    copy(temp,a);
    if(y!=3){
        swap(temp[x][y],temp[x][y+1]);
        miss=miss_place(temp);
        if(miss<max){
            max=miss;
            X=x;
            Y=y+1;
            s="R";
            copy(temp1,temp);
        }
    }
    final+=s;
    if(check_list(temp1)){
        cout<<final<<endl;
    }
    else if(c>=50){
        cout<<"NOT SOLVABLE"<<endl;
    } 
    else{
        move(temp1,X,Y,c); 
    }
}


int main()
{
    int x,y,c=0;
    int a[10][10];
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cin>>a[i][j];
            if(a[i][j]==0){
                x=i;
                y=j;
            }
        }
    }
    move(a,x,y,c);       
    return 0;
}