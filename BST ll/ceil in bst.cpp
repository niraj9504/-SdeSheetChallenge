/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/

int findCeil(BinaryTreeNode<int> *node, int x){
    int ceil=-1;
    //we want node->data>=x, int just greater than or equal to x
    while(node){
        if(node->data==x){
            return x;
        }
        else if(node->data>x){
            ceil=node->data;
            node=node->left;
        }
        else{
            node=node->right;
        }
    }
    return ceil;
}
