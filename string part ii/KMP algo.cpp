//KMP substring search like rabin carp,Z algo (does the given pattern exist in the string given)
//naive app->tc=O(mn), but kmp=>tc=O(m+n)
// pattern= a b c d a b c a  (i and j at a)
//     idx= 0 1 2 3 4 5 6 7
//   kmp[]= 0 0 0 0 1 2 3 1
//**TUSHAR ROY YOUTUBE
  #include<bits/stdc++.h>
vector<int> computeTempArr(string &pattern){
    int n=pattern.size();
    vector<int> lps(n);
    lps[0]=0;
    int j=0;
    for(int i=1;i<n;){
        if(pattern[i]==pattern[j]){
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
bool findPattern(string p, string s)
{
    vector<int> lps=computeTempArr(p);
    int i=0,j=0,m=p.size(),n=s.size();
    while(i<n && j<m){
        if(s[i]==p[j]){
            i++;j++;
        }
        else{
            if(j!=0){
                j=lps[j-1];
            }
            else{
                i++;
            }
        }
    }
    if(j==m)return true;
    return false;
}
  
