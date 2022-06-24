//word break i
//m1(recursion)TLE
class Solution {
public:
    bool wordBreak(string s, vector<string>& w) {
        if(find(w.begin(),w.end(),s)!=w.end())return true;
        for(int i=1;i<s.size();i++){
            string s1=s.substr(0,i);
            if(find(w.begin(),w.end(),s1)!=w.end() && wordBreak(s.substr(i),w))return true;
        }
        return false;
    }
};
//memoization(slower)
class Solution {
public:
    unordered_map<string,bool> map;//int dp[300]
    bool wordBreak(string s, vector<string>& w) {
        if(find(w.begin(),w.end(),s)!=w.end())return true;
        if(map.find(s)!=map.end())return map[s];
        for(int i=1;i<s.size();i++){
            string s1=s.substr(0,i);
            if(find(w.begin(),w.end(),s1)!=w.end() && wordBreak(s.substr(i),w))return map[s]=true;
        }
        return map[s]=false;
    }
};
//m3
class Solution {
public:
    bool wordBreak(string s, vector<string>& w) {
        int n=s.size();
        vector<bool> dp(n+1,0);dp[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                if(dp[j] && find(w.begin(),w.end(),s.substr(j,i-j))!=w.end()){
                    dp[i]=true;
                }
            }
        }
        return dp[n];
    }
};
//word break ii
class Solution {
public:
    vector<string> combine(string word,vector<string> prev){
        for(int i=0;i<prev.size();i++){
            prev[i]+=' '+word;
        }
        return prev;
    }
    unordered_map<string,vector<string>> map;
    vector<string> wordBreak(string s, vector<string>& w) {
        if(map.find(s)!=map.end())return map[s];
        vector<string> ans;
        if(find(w.begin(),w.end(),s)!=w.end()){
            ans.push_back(s);
        }
        for(int i=1;i<s.size();i++){
            string word=s.substr(i);//i to end
            if(find(w.begin(),w.end(),word)!=w.end()){
                string rem=s.substr(0,i);
                vector<string> prev=combine(word,wordBreak(rem,w));
                //ans+=prev;
                ans.insert(ans.end(),prev.begin(),prev.end());
            }
        }
        return map[s]=ans;
    }
};
