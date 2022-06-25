//m1(binary search)
int Solution::findMedian(vector<vector<int> > &matrix) {
    int n=matrix.size();  //row
    int m=matrix[0].size(); //column
    long long reqElements=(long long)(n*m)/2;    //x<=median<=x -->then median
    int low=1,high=1e9;
    while(low<=high){
        int mid=(low+high)/2;
        long long x=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]<=mid){
                    x++;
                }
            }
        }
        //if(x==reqElements)ans= mid;
        if(x<=reqElements){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return low;
}
//m2 (easy)
int Solution::findMedian(vector<vector<int> > &A) {
    int m=A.size(),n=A[0].size();
    for(int r=m-1;r>0;r--){//first row not included because we are adding all elements in this row
        for(int c=0;c<n;c++){
            A[0].push_back(A[r][c]);
        }
    }
    sort(A[0].begin(),A[0].end());
    return A[0][(m*n/2)];
}
