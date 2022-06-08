//see strivers sheet solution for Moore's voting extended vvi(for O(1) space) imp for interview
#include <bits/stdc++.h> 
vector<int> majorityElementII(vector<int> &nums)
{
        int n=nums.size();
        vector<int> ans;
        unordered_map<int,int> map;
        for(auto it:nums){
            map[it]++;
        }
        for(auto it:map){
            if(it.second>n/3)ans.push_back(it.first);
        }
        return ans;

}
