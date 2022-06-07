class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0)return;
        if(m==0){
            nums1=nums2;
            return;
        }
        int i=0,j=0,k=m;
        while(i<m){
            if(nums1[i]<=nums2[0]){
                i++;
            }
            else{
                swap(nums1[i],nums2[0]);
                for(int j=n-1;j>0;j--){
                    if(nums2[j]<nums2[0]){
                        swap(nums2[0],nums2[j]);
                    }
                }
                i++;
            }
        }
        j=0;
        while(k<(n+m)){
            nums1[k++]=nums2[j++];
        }
    }
};
//O(1) and easy solution
#include <bits/stdc++.h> 
vector<int> ninjaAndSortedArrays(vector<int>& nums1, vector<int>& nums2, int m, int n) {
	int i = m - 1, j = n - 1, k = m + n - 1;
     while(i >= 0 and j >= 0) {
         if(nums1[i] < nums2[j]) {
             nums1[k--] = nums2[j--];
         } else {
             nums1[k--] = nums1[i--];
         }
     }
     while(j >= 0) {
         nums1[k--] = nums2[j--];
     }
    return nums1;
}
