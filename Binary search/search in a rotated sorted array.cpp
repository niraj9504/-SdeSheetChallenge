class Solution {
public:
    int search(vector<int>& nums, int t) {
        int n=nums.size();
        int i=0,j=n-1;
        while(i<=j){
            int mid=(i+j)/2;
            if(nums[mid]==t){
                return mid;
            }
            if(nums[mid]>=nums[i]){
                if(nums[i]<=t && nums[mid]>=t){
                    j=mid-1;
                }
                else{
                    i=mid+1;
                }
            }
            else{
                if(nums[mid]<=t && nums[j]>=t){
                    i=mid+1;
                }
                else{
                    j=mid-1;
                }
            }
        }
        return -1;
    }
};
