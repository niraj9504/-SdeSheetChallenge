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
    //post order traversal in (right, left, root)
    //If we traverse the flattened tree in the reverse way, we would notice that [6->5->4->3->2->1] is in (right, left, root) order of the original tree. So the reverse order after flattening is post order traversal in (right, left, root) order like [6->5->4->3->2->1]
    TreeNode* prev;
    void flatten(TreeNode* root) {
        if(root==NULL)return;
        flatten(root->right);
        flatten(root->left);
        root->right=prev;
        root->left=NULL;
        prev=root;
    }
};
//codestudio
TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    if(root==NULL)return root;
    TreeNode<int> *prev=root->right,*temp=root;
    root->right=flattenBinaryTree(root->left);
    while(temp->right!=NULL)temp=temp->right;
    temp->right=flattenBinaryTree(prev);
    root->left=NULL;
    return root;
}
