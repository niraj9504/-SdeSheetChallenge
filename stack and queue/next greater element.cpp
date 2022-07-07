//if elements are unique(easy)
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> map;//val nextGreaterElement
        stack<int> st;
        for(auto it:nums2){
            while(!st.empty() && it>st.top()){
                map.insert({st.top(),it});
                st.pop();
            }
            st.push(it);
        }
        int n=nums1.size();
        for(int i=0;i<n;i++){
            auto it=map.find(nums1[i]);
            if(it!=map.end()){
                nums1[i]=it->second;
            }
            else nums1[i]=-1;
        }
        return nums1;
    }
};
//if elements are not unique
#include<bits/stdc++.h>
vector<int> nextGreater(vector<int> &arr, int n) {
    vector<int> nge(n,-1);
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && st.top()<=arr[i])st.pop();
        if(i<n){
            if(!st.empty()){
                nge[i]=st.top();
            }
        }
        st.push(arr[i]);
    }
    return nge;
}
