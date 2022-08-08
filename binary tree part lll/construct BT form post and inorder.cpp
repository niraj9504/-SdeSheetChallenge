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
    TreeNode* solve(vector<int> &in,vector<int> &post,int left,int right,int &i){
        if(left>right)return NULL;
        int piv=0;
        while(in[piv]!=post[i])piv++;
        i--;
        
        TreeNode* node=new TreeNode(in[piv]);
        node->right=solve(in,post,piv+1,right,i);//first right then left subtree
        node->left=solve(in,post,left,piv-1,i);
        return node;
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        int n=in.size();
        int i=n-1;
        return solve(in,post,0,n-1,i);
    }
};
// class Solution {
// public:
//     TreeNode* buildTree(vector<int>& in, vector<int>& post) {
//         int n = size(in), i = n-1;
//         return solve(in, post, 0, n-1, i);
//     }

//     TreeNode* solve(vector<int>& in, vector<int>& post, int left, int right, int& i) {
//         if(left > right) return nullptr;
//         TreeNode* root = new TreeNode(post[i--]);
//         int piv = find(begin(in), end(in), root -> val) - begin(in);
//         root -> right = solve(in, post, piv+1, right, i);
//         root -> left  = solve(in, post, left, piv-1, i);
//         return root;
//     }
// };
