//m1(bfs)
vector<int> getLeftView(TreeNode<int> *root)
{
    vector<int> ans;
    if(root==NULL)return ans;
    queue<TreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        int sz=q.size();
        for(int i=0;i<sz;i++){
            auto x=q.front();q.pop();
            if(i==0)ans.push_back(x->data);
            if(x->left)q.push(x->left);
            if(x->right)q.push(x->right);
        }
    }
    return ans;
}
//m2()

void dfs(TreeNode<int> *root,int h,vector<int> &ans){
    if(root==NULL)return;
    if(h==ans.size())ans.push_back(root->data);
    dfs(root->left,h+1,ans);
    dfs(root->right,h+1,ans);
}
vector<int> getLeftView(TreeNode<int> *root)
{    
    vector<int> ans;
    //if(root==NULL)return ans;
    dfs(root,0,ans);
    return ans;
}
