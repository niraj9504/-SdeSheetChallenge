//learn it **vvi
#include <bits/stdc++.h> 
vector<int> temp;
int merge(long long *nums,vector<int> &temp,int s,int m,int e){
    int inv=0;
    int i=s,j=m,k=s;
    while(i<=(m-1) && j<=e){
        if(nums[i]<=nums[j]){
            temp[k++]=nums[i++];
        }
        else{
            temp[k++]=nums[j++];
            inv+=(m-i);
        }
    }
    while(i<=m-1){
        temp[k++]=nums[i++];
    }
    while(j<=e){
        temp[k++]=nums[j++];
    }
    for(int i=s;i<=e;i++){
        nums[i]=temp[i];
    }
    return inv;
}
int mergesort(long long *nums,vector<int> &temp,int s,int e){
    int inv=0;
    if(s<e){
        int m=s+(e-s)/2;
        inv+=mergesort(nums,temp,s,m);
        inv+=mergesort(nums,temp,m+1,e);
        inv+=merge(nums,temp,s,m+1,e);
    }
    return inv;
}
long long getInversions(long long *arr, int n){
    temp.resize(n);
    mergesort(arr,temp,0,n-1);
}
