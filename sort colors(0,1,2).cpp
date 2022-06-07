//method 1
#include <bits/stdc++.h> 
void sort012(int *nums, int n)
{
   //   Write your code here
    int cnt0=0,cnt1=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0)cnt0++;
            else if(nums[i]==1)cnt1++;
        }
        //int n=nums.size();
            int i=0;
            while(cnt0){
                nums[i++]=0;
                cnt0--;
            }
            while(cnt1){
                nums[i++]=1;
                cnt1--;
            }
            while(i<n){
                nums[i++]=2;
            }
}
//method 2 dutch flag
class Solution {
public:
    void sortColors(vector<int>& nums) {
        //try radix sort
        int low=0,mid=0,high=nums.size()-1;
        while(mid<=high){
            if(nums[mid]==2){
                swap(nums[mid],nums[high]);
                high--;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[low],nums[mid]);
                low++;mid++;
            }
        }
    }
};
//method 3 Radix sort (similar as count sort but can work for larger sizes)


