//method 1 (learn it) o(n) ** see all solutions from leetcode 
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        while(nums[0]!=nums[nums[0]])swap(nums[0],nums[nums[0]]);
        return nums[0];
    }
};
//method 2 sorting t.c=O(nlogn) s.c=O(logn) in worst case for sorting 
