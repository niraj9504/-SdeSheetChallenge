/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(vector<int> &pre,vector<int> &in,int left,int right,int &i){
        if(left>right)return NULL;
        int piv=0;
        while(pre[i]!=in[piv])piv++;
        
        i++;
        TreeNode* node=new TreeNode(in[piv]);
        node->left=solve(pre,in,left,piv-1,i);
        node->right=solve(pre,in,piv+1,right,i);
        return node;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n=pre.size(),i=0;
        return solve(pre,in,0,n-1,i);
    }
};
