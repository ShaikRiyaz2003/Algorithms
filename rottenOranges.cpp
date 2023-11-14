#include<bits/stdc++.h>
using namespace std;
bool isSafe(int i,int j,int row,int col){
    if(i>=0 && i<row && j>=0 && j<col)
        return true;
    return false;
}
/*
0-> empty 
1-> fresh orange
2-> initially rotten
*/
int main(){
    int row,col;
    cin>>row>>col;
    vector<vector<int>> matrix(row,vector<int>(col,0));
    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
            cin>>matrix[i][j];
    int m,n;
    bool changed = false;
    int no =2;// present rotten number
    while(true){
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j] == no){
                    if(isSafe(i+1,j,row,col) && matrix[i+1][j]==1){//down
                        matrix[i+1][j] = matrix[i][j]+1;
                        changed = true;
                    }
                    if(isSafe(i,j+1,row,col) && matrix[i][j+1]==1){//right
                        matrix[i][j+1] = matrix[i][j]+1;
                        changed = true;
                    }
                    if(isSafe(i-1,j,row,col) && matrix[i-1][j]==1){//top
                        matrix[i-1][j] = matrix[i][j]+1;
                        changed = true;
                    }
                    if(isSafe(i,j-1,row,col) && matrix[i][j-1]==1){//left
                        matrix[i][j-1] = matrix[i][j]+1;
                        changed = true;
                    }
                }
            }
        }
        if(!changed)
            break;
        changed = false;
        no++;//update rotten
    }
    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
            if(matrix[i][j]==1){
                cout<<"Not possible";
                exit(0);
            }
    cout<<"Max time incurred:"<<no-2;
    return 0;
}   



/*
 matrix[i+1][j] = matrix[i][j]+1;
  ripen = latest rotten+1
 0 1 2        0 3 2     0 3 2
 0 1 2    ->  0 3 2  -> 0 3 2  (no change break)
 2 1 1        2 3 3     2 3 3

*/