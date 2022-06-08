#include <bits/stdc++.h> 
int uniquePaths(int m, int n) {
	vector<vector<int>> dp(m,vector<int> (n,1));
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
     return dp[m-1][n-1];
}
//2nd
vector<vector<int>> dp(101,vector<int>(101,-1));
class Solution {
public:
    
    int uniquePaths(int m, int n) {
        if(m==1 || n==1){
            return 1;
        }
        if(dp[m][n]!=-1)return dp[m][n];
        return dp[m][n]=uniquePaths(m-1,n)+uniquePaths(m,n-1);
    }
};
