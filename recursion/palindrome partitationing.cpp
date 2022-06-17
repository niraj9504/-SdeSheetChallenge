class Solution {
public:
    bool isPal(string s,int i,int j){
        while(i<j){
            if(s[i++]!=s[j--])return false;
        }
        return true;
    }
    void recursion(int i,vector<string> &temp,vector<vector<string>> &ans,string s){
        if(i==s.size()){
            ans.push_back(temp);
            return;
        }
        for(int j=i;j<s.size();j++){
            if(isPal(s,i,j)){
                temp.push_back(s.substr(i,j-i+1));
                recursion(j+1,temp,ans,s);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        recursion(0,temp,ans,s);
        return ans;
    }
};
//it can be optimised(isPal=>in O(1) )
class Solution {
public:
    // bool isPal(string s,int i,int j){
    //     while(i<j){
    //         if(s[i++]!=s[j--])return false;
    //     }
    //     return true;
    // }
    vector<vector<int>> dp;
    void recursion(int i,vector<string> &temp,vector<vector<string>> &ans,string s){
        if(i==s.size()){
            ans.push_back(temp);
            return;
        }
        for(int j=i;j<s.size();j++){
            if(s[i]==s[j] && (j-i<=2 || dp[i+1][j-1])){
                dp[i][j]=1;
                temp.push_back(s.substr(i,j-i+1));
                recursion(j+1,temp,ans,s);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        dp.resize(s.size(),vector<int>(s.size(),0));
        recursion(0,temp,ans,s);
        return ans;
    }
};
