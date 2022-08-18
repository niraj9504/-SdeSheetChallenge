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
