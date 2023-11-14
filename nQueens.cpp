/* C++ program to solve n Queen Problem using
backtracking */

#include <bits/stdc++.h>
using namespace std;

/* A utility function to print solution */
void printSolution(vector<vector<int>> board,int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
		if(board[i][j])
			cout << "Q ";
		else cout<<". ";
		printf("\n");
	}
}

/* A utility function to check if a queen can
be placed on board[row][col]. note that this
function is called when "col" queens are
already placed in columns from 0 to col -1.
So we need to check only left side for
attacking queens */
bool isSafe(vector<vector<int>> board, int row, int col,int n)
{
	int i, j;

	/* Check this row on left side */
	for (i = 0; i < col; i++)
		if (board[row][i])
			return false;

	/* Check upper diagonal on left side */
	for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
		if (board[i][j])
			return false;

	/* Check lower diagonal on left side */
	for (i = row, j = col; j >= 0 && i < n; i++, j--)
		if (board[i][j])
			return false;

	return true;
}

/* A recursive utility function to solve n
Queen problem */
bool solvenQUtil(vector<vector<int>> board, int col,int n)
{
	/* base case: If all queens are placed
	then return true */
	if (col >= n)
		return true;

	/* Consider this column and try placing
	this queen in all rows one by one */
	for (int i = 0; i < n; i++) {
		/* Check if the queen can be placed on
		board[i][col] */
		if (isSafe(board, i, col,n)) {
			/* Place this queen in board[i][col] */
			board[i][col] = 1;

			/* recur to place rest of the queens */
			if (solvenQUtil(board, col + 1,n))
				return true;

			/* If placing queen in board[i][col]
			doesn't lead to a solution, then
			remove queen from board[i][col] */
			board[i][col] = 0; // BACKTRACK
		}
	}

	/* If the queen cannot be placed in any row in
		this column col then return false */
	return false;
}

/* This function solves the n Queen problem using
Backtracking. It mainly uses solvenQUtil() to
solve the problem. It returns false if queens
cannot be placed, otherwise, return true and
prints placement of queens in the form of 1s.
Please note that there may be more than one
solutions, this function prints one of the
feasible solutions.*/
bool solvenQ(int n)
{
	vector<vector<int>> board(n,vector<int>(n,0));

	if (solvenQUtil(board, 0,n) == false) {
		cout << "Solution does not exist";
		return false;
	}

	printSolution(board,n);
	return true;
}

// driver program to test above function
int main()
{
    int n;
    cin>>n;
	solvenQ(n);
	return 0;
}

// This code is contributed by Aditya Kumar (adityakumar129)
