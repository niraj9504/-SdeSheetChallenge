//method 1(see other solutions of leetcode)*** and striver solution for this MOORE's voting algo.
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> map;
        int n=nums.size()/2;
        for(auto it:nums){
            map[it]++;
            if(map[it]>n)return it;
        }
        return -1;
    }
};
