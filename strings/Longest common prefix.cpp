//See various other methods like divide and conquer in leetcode disscussion
class Solution {
public:
    string lcp(string &a,string &b){
        int i=0,j=0,m=a.size(),n=b.size();
        string common="";
        while(i<m && j<n && a[i]==b[j]){
            common+=a[i];
            i++;j++;
        }
        return common;
    }
    string longestCommonPrefix(vector<string>& s) {
        int n=s.size();
        string prev=s[0];
        for(int i=1;i<n;i++){
            string common=lcp(prev,s[i]);
            if(common.size()==0)return common;
            prev=common;
        }
        return prev;
    }
};
