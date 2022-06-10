#include <bits/stdc++.h> 
int subarraysXor(vector<int> &nums, int x)
{
    unordered_map<int,int> map;
    int n=nums.size();
    int xorr=0;int cnt=0;
    for(int i=0;i<n;i++){
        xorr^=nums[i];
        int h=xorr^x;
        if(xorr==x)cnt++;//P^B = Q, =>P^B^P = Q^P ,=> B = Q^P
        if(map.find(h)!=map.end())cnt+=map[h];
        map[xorr]++;
    }
    return cnt;
}
