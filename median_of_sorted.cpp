#include<bits/stdc++.h>
using namespace std;
void insertionSort(int arr[], int n,int start)
{
    int i, key, j;
    for (i = start; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    int* arr=new int[n+m];
    // vector<int>arr(n+m);
    for(int i=0;i<n+m;i++)
        cin>>arr[i];
    // sort(arr.begin(),arr.end());
    insertionSort(arr,n+m,n);
    for (int i = 0; i < n+m; i++)
        cout<<arr[i]<<" ";
    if((n+m)%2!=0)
        cout<<arr[(n+m)/2]<<endl;
    else
        cout<<(arr[(n+m)/2]+arr[(n+m+1)/2-1])/2<<endl;
    return 0;
}