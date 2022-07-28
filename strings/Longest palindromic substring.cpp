class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        bool dp[n][n];
        //dp[i][j]=true if substr from i to j is palindrome
        memset(dp,false,sizeof(dp));
        for(int i=0;i<n;i++)dp[i][i]=true;
        string ans="";
        ans+=s[0];
        for(int i=n-2;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(s[i]==s[j]){
                    //If it is of two character OR if its susbtring is palindrome.
                    if(j-i==1 || dp[i+1][j-1]){
                        dp[i][j]=true;//Then it will also a palindrome substring
                        if(ans.size()<j-i+1)
                        ans=s.substr(i,j-i+1);//Check for Longest Palindrome substring
                    }
                }
            }
        }
        return ans;
    }
};
//m2 expand on i,i and i,i+1
