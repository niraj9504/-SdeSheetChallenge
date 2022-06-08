class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        long long nn=n;
        if(nn<0){
            nn=(-1)*nn;
        }
        while(nn!=0){
            if(nn&1){
                ans=ans*x;
                nn=nn-1;
            }
            else{
                x=x*x;
                nn=nn/2;
            }
        }
        if(n<0){
            ans=(double)(1.0)/(double)(ans);
        }
        return ans;
    }
};
//codestudio
#include <bits/stdc++.h> 
int modularExponentiation(int x, int n, int m) {
	// Write your code here.
    long long ans=1;
    long long xx=x;
    while(n){
        if((n&1)){
            ans=(ans*xx%m)%m;
            n-=1;
        }
        else{
            xx=(xx%m*xx%m)%m;
            n>>=1;
        }
    }
    return (int)(ans%m);
}
