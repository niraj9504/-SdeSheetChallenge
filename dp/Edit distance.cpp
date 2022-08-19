//important and hard
RECURSION:-O(3^n) time
```
class Solution {
public:
    int solve(int i,int j,string &s1,string &s2){
        if(i==s1.size()){
            return s2.size()-j;//we are at end of s1, no further replace,delete=>rest of s1 is inserted to s2 make it equal to s2 
        }
        if(j==s2.size()){
            return s1.size()-i;//we are at end of s2,remaining char of s1 is deleted to make it equal to s1
        }
        if(s1[i]==s2[j]){
            return 0+solve(i+1,j+1,s1,s2);//both matching
        }
        //insert,delete,replace=>min steps
        int x=solve(i,j+1,s1,s2)+1;//insert in s1=>j of s2 increases
        int y=solve(i+1,j,s1,s2)+1;//deleted at i=>now move to i+1 
        int z=solve(i+1,j+1,s1,s2)+1;//replace the curr char, they become equal=>moves both i and j
        return min(min(x,y),z);
        
    }
    int minDistance(string s1, string s2) {
        return solve(0,0,s1,s2);
    }
};
```

MEMOIZATION:- O(n * m) Time, 2 * O(n+m) space (auxillary space included)
```
class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i,int j,string &s1,string &s2){
        if(i==s1.size()){
            return s2.size()-j;//we are at end of s1, no further replace,delete=>rest of s1 is inserted to s2 make it equal to s2 
        }
        if(j==s2.size()){
            return s1.size()-i;//we are at end of s2,remaining char of s1 is deleted to make it equal to s1
        }
        if(dp[i][j]!=-1)return dp[i][j];
        if(s1[i]==s2[j]){
            return dp[i][j]=0+solve(i+1,j+1,s1,s2);//both matching
        }
        //insert,delete,replace=>min steps
        int x=solve(i,j+1,s1,s2)+1;//insert in s1=>j of s2 increases
        int y=solve(i+1,j,s1,s2)+1;//deleted at i=>now move to i+1 
        int z=solve(i+1,j+1,s1,s2)+1;//replace the curr char, they become equal=>moves both i and j
        return dp[i][j]=min(min(x,y),z);
        
    }
    int minDistance(string s1, string s2) {
        dp.resize(s1.size(),vector<int>(s2.size()+1,-1));
        return solve(0,0,s1,s2);
    }
};
```

BOTTOM UP:-
```
class Solution {
public:
    vector<vector<int>> dp;
    int minDistance(string s1, string s2) {
        dp.resize(s1.size()+1,vector<int>(s2.size()+1,0));
        //return solve(0,0,s1,s2);
        
        //base cases
        for(int i=0;i<=s1.size();i++)dp[i][0]=i;
        for(int j=0;j<=s2.size();j++)dp[0][j]=j;
        
        //bottom up after base cases
        for(int i=1;i<=s1.size();i++){
            for(int j=1;j<=s2.size();j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=0+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=1+min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
                }
            }
        }
        return dp[s1.size()][s2.size()];
    }
};
```

//NOTE:- space can further be optimised .TRY
