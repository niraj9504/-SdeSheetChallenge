//bfs try dfs
vector<int> bottomView(BinaryTreeNode<int> * root){
    vector<int> ans;
    map<int,int> map;//sorted order index,value
    queue<pair<BinaryTreeNode<int>*,int>> q;//nodes,indexes
    q.push({root,0});
    while(!q.empty()){
        auto x=q.front();q.pop();
        auto node=x.first;
        int dist=x.second;
        map[dist]=node->data;
        if(node->left)q.push({node->left,dist-1});
        if(node->right)q.push({node->right,dist+1});
    }
    for(auto it:map){
        ans.push_back(it.second);
    }
    return ans;
}
