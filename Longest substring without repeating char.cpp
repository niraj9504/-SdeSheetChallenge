//slower one
#include <bits/stdc++.h> 
int uniqueSubstrings(string s)
{
    int r=0,n=s.size(),cnt=1;
        if(n<=1)return n;
        int l=0;
        unordered_set<char> map;
        while(r<n){
            auto it=map.find(s[r]);
            if(it!=map.end()){  //duplicate found
                while(l<r && map.find(s[r])!=map.end()){
                    map.erase(s[l]);
                    l++;
                }
            }
            map.insert(s[r]);
            cnt=max(cnt,r-l+1);
            r++;
        }
        return cnt;
}
//faster 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mp(256,-1);
        int n=s.size();
        int left=0,right=0,ans=0;
        while(right<n){
            if(mp[s[right]]!=-1){
                left=max(left,mp[s[right]]+1);
            }
                mp[s[right]]=right;
                ans=max(ans,right-left+1);
            
               right++;
        }
        return ans;
    }
};
