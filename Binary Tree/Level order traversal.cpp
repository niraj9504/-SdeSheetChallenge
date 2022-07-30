//m1
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)return ans;
        queue<TreeNode*> q;
        q.push(root);
        vector<int> level;
        while(!q.empty()){
            level.clear();
            int levelSize=q.size();
            for(int i=0;i<levelSize;i++){
                auto node=q.front();q.pop();
                level.push_back(node->val);
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            ans.push_back(level);
        }
        return ans;
    }
};

//m2
class Solution {
public:
    vector<vector<int>> ans;
    int height(TreeNode* root){
        if(root==NULL){
            return -1;
        }
        else{
            return max(height(root->left)+1,height(root->right)+1);
        }
    }
    void levelp(TreeNode* root,int level,int l){
        if(root==NULL){
            return;
        }
        if(level==0){
            ans[l].push_back(root->val);
        }
        else if(level>0){
            levelp(root->left,level-1,l);
            levelp(root->right,level-1,l);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        int h=height(root);
        ans.resize(h+1);
        for(int i=0;i<=h;i++){
            levelp(root,i,i);
        }
        return ans;
    }
};
//m3

class Solution {
public:
    void levelOrderHelper(vector<vector<int>> &res, TreeNode* root, int depth)
    {
        if(root==NULL)
            return;
        if(depth>=res.size())
            res.push_back({});
        res[depth].push_back(root->val);
        levelOrderHelper(res, root->left, depth+1);
        levelOrderHelper(res, root->right, depth+1);
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL)
            return {};
        vector<vector<int>> res;
        levelOrderHelper(res, root, 0);
        return res;
    }
};
