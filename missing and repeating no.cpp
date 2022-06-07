//with extra space
#include <bits/stdc++.h> 

pair<int,int> missingAndRepeating(vector<int> &nums, int n)
{
	vector<int> temp(n+1,0);
    int x,y;
    for(auto it:nums){
        if(temp[it]){
            y=it;
        }
        else{
            temp[it]=1;
        }
    }
    x=find(temp.begin()+1,temp.end(),0)-temp.begin();
    return {x,y};
}
//try with extra space
