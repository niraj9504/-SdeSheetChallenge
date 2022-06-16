#include<bits/stdc++.h>

int maximumActivities(vector<int> &s, vector<int> &f) {
    vector<pair<int,int>> v;
    int n=s.size();
    for(int i=0;i<n;i++){
        v.push_back({f[i],s[i]});
    }
    sort(v.begin(),v.end());
    int cnt=0,right=INT_MIN;
    for(int i=0;i<n;i++){
        if(right<=v[i].second){
            cnt++;
            right=v[i].first;
        }
    }
    return cnt;
}
