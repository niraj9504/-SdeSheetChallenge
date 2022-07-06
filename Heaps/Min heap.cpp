vector<int> minHeap(int n, vector<vector<int>>& q) {
    priority_queue<int,vector<int>,greater<int>> pq;
    vector<int> ans;
    for(auto it:q){
        if(it.size()==1 && it[0]==1){
            ans.push_back(pq.top());
            pq.pop();
        }
        else{
            pq.push(it[1]);
        }
    }
    return ans;
}
