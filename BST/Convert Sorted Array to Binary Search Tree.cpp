//easy concept
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
    TreeNode* solve(vector<int>& nums,int l,int r,TreeNode* ans){
        if(l>r)return NULL;
        int mid=(l+r)/2;
        ans=new TreeNode(nums[mid]);
        ans->left=solve(nums,l,mid-1,ans);
        ans->right=solve(nums,mid+1,r,ans);
        return ans;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        TreeNode* ans;
        solve(nums,0,n-1,ans);
        return ans;
    }
};
