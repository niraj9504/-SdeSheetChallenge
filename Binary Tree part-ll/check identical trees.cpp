class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL)return true;
        else if(q==NULL)return false;
        else if(p==NULL)return false;
        if((p->val)!=(q->val))return false;
        return (isSameTree(p->left,q->left) && isSameTree(p->right,q->right));
    }
};
