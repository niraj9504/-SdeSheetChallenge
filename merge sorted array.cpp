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
