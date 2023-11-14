#include<bits/stdc++.h>
using namespace std;
vector <int> solve(string pat, string txt)
        {
            string eval = pat+'$'+txt;
            int len=eval.size();
            int txt_len = txt.size();
            int pat_len = pat.size();
            vector<int> z;
            for(int i=0;i<len;i++){
                if(i<=pat_len){
                    z.push_back(0);
                    continue;
                }
                int left=0,right=0;
                if(eval[left]==eval[i]){
                    right=i;
                    while(eval[left]==eval[right] && right < len){
                        right++;
                        left++;
                    }
                }
                z.push_back(left);
            }
            vector<int>ans;
        for (int i=0;i<len;i++){
            if(z[i]==pat_len)
                ans.push_back(i-pat_len);
        //     cout<<z[i]<<endl;
        }
        return ans;
            //code hee.
        }
int main()
{
    string pattern, message;
    cin>>pattern>>message;
    vector<int> ans = solve(pattern,message);
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    
 return 0;
}
/*
Input: 
S = "abesdu", pat = "edu"
Output: -1
Explanation: There's not substring "edu"
present in S.



Input:
S = "batmanandrobinarebat", pat = "bat"
Output: 1 18
Explanation: The string "bat" occurs twice
in S, one starts are index 1 and the other
at index 18.

*/