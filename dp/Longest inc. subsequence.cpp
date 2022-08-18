//m1(recursion) tc O(2^n) ,sc=O(n) recursion stack
class Solution {
public:
    int len=1;
    int solve(int i,vector<int> &nums,int prev){
        if(i==nums.size()){
            return 0;//not have any idx=>len=0
        }
        //not pick
        int len=solve(i+1,nums,prev)+0;
        //pick
        if(prev==-1 || nums[i]>nums[prev]){
            len=max(len,solve(i+1,nums,i)+1);
        }
        return len;
    }
    int lengthOfLIS(vector<int>& nums) {
        
        return solve(0,nums,-1);
    }
};

//memoization=> 
class Solution {
public:
    int len=1;
    int solve(int i,vector<int> &nums,int prev,vector<vector<int>> &dp){
        if(i==nums.size()){
            return 0;
        }
        if(dp[i][prev+1]!=-1)return dp[i][prev+1];
        int len=solve(i+1,nums,prev,dp)+0;
        //pick
        if(prev==-1 || nums[i]>nums[prev]){
            len=max(len,solve(i+1,nums,i,dp)+1);
        }
        return dp[i][prev+1]=len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(0,nums,-1,dp);
    }
};

//striver dp series for more optimisation

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};

//fastest(look for leetcode solution)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len=0;
        for(auto it:nums){
            if(len==0 || nums[len-1]<it)nums[len++]=it;
            else{
                auto x=lower_bound(nums.begin(),nums.begin()+len,it);
                *x=it;
            }
        }
        return len;
    }
};
