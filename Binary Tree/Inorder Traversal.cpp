//for revision see the striver playlist
//also think for iterative approach, morris traversal
void solve(TreeNode* root,vector<int> &ans){
    if(root==NULL)return;
    solve(root->left,ans);
    ans.push_back(root->data);
    solve(root->right,ans);
}
vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    solve(root,ans);
    return ans;
}

//m2 (TLE)
vector<int> getInOrderTraversal(TreeNode *root)
{
    if(root==NULL)return {};
    vector<int> lt=getInOrderTraversal(root->left);
    lt.push_back(root->data);
    vector<int> rt=getInOrderTraversal(root->right);
    for(int i=0;i<rt.size();i++){
        lt.push_back(rt[i]);
    }
    return lt;
}
