#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &nums, int n)
{
    //next_permutation(nums.begin(),nums.end());
        ///**Narayana Pandita Algo.. see wikipedia** //
        int i=nums.size()-2;
        while(i>=0){
            if(nums[i]<nums[i+1]){
                break;
            }
            i--;
        }
        
        if(i!=-1){
            int j=nums.size()-1;
            for(j;j>i;j--){
                if(nums[j]>nums[i]){
                    break;
                }
            }
            swap(nums[i],nums[j]);
            reverse(nums.begin()+i+1,nums.end());
        }
        else{
            reverse(nums.begin(),nums.end());
        }
    return nums;
}
