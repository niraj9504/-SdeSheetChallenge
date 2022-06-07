//leetcode solution 1
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //transpose +reverse=rotated
        int n=matrix.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j>i){
                    swap(matrix[i][j],matrix[j][i]);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n/2;j++){
                swap(matrix[i][j],matrix[i][n-1-j]);
            }
        }
    }
};
//leetcode solution 2 :- y'=ycos-xsin
void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int a = 0;
        int b = n-1;
        while(a<b){
            for(int i=0;i<(b-a);++i){
                swap(matrix[a][a+i], matrix[a+i][b]);
                swap(matrix[a][a+i], matrix[b][b-i]);
                swap(matrix[a][a+i], matrix[b-i][a]);
            }
            ++a;
            --b;
        }
    }

//codestudio solution
#include <bits/stdc++.h> 

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    // similar to spiral matrix
    int rs=0,cs=0,prev,curr;
    while(rs<n && cs<m){
        if(rs==n-1 || cs==m-1){
            break;
        }
        prev=mat[rs+1][cs];
        for(int i=cs;i<m;i++){
            curr=mat[rs][i];
            mat[rs][i]=prev;
            prev=curr;
        }
        rs++;
        for(int i=rs;i<n;i++){
            curr=mat[i][m-1];
            mat[i][m-1]=prev;
            prev=curr;
        }
        m--;
        if(rs<n){//no need
            for(int i=m-1;i>=cs;i--){
                curr=mat[n-1][i];
                mat[n-1][i]=prev;
                prev=curr;
            }
        }
        n--;
        if(cs<m){//no need
            for(int i=n-1;i>=rs;i--){
                curr=mat[i][cs];
                mat[i][cs]=prev;
                prev=curr;
            }
        }
        cs++;
    }

}
//no need of taking if cases 
#include <bits/stdc++.h> 

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    // similar to spiral matrix
    int rs=0,cs=0,prev,curr;
    while(rs<n && cs<m){
        if(rs==n-1 || cs==m-1){
            break;
        }
        prev=mat[rs+1][cs];
        for(int i=cs;i<m;i++){
            curr=mat[rs][i];
            mat[rs][i]=prev;
            prev=curr;
        }
        rs++;
        for(int i=rs;i<n;i++){
            curr=mat[i][m-1];
            mat[i][m-1]=prev;
            prev=curr;
        }
        m--;
            for(int i=m-1;i>=cs;i--){
                curr=mat[n-1][i];
                mat[n-1][i]=prev;
                prev=curr;
            }
        n--;
            for(int i=n-1;i>=rs;i--){
                curr=mat[i][cs];
                mat[i][cs]=prev;
                prev=curr;
            }
        cs++;
    }

}

//Try it by recursion 
