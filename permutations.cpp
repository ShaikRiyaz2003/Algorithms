#include<bits/stdc++.h>
using namespace std;
vector<string>ans;
void permute(string str,int n,int idx){
    if(idx==n){
        ans.push_back(str);
        return;
    }
    for(int i=idx;i<n;i++){
        swap(str[i],str[idx]);
        permute(str,n,idx+1);
        swap(str[i],str[idx]);
    }
}
int main()
{
    string str;
    cin>>str;
    permute(str,str.size(),0);
    for(auto i : ans){
            cout<<i<<" ";
        cout<<endl;
    }
 return 0;
}

/*

class Solution {
public:
    int findMin(vector<int>& dist, vector<bool>& visited){
        int min = INT_MAX, size = dist.size(), idx;
        for(int i = 0; i < size; i++){
            if(!visited[i] && min > dist[i]){
                min = dist[i];
                idx = i;
            }
        }
        return idx;
    }
    vector<int> dijstras(vector<vector<int>> graph, int src){
        int size = graph.size();
        vector<int> dist(size, INT_MAX);
        vector<bool> visited(size, false)
        dist[src] = 0;
        for(int i = 0; i < size - 1; i++){
            int u = findMin(dist, visited);
            visited[u] = true;
            for(int v = 0; v < size; v++){
                if(!visited[v] && graph[u][v] && dist[v] != INT_MAX &&
                                         dist[u] + graph[u][v] < dist[v])
                            dist[v] = dist[u] + graph[u][v];
            }
        }
        return dist;
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> graph(n, vector<int>(n, 0));
        for(int i = 0; i < flights.size(); i++){
            graph[flights[i][0]][flights[i][1]] = graphs[flights[i][2]];
        }
        vector<int>

    }
};

*/