class Solution {
public:
    void recursion(int i,vector<vector<int>> &ans,vector<int> &temp,int t,vector<int> nums){
        if(i==nums.size()){
            if(t==0){
                ans.push_back(temp);
            }
            return;
        }
        if(t-nums[i]>=0){
            temp.push_back(nums[i]);
            recursion(i,ans,temp,t-nums[i],nums);
            temp.pop_back();
        }
        recursion(i+1,ans,temp,t,nums);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        //sort(nums.begin(),nums.end());
        recursion(0,ans,temp,target,nums);
        return ans;
    }
};
// see codestudio

void recursion(int i,vector<vector<int>> &ans,vector<int> &temp,int k,vector<int> nums){
    if(i==nums.size()){
        if(k==0){
            ans.push_back(temp);
        }
        return;
    }
        temp.push_back(nums[i]);
        recursion(i+1,ans,temp,k-nums[i],nums);
        temp.pop_back();
        recursion(i+1,ans,temp,k,nums);
    
    
}
vector<vector<int>> findSubsetsThatSumToK(vector<int> nums, int n, int k)
{
    vector<vector<int>> ans;
    vector<int> temp;
    recursion(0,ans,temp,k,nums);
    return ans;
}
