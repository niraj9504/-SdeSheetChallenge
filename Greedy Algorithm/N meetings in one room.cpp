//hackerrank(easy->sort by ending time)
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
     static bool comp(pair<int,int>&a ,pair<int,int> &b){
        if(a.second==b.second)return a.first<b.first;
        return a.second<b.second;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({start[i],end[i]});
        }
        sort(v.begin(),v.end(),comp);
        
        int count=1;
        int right=v[0].second;
        for(int i=1;i<n;i++){
            if(right<v[i].first){
                count++;
                right=v[i].second;
            }
        }
        return count;
    }
};
//code studio->by making class/struct and also try to do without it
#include<bits/stdc++.h>
class meeting{
    public:
    int start;
    int end;
    int pos;
};
static bool comp(meeting &m1,meeting &m2){
    if(m1.end!=m2.end)return m1.end<m2.end;
    else return m1.pos<m2.pos;
}
vector<int> maximumMeetings(vector<int> &s, vector<int> &e) {
    int n=s.size();
    meeting meet[n];
    for(int i=0;i<n;i++){
        meet[i].start=s[i];
        meet[i].end=e[i];
        meet[i].pos=i+1;
    }
    sort(meet,meet+n,comp);
    vector<int> ans;
    int right=meet[0].end;
    ans.push_back(meet[0].pos);
    for(int i=1;i<n;i++){
        if(right<meet[i].start){
            ans.push_back(meet[i].pos);
            right=meet[i].end;
        }
    }
    return ans;
}
