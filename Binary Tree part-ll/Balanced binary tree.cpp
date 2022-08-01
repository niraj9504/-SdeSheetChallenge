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
    int height(TreeNode* root){
        if(root==NULL)return 0;
        int lh=height(root->left);
        int rh=height(root->right);
        return max(lh,rh)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL)return true;
        int lh=height(root->left);
        int rh=height(root->right);
        if(abs(lh-rh)>1)return false;
        return isBalanced(root->left) && isBalanced(root->right) ;
    }
};

//m2
class Solution {
public:
    int dfsheight(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int leftH=dfsheight(root->left);
        if(leftH==-1)return -1;
        int rightH=dfsheight(root->right);
        if(rightH==-1)return -1;
        if(abs(leftH-rightH)>1)return -1;
        return max(leftH,rightH)+1;
    }
    bool isBalanced(TreeNode* root) {
        return dfsheight(root)!=-1;
    }
};
