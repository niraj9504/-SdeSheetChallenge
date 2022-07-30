    // kmp algorithm ka lps apply kro
    // kaise???
    // lps kya btata h? proper prefix suffix,
    // mtlb agar A and (A#A') mein proper prefix suffix nikale to wo 
    // palindrome hi hoga jo pehle se starting of string me present hai,
    // so baki len(A) - lps[last] will be answer
    // please dry run on page
#include<bits/stdc++.h>
vector<int> computeTempArr(string &s){
    int n=s.size();
    vector<int> lps(n);
    lps[0]=0;
    int i=1,j=0;
    while(i<n){
        if(s[i]==s[j]){
            lps[i]=j+1;
            i++;j++;
        }
        else{
            if(j!=0){
                j=lps[j-1];
            }
            else{
                lps[i]=0;
                i++;
            }
        }
    }
    return lps;
}
int minCharsforPalindrome(string s) {
	//KMP
    int n=s.size();
    string b=s;
    reverse(b.begin(),b.end());
    s+="$"+b;
    vector<int> lps=computeTempArr(s);
	int m=s.size();
    int len=lps[m-1];//lps of last
    return n-len;
}
