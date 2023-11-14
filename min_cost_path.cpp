// A Naive recursive implementation
// of MCP(Minimum Cost Path) problem
#include <bits/stdc++.h>
using namespace std;
int min(int x, int y, int z);
int minCost(vector<vector<int>> cost, int m, int n)
{
	if (n < 0 || m < 0)
		return INT_MAX;
	else if (m == 0 && n == 0)
		return cost[m][n];
	else
		return cost[m][n]
			+ min(minCost(cost, m - 1, n - 1),//top left
					minCost(cost, m - 1, n),//left
					minCost(cost, m, n - 1));//top
}
int min(int x, int y, int z)
{
	if (x < y)
		return (x < z) ? x : z;
	else
		return (y < z) ? y : z;
}

int main()
{
    int row,col;
    cin>>row>>col;

	vector<vector<int>> cost(row,vector<int>(col,0));
    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
            cin>>cost[i][j];
	cout << minCost(cost,row-1,col-1) << endl;
	return 0;
}
