class Solution {
public:
    bool isPoss(int r,int c,vector<vector<char>> &board,char ch){
        for(int i=0;i<9;i++){
            if(board[i][c]==ch)return false;
            if(board[r][i]==ch)return false;
            if(board[3*(r/3)+i/3][3*(c/3)+i%3]==ch)return false;//learn this
        }
        return true;
    }
    bool solve(vector<vector<char>> &board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(char c='1';c<='9';c++){
                        if(isPoss(i,j,board,c)){
                            board[i][j]=c;
                            if(solve(board))return true;
                            else board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);        
    }
};
