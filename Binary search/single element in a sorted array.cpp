//m-1: Bit manipulation:- O(n)
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int xorr=0;
        for(auto it:nums)xorr^=it;
        return xorr;
    }
};
//m-2 Binary search O(logn) but slower than above
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=1,h=nums.size()-1;//l==1 not 0 (zero) coz checking for m-1, 1223344
        while(l<=h){
            int m=(l+h)/2;
            if(m&1){
                if(nums[m]==nums[m-1]){
                    l=m+1;
                }
                else{
                    h=m-1;
                }
            }
            else{
                if(nums[m]==nums[m-1]){
                    h=m-1;
                }
                else{
                    l=m+1;
                }
            }
        }
        return nums[h];
    }
};
