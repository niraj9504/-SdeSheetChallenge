#include<bits/stdc++.h>
vector<int> maxMinWindow(vector<int> nums, int n) {
    vector<int> lse(n),rse(n);//left smaller and right smaller element
    stack<int> st;
    //lse
    for(int i=0;i<n;i++){
        while(!st.empty() && nums[i]<=nums[st.top()])st.pop();
        lse[i]=(st.empty())?-1:st.top();
        st.push(i);
    }
    while(!st.empty())st.pop();
    //rse
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && nums[i]<=nums[st.top()])st.pop();
        rse[i]=(st.empty())?n:st.top();
        st.push(i);
    }
    //finally
    vector<int> ans(n,INT_MIN);
    for(int i=0;i<n;i++){
        int len=rse[i]-lse[i]-1;//length of window
        ans[len-1]=max(ans[len-1],nums[i]);
    }
    for(int i=n-2;i>=0;i--){
        ans[i]=max(ans[i],ans[i+1]);
    }
    return ans;
}
