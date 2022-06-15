//leetcode(easier)
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt=0,best=-1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==1)cnt++;
            else{
                cnt=0;
            }
            best=max(best,cnt);
        }
        return best;
    }
};
//code studio(tricky)
int longestSubSeg(vector<int> &arr , int n, int k){
    int i=0,j=0;
    int ans=0;
    while(j<n){
        if(arr[j]==0)k--;
        if(k<0){
            while(arr[i]==1)i++;
            i++;k++;
        }
        else{
            ans=max(ans,j-i+1);
        }
        j++;
    }
    return ans;
}
