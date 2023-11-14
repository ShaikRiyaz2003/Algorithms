#include<bits/stdc++.h>
using namespace std;
void print(vector<vector<int>> arr,int i, int j, int m, int n){
    if(i>=m || j>=n)//outside
        return;

    //first row
    for(int p=j;p<n;p++)
        cout<<arr[i][p]<<" ";

    //last column
    for(int p = i+1;p<m;p++)
        cout<<arr[p][n-1]<<" ";

    //last row if first row and last row are not same
    if((m-1)!=i)
        for(int p=n-2;p>=j;p--)
            cout<<arr[m-1][p]<<" ";

    //last row if first column and last column are not same
    if((n-1)!=j)
        for(int p=m-2;p>i;p--)
            cout<<arr[p][j]<<" ";
    print(arr, i+1,j+1,m-1,n-1);
}
int main(){
    int R,C;
    cin>>R>>C;
    vector<vector<int>>matrix(R,vector<int>(C,0));
    for(int i=0;i<R;i++)
        for(int j=0;j<C;j++)
            cin>>matrix[i][j];
    print(matrix,0,0,R,C);
    return 0;
}

/*

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,t;
    cin>>n>>m;
    vector< vector <int> > a(n,vector<int>(m));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>a[i][j];
    int left=0,top=0,right=m-1,bottom=n-1;
    while(top<=bottom && left<=right){
        if(top <= bottom ){
            for(int i=left;i<=right;i++)
                cout<<a[top][i]<<" ";
            top++;
        }
        if(left <= right){
            for(int i=top;i<=bottom;i++)
                cout<<a[i][right]<<" ";
            right--;
        }
        if(top <= bottom){
            for(int i=right;i>=left;i--)
                cout<<a[bottom][i]<<" ";
            bottom--;
        }
        if(left <= right){
            for(int i=bottom;i>=top;i--)
                cout<<a[i][left]<<" ";
            left++;
        }
    }
    return 0;
}


*/