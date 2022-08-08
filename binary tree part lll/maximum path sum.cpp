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
    int ans=INT_MIN;
    int dfs(TreeNode* root){
        if(root==NULL)return 0;
        int lh=max(0,dfs(root->left));
        int rh=max(0,dfs(root->right));
        ans=max(ans,lh+rh+root->val);
        return root->val+max(lh,rh);
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};

//codestudio
/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>
using ll=long long;
//#define ll long long
//ll ans=INT_MIN;
ll cnt;
ll solve(TreeNode<int> *root,ll &ans){
    if(root==NULL)return 0;
    if(!root->left && ! root->right)cnt++;//root->left==NULL
    ll lh=solve(root->left,ans);
    ll rh=solve(root->right,ans);
    ll temp=root->val+max(lh,rh);
    ll mx=max(temp,lh+rh+root->val);
    ans=max(ans,mx);
    return temp;//temp is height type
}
long long int findMaxSumPath(TreeNode<int> *root)
{    
    if(root==NULL)return -1;
    cnt=0;
    ll ans=INT_MIN;
    solve(root,ans);
    if(cnt==1)return -1;
    return ans;
}
