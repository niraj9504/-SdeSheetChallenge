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
