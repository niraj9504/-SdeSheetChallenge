//method 1 :-> by Kadane's Algo
#include <bits/stdc++.h> 
long long maxSubarraySum(int nums[], int n)
{
        long long maxi=nums[0];long long best=0;
        for(int i=1;i<n;i++){
            maxi=max((long long)nums[i],(long long)(maxi+nums[i]));
            best=max(best,(long long)maxi);
        }
        return best;
}
//method 2 :-> divide and conquer
