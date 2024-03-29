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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> level;
        if(root==NULL)return ans;
        queue<TreeNode*> q;
        q.push(root);
        int sign=-1;//for left to right or right to left
        while(!q.empty()){
            level.clear();
            int levelSize=q.size();
            level.resize(levelSize);
            for(int i=0;i<levelSize;i++){
                auto node=q.front();
                q.pop();
                int index=(sign==-1)? i:(levelSize-1-i);
                level[index]=node->val;
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
                
            }
            sign=(sign*(-1));
            ans.push_back(level);
        }
        return ans;
    }
};

//codestudio
#include<bits/stdc++.h>
vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    vector<int> ans;
    if(root==NULL)return ans;
    queue<BinaryTreeNode<int> *>q;
    q.push(root);
    int sign=1;
    while(!q.empty()){
        int sz=q.size();
        vector<int> level(sz);
        for(int i=0;i<sz;i++){
            auto it=q.front();q.pop();
            int idx=(sign==1)?i:sz-1-i;
            level[idx]=it->data;
            if(it->left)q.push(it->left);
            if(it->right)q.push(it->right);
        }
        sign*=-1;
        ans.insert(ans.end(),level.begin(),level.end());
    }
    return ans;
}
