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
//m1-> bit manupulation(xor) **imp
//try

//m2->vvi
#include <bits/stdc++.h> 

pair<int,int> missingAndRepeating(vector<int> &nums, int n)
{
	int x,y,i=0;
    while(i<n){
        if(nums[i]!=nums[nums[i]-1]){
            swap(nums[i],nums[nums[i]-1]);
        }
        else{
            i++;
        }
    }
    //for(auto it:nums)cout<<it<<" ";cout<<endl;
    for(int i=0;i<n;i++){
        if(nums[i]!=i+1){
            x=i+1;
            y=nums[i];
            break;
        }
    }
    return {x,y};
}


