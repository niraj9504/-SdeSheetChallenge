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
