//similar as subset sum, slight change => learn how to remove duplicates
class Solution {
public:
    
    void recursion(int i,vector<int> &temp,vector<int> nums,int t,vector<vector<int>> &ans){                   if(t==0){
            ans.push_back(temp);
            return;
        }
        for(int j=i;j<nums.size();j++){
            if(j>i && nums[j]==nums[j-1])continue;
            if(nums[j]>t)break;//important otherwise gives TLE
            temp.push_back(nums[j]);
            recursion(j+1,temp,nums,t-nums[j],ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int t) {
        vector<int> temp;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        recursion(0,temp,nums,t,ans);
        return ans;
    }
};
