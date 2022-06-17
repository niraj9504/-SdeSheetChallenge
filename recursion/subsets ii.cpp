//without optimised
class Solution {
public:
    vector<vector<int>> ans;
    //set<vector<int>> map;
    void recursion(vector<int> &nums,int i,vector<int> &temp){
        if(i==nums.size()){
            //sort(temp.begin(),temp.end());
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        recursion(nums,i+1,temp);
        temp.pop_back();
        recursion(nums,i+1,temp);
        
    }
    vector<vector<int>> removeDup(vector<vector<int>> &ans){
        vector<vector<int>> x; 
        for(int i=0;i<ans.size();i++){
            sort(ans[i].begin(),ans[i].end());
        }
        int i;
        sort(ans.begin(),ans.end());
        for(i=0;i<ans.size()-1;i++){
            if(ans[i]!=ans[i+1]){
                x.push_back(ans[i]);
            }
        }
        if(i==ans.size()-1) x.push_back(ans[i]);
        return x;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        recursion(nums,0,temp);
        return removeDup(ans);
    }
};
//try optimising (striver solution**)
class Solution {
public:
    void recursion(int i,vector<vector<int>> &ans,vector<int> &temp,vector<int> nums){
        ans.push_back(temp);
        for(int j=i;j<nums.size();j++){
            if(j!=i && nums[j]==nums[j-1])continue;
            temp.push_back(nums[j]);
            recursion(j+1,ans,temp,nums);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        recursion(0,ans,temp,nums);
        return ans;
    }
};
