#include <bits/stdc++.h>
using namespace std;

// Function that matches input str with
// given wildcard pattern
vector<vector<int> > dp;
int finding(string& s, string& p, int n, int m)
{
	// return 1 if n and m are negative
	if (n < 0 && m < 0)//both are null
		return 1;

	// return 0 if m is negative
	if (m < 0)//string is there but no pattern
		return 0;

	// return n if n is negative
	if (n < 0)//string is null but pattern is there
	{
        //
        //********************
		// while m is positive
		while (m >= 0)
		{
			if (p[m] != '*')
				return 0;
			m--;
		}
		return 1;
	}
	
	// if dp state is not visited
	if (dp[n][m] == -1)
	{
		if (p[m] == '*')
		{
			return dp[n][m] = finding(s, p, n - 1, m)
							|| finding(s, p, n, m - 1);
		}
		else
		{
			if (p[m] != s[n] && p[m] != '?')
				return dp[n][m] = 0;
			else
				return dp[n][m]
					= finding(s, p, n - 1, m - 1);
		}
	}

	// return dp[n][m] if dp state is previsited
	return dp[n][m];
}


bool isMatch(string s, string p)
{
	dp.clear();
	
	// resize the dp array
	dp.resize(s.size() + 1, vector<int>(p.size() + 1, -1));
	return dp[s.size()][p.size()]
		= finding(s, p, s.size() - 1, p.size() - 1);
}

// Driver code
int main()
{
	string str,pattern;
	cin>>str>>pattern;
	if (isMatch(str, pattern))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}



/*

>>>>>>>>>>>>>>>>>>>>>>>>>>DP without recursion 2D array<<<<<<<<<<<<<<<<<<<

column=string
row=pattern


bool isMatch(string s, string p) {
        int m=s.length(),n=p.length();
        bool a[m+1][n+1];
        a[0][0]=true;
        for(int i=1;i<=m;i++)
            a[i][0]=false;
        for(int j=1;j<=n;j++)
            a[0][j]=(p[j-1]=='*')?(a[0][j-1]):(false);
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==p[j-1]||p[j-1]=='?')
                    a[i][j]=a[i-1][j-1];
                else if(p[j-1]=='*')
                    a[i][j]=a[i][j-1]||a[i-1][j];
                else 
                    a[i][j]=false;
            }
        }
        return a[m][n];
    }

*/


/*
>>>>>>>>>>>>>>>>>>>>>>DP solution with 1D array<<<<<<<<<<<<<<<<


bool isMatch(string s,string p){
    int m=s.length(),n=p.length();
    if(n>3e4) return false;
    vector<bool> cur(m+1,false);
    cur[0]=true;
    bool pre=cur[0];
    for(int j=1;j<=n;j++,pre=cur[0]){
        cur[0]=cur[0]&&p[j-1]=='*';
        for(int i=1;i<=m;i++){
            bool temp=cur[i];
            cur[i]=(p[j-1]!='*')?(pre&&(s[i-1]==p[j-1]||p[j-1]=='?')):(cur[i-1]||cur[i]);
            pre=temp;
        }
    }
    return cur[m];
}

*/


/*
	>>>>>>>>>>>> Explanation <<<<<<<<<<<<<<<<<<

			if(s[i-1]==p[j-1]||p[j-1]=='?')
                    a[i][j]=a[i-1][j-1];
                else if(p[j-1]=='*')
                    a[i][j]=a[i][j-1]||a[i-1][j];
                else 
                    a[i][j]=false;

string = aabbc
pattern = a*b?c
	 _ a * b ? c
	_0 0 0 0 0 0 
	a0 1 1 0 0 0
	a0 1 1 0 0 0
	b0 0 1 1 0 0
	b0 0 1 1 1 0
	c0 0 1 0 1 1
	


*/
