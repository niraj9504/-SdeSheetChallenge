//m1 try (root->left lie b/w -inf to root->val-1 && root->right b/w root->val+1 to inf)
//m2
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
    TreeNode* prev=NULL;
    bool isValidBST(TreeNode* root) {
        if(root==NULL)return true;
        if(isValidBST(root->right)==false)return false;
        if(prev && prev->val<=root->val)return false;
        prev=root;
        if(isValidBST(root->left)==false)return false;
        return true;
    }
};
//m2
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
    bool solve(TreeNode* root,long long l,long long r){
        if(root==NULL)return true;
        if(root->val<=l || root->val>=r)return false;
        return solve(root->left,l,root->val) & solve(root->right,root->val,r);
    }
    bool isValidBST(TreeNode* root) {
        return solve(root,-LONG_MAX,LONG_MAX);
    }
};
