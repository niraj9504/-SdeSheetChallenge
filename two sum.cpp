class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int t) {
        unordered_map<int,int> map;
        int n=nums.size();
        for(int i=0;i<n;i++){
            map.insert({nums[i],i});
        }
        for(int i=0;i<n;i++){
            int f=t-nums[i];
            auto it=map.find(f);
            if(it!=map.end() && i!=it->second){
                return {i,it->second};
            }
        }
        return {-1,-1};
    }
};
//try code studio by this logic
