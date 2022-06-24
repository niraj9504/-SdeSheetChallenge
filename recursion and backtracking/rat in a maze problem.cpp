// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void path(int i,int j,vector<vector<int>> &m,int n,string temp,vector<string> &ans){
        if(i<0 || j<0 || i>=n ||j>=n || m[i][j]==0){
            return;
        }
        if(i==n-1 && j==n-1){
            ans.push_back(temp);
            return;
        }
        if(m[i][j]==1){
            m[i][j]=0;
            //down
            temp.push_back('D');//temp+='D';
            path(i+1,j,m,n,temp,ans);
            temp.pop_back();
            
            //right
            temp.push_back('R');
            path(i,j+1,m,n,temp,ans);
            temp.pop_back();
            
            //up
            temp.push_back('U');
            path(i-1,j,m,n,temp,ans);
            temp.pop_back();
            
            //left
            temp.push_back('L');
            path(i,j-1,m,n,temp,ans);
            temp.pop_back();
            m[i][j]=1;
        }
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        string temp="";
        vector<string> ans;
        path(0,0,m,n,temp,ans);
        return ans;
    }
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
//also works without this
    void rat(int r,int c,string s,vector<string> &ans,vector<vector<int>> &m,int n){
        if(r<0 || r>=n || c<0 || c>=n || m[r][c]==0)return;
        if(r==n-1 && c==n-1){
            ans.push_back(s);
            return;
        }
        //if(m[r][c]==1){ ********
            m[r][c]=0;
            s+='D';
            rat(r+1,c,s,ans,m,n);
            s.pop_back();
            s+='U';
            rat(r-1,c,s,ans,m,n);
            s.pop_back();
            s+='R';
            rat(r,c+1,s,ans,m,n);
            s.pop_back();
            s+='L';
            rat(r,c-1,s,ans,m,n);
            s.pop_back();
            m[r][c]=1;
        //}
        
    }
