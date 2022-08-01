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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        long long ans=INT_MIN;
        while(!q.empty()){
            int sz=q.size();
            long long curr_min=q.front().second;
            long long  l,r;
            for(int i=0;i<sz;i++){
                auto it=q.front();q.pop();
                long long id=it.second-curr_min;
                if(i==0)l=id;
                if(i==sz-1)r=id;
                if(it.first->left)q.push({it.first->left,(long long)(2*id+1)});
                if(it.first->right)q.push({it.first->right,(long long)(2*id+2)});
                ans=max(ans,r-l+1);
            }
        }
        return ans;
    }
};
//codestudio
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>
int getMaxWidth(TreeNode<int> *root)
{    
    if(root==NULL)return 0;
    queue<TreeNode<int> *> q;
    q.push(root);
    long long ans=INT_MIN;
    while(!q.empty()){
        long long sz=q.size();
        for(int i=0;i<sz;i++){
            auto it=q.front();q.pop();
            if(it->left)q.push(it->left);
            if(it->right)q.push(it->right);
        }
        ans=max(ans,sz);
    }
    return ans;
}
