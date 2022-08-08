//bfs
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
    //bfs
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)return true;
        queue<TreeNode*> q;
        q.push(root->left);q.push(root->right);
        while(!q.empty()){
            auto lt=q.front();q.pop();
            auto rt=q.front();q.pop();
            if(lt==NULL && rt==NULL)continue;
            if(lt==NULL || rt==NULL || lt->val!=rt->val)return false;
            q.push(lt->left);q.push(rt->right);
            q.push(lt->right);q.push(rt->left);
        }
        return true;
    }
};
