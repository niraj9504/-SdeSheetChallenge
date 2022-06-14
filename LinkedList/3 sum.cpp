//very very slow + more space
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        if(n<3)return ans;
        set<vector<int>> map;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            int f=-nums[i];
            int j=i+1,k=n-1;
            while(j<k){
                if(nums[j]+nums[k]==f){
                    map.insert({nums[i],nums[j],nums[k]});
                    j++;
                }
                else if(nums[j]+nums[k]>f){
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        for(auto it:map)ans.push_back({it[0],it[1],it[2]});
        return ans;
    }
};
