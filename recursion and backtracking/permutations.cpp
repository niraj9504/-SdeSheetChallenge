//backtracking method (try recursion method->think)
class Solution {
public:
    void help(vector<int>&nums,int idx,vector<vector<int>> &ans){
        if(idx==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=idx;i<nums.size();i++){
            swap(nums[i],nums[idx]);
            help(nums,idx+1,ans);
            swap(nums[i],nums[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        help(nums,0,ans);
        return ans;
    }
};
