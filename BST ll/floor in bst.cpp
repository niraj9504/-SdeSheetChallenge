//imp

//** root->val <= key we want lesser or equal value


/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int floorInBST(TreeNode<int> * root, int x)
{    
    int ans=-1;
    while(root){
        if(root->val==x)return x;
        else if(root->val>x){
            root=root->left;
        }
        else{
            ans=root->val;
            root=root->right;
        }
    }
    return ans;
}
