//also try similar questions->nqueens ii ...
class Solution {
public:
    bool isPoss(int r,int c,vector<string> &grid){
        for(int j=c;j>=0;j--){
            if(grid[r][j]=='Q')return false;
        }
        for(int i=r,j=c;i>=0 && j>=0;i--,j--){
            if(grid[i][j]=='Q')return false;
        }
        for(int i=r,j=c;i<grid.size() && j>=0;i++,j--){
            if(grid[i][j]=='Q')return false;
        }
        return true;
    }
    void nqueen(int col,vector<vector<string>> &ans,vector<string> &grid,int n){
        if(col==n){
            ans.push_back(grid);
            return ;
        }
        for(int i=0;i<n;i++){
            if(isPoss(i,col,grid)){
                grid[i][col]='Q';
                nqueen(col+1,ans,grid,n);
                grid[i][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string s(n,'.');
        vector<string> grid(n,s);
        nqueen(0,ans,grid,n);
        return ans;
    }
};
