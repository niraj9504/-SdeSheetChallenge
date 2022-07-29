//m1(wrong but keep in mind)
vector<int> stringMatch(string &s, string &p) {
    //int idx=s.find(p);
    vector<int> ans;
//     if(idx!=string::npos)
//         ans.push_back(idx);
//     else return ans;
    int idx=0;
    while((idx=s.find(p,idx))!=string::npos){
        ans.push_back(idx);
        idx+=p.size();
    }
    return ans;
}
//Brute force O(m*n)
#include<bits/stdc++.h>
bool check(string &a,string &b){
    for(int i=0;i<a.size();i++){
        if(a[i]!=b[i])return false;
    }
    return true;
}

vector<int> stringMatch(string &s, string &p) {
    vector<int> ans;
    int n=s.size();
    int m=p.size();
    for(int i=0;i<=n-m;i++){
        string temp=s.substr(i,m);
        if(check(temp,p)){
            ans.push_back(i);
        }
    }
    return ans;
}

//Rabin Carp (find hash value by taking a prime value then match) abc=> 1+2*3+3*(3^2) 
//should use bigger prime no. like 101, and ASCII value of a,b,c,... (of string)
//x=oldHash-val(oldChar)
//x=x/prime
//newHash=x+prime^(m-1)*val(newChar) , m=size of smaller string
#include<bits/stdc++.h>
int prime=5;
long long createHash(string &s,int m){
    long long hash=0;
    for(int i=0;i<m;i++){
        hash+=(s[i]-'A'+1)*pow(5,i);
    }
    return hash;
}
long long recalculateHash(string &s,int i,int m,long long oldHash){
    long long newHash=oldHash-(s[i]-'A'+1);
    newHash=newHash/5;
    newHash+=(s[i+m]-'A'+1)*pow(5,m-1);
    return newHash;
}
bool checkEqual(string &a,string &b){
    for(int i=0;i<a.size();i++){
        if(a[i]!=b[i])return false;
    }
    return true;
}
vector<int> stringMatch(string &s, string &p) {
    int n=s.size(),m=p.size();
    vector<int> ans;
    long long sHash=createHash(s,m), pHash=createHash(p,m);
    for(int i=0;i<=n-m;i++){
        string x=s.substr(i,m);
        if(pHash==sHash && checkEqual(x,p)){
            ans.push_back(i);
        }
        //cout<<pHash<<" "<<sHash<<endl;
        sHash=recalculateHash(s,i,m,sHash);
        //sHash=((sHash-s[i]))
    }
    return ans;
}

