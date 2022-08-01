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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        //line,depth,value
        map<int,map<int,multiset<int>>> map;
        vector<vector<int>> ans;
        queue<pair<TreeNode*,pair<int,int>>> q;//node,line,depth
        q.push({root,{0,0}});
        while(!q.empty()){
            auto it=q.front();q.pop();
            auto node=it.first;
            int line=it.second.first;
            int depth=it.second.second;
            //map.insert({line,{depth,node->val}});
            map[line][depth].insert(node->val);//inserting into multiset
            if(node->left)q.push({node->left,{line-1,depth+1}});
            if(node->right)q.push({node->right,{line+1,depth+1}});
        }
        
        for(auto it:map){
            vector<int> temp;
            for(auto x:it.second){
                temp.insert(temp.end(),x.second.begin(),x.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

//m2
/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/
#include<bits/stdc++.h>
vector<int> verticalOrderTraversal(TreeNode<int> *root)
{    if(root==NULL)return {};
    map<int,map<int,vector<int>>> map;
    queue<pair<TreeNode<int>*,pair<int,int>>> q;//node,line,depth
    q.push({root,{0,0}});
    while(!q.empty()){
        auto it=q.front();q.pop();
        auto node=it.first;
        int x=it.second.first;
        int y=it.second.second;
        map[x][y].push_back(node->data);
        if(node->left)q.push({node->left,{x-1,y+1}});
        if(node->right)q.push({node->right,{x+1,y+1}});
    }
    vector<int> temp;
    for(auto it:map){
        for(auto x:it.second){
            for(auto k:x.second){
                temp.push_back(k);
            }
        }
    }
    return temp;
}
