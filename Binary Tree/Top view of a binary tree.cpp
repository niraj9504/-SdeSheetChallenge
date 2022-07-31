// //dfs(recursion) think it giving wrong answer
// #include<bits/stdc++.h>
// void dfs(TreeNode<int> *root,map<int,int> &map,int line){
//         if(root==NULL)return;
//         //map.insert({line,root->val});bottom view
//         if(map.find(line==map.end())map.insert({line,root->val});
//         if(root->left)dfs(root->left,map,line-1);
//         if(root->right)dfs(root->right,map,line+1);
// }
// vector<int> getTopView(TreeNode<int> *root) {
//     vector<int> ans;
//     if(root==NULL)return ans;
//     map<int,int> mp;
//     dfs(root,mp,0);
//     for(auto it:mp){
//         ans.push_back(it.second);
//     }
//     return ans;
// }

//bfs
#include<bits/stdc++.h>

vector<int> getTopView(TreeNode<int> *root) {
    vector<int> ans;
    if(root==NULL)return ans;
    map<int,int> map;
    queue<pair<TreeNode<int>*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        auto x=q.front();q.pop();
        auto node=x.first;
        int dist=x.second;
        if(map.find(dist)==map.end())map[dist]=node->val;//change from bottom view
        if(node->left)q.push({node->left,dist-1});
        if(node->right)q.push({node->right,dist+1});
    }
    
    for(auto it:map)ans.push_back(it.second);
    return ans;
}
