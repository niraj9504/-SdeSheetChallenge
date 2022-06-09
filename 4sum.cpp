//best method
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int t) {
        //easy 
        vector<vector<int>> ans;
        int n=nums.size();
        if(n<4)return ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-3;i++){
            if(i>0 && nums[i]==nums[i-1])continue;//remove duplicates
            if((long long)(nums[i]+nums[i+1])+(long long)(nums[i+2]+nums[i+3])>t)break;//check possibilities
            if((long long)(nums[i]+nums[n-1])+(long long)(nums[n-2]+nums[n-3])<t)continue;//check possibilities
            for(int j=i+1;j<n-2;j++){
                if(j>i+1 && nums[j]==nums[j-1])continue;
                if((long long)(nums[i]+nums[j])+(long long)(nums[j+1]+nums[j+2])>t)break;
                if((long long)(nums[i]+nums[j])+(long long)(nums[n-1]+nums[n-2])<t)continue;
                
                int s=j+1,e=n-1;
                while(s<e){
                    long long sum=nums[i]+nums[j]+nums[s]+nums[e];
                    if(sum==t){
                        ans.push_back({nums[i],nums[j],nums[s],nums[e]});
                        do{s++;}while(nums[s]==nums[s-1] && s<e);
                        do{e--;}while(nums[e]==nums[e+1] && s<e);
                    }
                    else if(sum>t)e--;
                    else s++;
                }
            }
        }
        return ans;
    }
};
//m2 
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int t) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        set<vector<int>> mp;
        int n=nums.size();
        for(int i=0;i<n-3;i++){
            int f=t-nums[i];
            for(int j=i+1;j<n-2;j++){
                int g=f-nums[j];
                int s=j+1,e=n-1;
                while(s<e){
                    if(nums[s]+nums[e]==g){
                        mp.insert({nums[i],nums[j],nums[s],nums[e]});
                        s++;
                    }
                    else if(nums[s]+nums[e]>g){
                        e--;
                    }
                    else{
                        s++;
                    }
                }
            }
        }
        for(auto it:mp)ans.push_back(it);
        return ans;
    }
};
