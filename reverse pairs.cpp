class Solution {
public:
    int count=0;
    void checkcount(vector<int> &nums,int l,int m,int r){
        int right=m+1,start=l,end=r;
        while(l<=m && right<=r){
            if((long long)nums[l]>(long long)2*nums[right]){
                count+=(m-l+1);
                right++;
            }
            else{
                l++;
            }
        }
        sort(nums.begin()+start,nums.begin()+end+1);
    }
    void mergesort(vector<int> &nums,int l,int r){
        if(l==r)return;
        int mid=(l+r)/2;
        mergesort(nums,l,mid);
        mergesort(nums,mid+1,r);
        checkcount(nums,l,mid,r);
    }
    int reversePairs(vector<int>& nums) {
        mergesort(nums,0,nums.size()-1);
        return count;
    }
};
//also see others solution as the concept is used at many places
