// #include<bits/stdc++.h>
// using namespace std;
// void solve(vector<int>arr){
//     int n=arr.size();
//     int max1,max2,max3,min1,min2;
//     max1=max2=max3=min1=min2=arr[0];
//     for(int i=1;i<n;i++){
//         if(max1<arr[i]){
//             max3=max2;
//             max2=max1;
//             max1=arr[i];
//         }
//         else if(max2<arr[i]){
//             max3=max2;
//             max2=arr[i];
//         }
//         else if(max3<arr[i]){
//             max3 = arr[i];
//         }
//         if(min1>arr[i])
            
//     }
// }
// int main(){
//     int n;
//     cin>>n;
//     vector<int>arr(n);
//     for(int i=0;i<n;i++)
//         cin>>arr[i];
//     solve(arr);
// }
#include<bits/stdc++.h>
using namespace std;
void Triplet(vector<int>arr){
    int size = arr.size();
    sort(arr.begin(),arr.end());
    int first=arr[0]*arr[1]*arr[size-1];
    int last = arr[size-1]*arr[size-2]*arr[size-3];
    if(first>last)
        cout<<arr[0]<<","<<arr[1]<<","<<arr[size-1];
    else
        cout<<arr[size-3]<<","<<arr[size-2]<<","<<arr[size-1];
    return;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    Triplet(arr);
}