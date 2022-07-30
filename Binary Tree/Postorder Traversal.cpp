//check for iterative one
void solve(TreeNode* root,vector<int> &ans){
    if(root==NULL)return;
    solve(root->left,ans);
    solve(root->right,ans);
    ans.push_back(root->data);
}
vector<int> getPostOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    solve(root,ans);
    return ans;
}
