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
//fast and good one
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        if(n<3)return ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            if(i>0 && nums[i]==nums[i-1])continue;//removing duplicates;
            if(nums[i]+nums[i+1]+nums[i+2]>0)break;
            if(nums[i]+nums[n-1]+nums[n-2]<0)continue;
            int f=-nums[i];
            int j=i+1,k=n-1;
            while(j<k){
                if(nums[j]+nums[k]==f){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    int x=nums[j],y=nums[k];
                    while(j<k && nums[j]==x)j++;
                    while(k>j && nums[k]==y)k--;
                }
                else if(nums[j]+nums[k]>f){
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        //for(auto it:map)ans.push_back({it[0],it[1],it[2]});
        return ans;
    }
};
