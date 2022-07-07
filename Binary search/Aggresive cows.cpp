#include<bits/stdc++.h>
bool isPossible(int gap,vector<int> p,int players){
    int cnt=1;
    int prev=p[0];
    for(int i=1;i<p.size();i++){
        if(p[i]-prev>=gap){
            cnt++;
            prev=p[i];
        }
    }
    if(cnt>=players)return true;
    return false;
}

int chessTournament(vector<int> p , int n ,  int c){
    sort(p.begin(),p.end());
	int low=1,high=p[n-1]-p[0];
    while(low<=high){
        int mid=(low+high)>>1;
        if(isPossible(mid,p,c)){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return high;
}
