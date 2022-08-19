//leetcode =>Ones and Zero
//TLE (recursion)
class Solution {
public:
    int count(string s){
        bitset<100> st(s);
        return st.count();
    }
    int knapsack(int i,int m,int n,vector<string> s){
        if((m<=0 && n<=0) || i==s.size()){
            return 0;
        }
        int one=count(s[i]),zero=s[i].size()-one;
        int pick=0;
        if(m-zero>=0 && n-one>=0)
            pick=knapsack(i+1,m-zero,n-one,s)+1;
        return max(pick,knapsack(i+1,m,n,s));
    }
    int findMaxForm(vector<string>& s, int m, int n) {
        return knapsack(0,m,n,s);
    }
};
//m2 (memory limit exceed)
class Solution {
public:
    int dp[601][101][101];//because i,m and n=> all three are changing in recursion
    int count(string s){
        bitset<100> st(s);
        return st.count();
    }
    int knapsack(int i,int m,int n,vector<string> s){
        if((m<=0 && n<=0) || i==s.size()){
            return 0;
        }
        if(dp[i][m][n]!=-1)return dp[i][m][n];
        int one=count(s[i]),zero=s[i].size()-one;
        int pick=0;
        if(m-zero>=0 && n-one>=0)
            pick=knapsack(i+1,m-zero,n-one,s)+1;
        return dp[i][m][n]=max(pick,knapsack(i+1,m,n,s));
    }
    int findMaxForm(vector<string>& s, int m, int n) {
        memset(dp,-1,sizeof(dp));
        return knapsack(0,m,n,s);
    }
};
//m3 bottom up
class Solution {
public:
    int findMaxForm(vector<string> &s, int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(auto it:s){
            int z=it.size();
            bitset<100> b(it);
            int one=b.count();
            int zero=z-one;
            for(int i=m;i>=zero;i--){
                for(int j=n;j>=one;j--){
                    dp[i][j]=max(dp[i][j],dp[i-zero][j-one]+1);//not pick and pick type
                }
            }
        }
        return dp[m][n];
    }
};

//count 1's another method
int x = count(s.begin(),s.end(),'1');
            int y = s.size()-x;

//codestudio 0/1 knapsack
//TLE
#include<bits/stdc++.h>
int solve(int i,vector<int> &val,vector<int> &wt,int w){
    if(i==val.size()){
        return 0;
    }
    int cost=solve(i+1,val,wt,w);
    if(w-wt[i]>=0)
        cost=max(cost,solve(i+1,val,wt,w-wt[i])+val[i]);
    return cost;
}
int maxProfit(vector<int> &val, vector<int> &wt, int n, int w)
{
	return solve(0,val,wt,w);
}

//top-down(memoization)
#include<bits/stdc++.h>
int solve(int i,vector<int> &val,vector<int> &wt,int w,vector<vector<int>> &dp){
    if(i==val.size()){
        return 0;
    }
    if(dp[i][w]!=-1)return dp[i][w];
    int cost=solve(i+1,val,wt,w,dp);
    if(w-wt[i]>=0)
        cost=max(cost,solve(i+1,val,wt,w-wt[i],dp)+val[i]);
    return dp[i][w]=cost;
}
int maxProfit(vector<int> &val, vector<int> &wt, int n, int w)
{    
    vector<vector<int>> dp(n,vector<int>(w+1,-1));
	return solve(0,val,wt,w,dp);
}
//bottom up

#include<bits/stdc++.h>
int maxProfit(vector<int> &val, vector<int> &wt, int n, int w)
{    
    vector<vector<int>> dp(n+1,vector<int>(w+1,0));
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
            if(j-wt[i-1]>=0)
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-wt[i-1]]+val[i-1]);
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][w];
}
or
 #include<bits/stdc++.h>
int maxProfit(vector<int> &val, vector<int> &wt, int n, int w)
{    
    vector<vector<int>> dp(n+1,vector<int>(w+1,0));
    
    for(int i=1;i<=n;i++){
        for(int j=w;j>=0;j--){
            if(j-wt[i-1]>=0)
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-wt[i-1]]+val[i-1]);
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][w];
}
//see codestudion solution
#include<bits/stdc++.h>
int maxProfit(vector<int> &val, vector<int> &wt, int n, int w)
{    
    vector<int> dp(w+1,0);
    
    for(int i=0;i<=n;i++){
        for(int j=w;j>=wt[i];j--){
            dp[j]=max(dp[j],dp[j-wt[i]]+val[i]);
        }
    }
    return dp[w];
}
