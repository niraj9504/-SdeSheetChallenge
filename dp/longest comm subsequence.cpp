//recursion
class Solution {
public:
    int solve(int i,int j,string s1,string s2){
        if(i==s1.size() || j==s2.size()){
            return 0;
        }
        if(s1[i]==s2[j]){
            return 1+solve(i+1,j+1,s1,s2);
        }
        return max(solve(i+1,j,s1,s2),solve(i,j+1,s1,s2));
    }
    int longestCommonSubsequence(string s1, string s2) {
        return solve(0,0,s1,s2);
    }
};
//memoization
class Solution {
public:
    int solve(int i,int j,string &s1,string &s2,vector<vector<int>> &dp){
        if(i==s1.size() || j==s2.size()){
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        if(s1[i]==s2[j]){
            return dp[i][j]=1+solve(i+1,j+1,s1,s2,dp);
        }
        return dp[i][j]=max(solve(i+1,j,s1,s2,dp),solve(i,j+1,s1,s2,dp));
    }
    int longestCommonSubsequence(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(0,0,s1,s2,dp);
    }
};
//bottom up
class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 || j==0)continue;
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};

class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                //if(i==0 || j==0)continue;
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};
