//use similar as rabin carp, and similar TC as KMP algo
// Z[k]=longest substring starting at k which is also prefix of the string
//     a a b x a a y a a b
//     0 1 2 3 4 5 6 7 8 9
//Z[]= 0 1 0 0 2 1 0 3 1 0
//=>text= x a b c a b z a b c , pattern=abc
//finding Z[] by combining text+pattern $ b/w them
//  => a b c $ x a b c a b  z  a  b  c 
//     0 1 2 3 4 5 6 7 8 9 10 11 12 13
//z[]= 0 0 0 0 0 3 0 0 2 0  0  3  0  0
//Now find value = pattern.size in Z, that will be your answers index(here 3)
//TUSHAR ROY video
#include<bits/stdc++.h>
vector<int> calculateZ(string &s){
    int n=s.size();
    vector<int> z(n,0);
    int l=0,r=0;
    z[0]=0;
    for(int i=1;i<n;i++){
        if(i>r){
            l=r=i;
            while(r<n && s[r]==s[r-l]){
                r++;
            }
            z[i]=r-l;
            r--;
        }
        else{
            //we are operating inside matched box
            int i1=i-l;
            //if values doesn't streches till right bound then just copy it
            if(z[i1]<r-i+1){
                z[i]=z[i1];
            }
            else{ //otherwise try to see if there are more matches
                l=i;
                while(r<n && s[r]==s[r-l])r++;
                z[i]=r-l;
                r--;
            }
        }
    }
    return z;
}
int zAlgorithm(string s, string p, int n, int m)
{
	string x="";
    x+=p+"$"+s;
    vector<int> z=calculateZ(x);
    
    int cnt=0;
    for(int i=0;i<z.size();i++){
        if(z[i]==m)cnt++;//index=(i-m-1)
    }
    return cnt;
}
