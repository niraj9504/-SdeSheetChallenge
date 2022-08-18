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
    int ans;
    void inorder(TreeNode* root, int &k){
        //k is passed by reference
        if(root==NULL)return;
        inorder(root->left,k);
        k--;
        if(k==0){
            ans=root->val;
        }
        inorder(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        inorder(root,k);
        return ans;
    }
};


//kth largest
    int ans;
    void revinorder(Node *root, int &k){
        if(root==NULL)return;
        revinorder(root->right,k);
        --k;
        if(k==0)ans=root->data;
        revinorder(root->left,k);
    }
    int kthLargest(Node *root, int k)
    {
        revinorder(root,k);
        return ans;
    }
