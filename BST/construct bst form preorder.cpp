//O(n2) think
//here O(n)
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
    TreeNode* solve(vector<int> &pr,int l,int r){
        if(l>r)return NULL;
        TreeNode* node=new TreeNode(pr[l]);
        int i=l+1;
        while(i<=r && pr[i]<pr[l])i++;
        node->left=solve(pr,l+1,i-1);
        node->right=solve(pr,i,r);
        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& pr) {
        int n=pr.size()-1;
        return solve(pr,0,n);
    }
};
