//see the solution of tle in leetcode
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        ans.push_back({intervals[0][0],intervals[0][1]});int k=0;
        for(int i=1;i<intervals.size();i++){
            if(ans[k][1]>=intervals[i][0]){
                
                ans[k][1]=max(intervals[i][1],ans[k][1]);
            }
            else{
                ans.push_back({intervals[i][0],intervals[i][1]});
                k++;
            }
        }
        return ans;
    }
};
//try for O(1) space (merge inplace vvi
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& s) {
        //inplace merge
        sort(s.begin(),s.end());
        int i=0;
        for(auto it:s){
            if(it[0]<=s[i][1]){
                s[i][1]=max(s[i][1],it[1]);
            }
            else{
                i++;
                s[i]=it;
            }
        }
        s.resize(i+1);//creating duplicates and pushing it to the right and at last deleting by resizing it
        return s;
    }
};
