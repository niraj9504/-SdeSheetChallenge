//
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=nums[0],maxi=nums[0],mini=nums[0];
        for(int i=1;i<nums.size();i++){
          // multiplied by a negative makes big number smaller, small number bigger
          // so we redefine the extremums by swapping them
            if(nums[i]<0){
                swap(mini,maxi);
            }
          // max/min product for the current number is either the current number itself
          // or the max/min by the previous number times the current one
            maxi=max(nums[i],maxi*nums[i]);
            mini=min(nums[i],mini*nums[i]);
          // the newly computed max value is a candidate for our global result
            ans=max(maxi,ans);
        }
        return ans;
    }
};

//m2(striver two traversals method)
int maxProductSubArray(vector<int>& nums) {
    int maxLeft = nums[0];
    int maxRight = nums[0];
    
    int prod = 1;
    
    bool zeroPresent =  false;
    
    for(auto i:nums) {
        prod *= i;
        if(i == 0) {
            zeroPresent = true;
            prod = 1;
            continue;
        }
        maxLeft = max(maxLeft,prod);
    }
    
    prod = 1;
    
    for(int j=nums.size()-1;j>=0;j--) {
        prod *= nums[j];
        if(nums[j] == 0) {
            zeroPresent = true;
            prod = 1;
            continue;
        }
        maxRight = max(maxRight,prod);
    }
    
    if(zeroPresent) return max(max(maxLeft,maxRight),0);
    return max(maxLeft,maxRight);
}
