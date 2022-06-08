class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int t) {
        int r=0,c=mat[0].size()-1,m=mat.size();
        while(r<m && c>=0){
            if(mat[r][c]==t)return true;
            else if(mat[r][c]>t){
                c--;
            }
            else{
                r++;
            }
        }
        return false;
    }
};
//try search in a 2d mat ii from leetcode (try logm+lonn time complexity) also
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int t) {
        //start from top right corner
        int m=mat.size(),n=mat[0].size();
        if(m<1 || n<1)return false;
        if(t<mat[0][0] || t>mat[m-1][n-1])return false;
        int i=0,j=n-1;
        while(i<m && j>=0){
            if(mat[i][j]==t)return true;
            else if(mat[i][j]>t)j--;
            else i++;
        }
        return false;
    }
};
