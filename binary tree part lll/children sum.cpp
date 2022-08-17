//important
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
m2.o(n^2) 
Depth - First Search
This problem can be solved using a simple depth-first search, where the parent node is updated after its children.
Let ‘parentVal’ be the value at the parent’s node and ‘childVal’ be the sum of the values of children nodes. Now there arise three cases :
If ‘parentVal’ = ‘childVal’, then we have to do nothing.
If ‘parentVal’ < ‘childVal’, then we can simply increase ‘parentVal’ by diff = ‘childVal’ - ‘parentVal’.
If ‘parentVal’ > ‘childVal’, then we can’t decrease the value in a node, so this case is a bit tricky. To handle this case, we need to increase ‘childVal’ i.e increase the sum of children nodes and for that increase the values in the child nodes.
To handle the last case, what we can do is traverse recursively either the left child or the right child,  as when incrementing a child’s value, it will violate its children sum property so we have to recursively update the values in the subtree also. If one child is ‘NULL’, then we can recursively update the second child.

    
m1.O(n) The approach is simple, we will find the difference between the root node and the child nodes. If the difference is positive then we will add the difference to one of the child node and call this recursive function for both left and right child nodes and finally update the value of the root node equal to the sum of the left and right child node.
The steps are as follows:
.Take a variable diff to store the difference between the root and the sum of child nodes.
.If diff is positive then add the difference to any one of the child nodes.
.Call this function again for the left and right nodes to check whether the updated child nodes are following this property or not.
.Now update the current node as the sum of left and right child data.

*************************************************************/
void changeTree(BinaryTreeNode < int > * root) {//postorder
    if(root==NULL || (root->left==NULL && root->right==NULL)){
        return;
    }
    int diff=root->data - ((root->left)?root->left->data:0) + ((root->right)?root->right->data:0);
    if(diff>0){
        if(root->left){
            root->left->data+=diff;
        }
        else{
            root->right->data+=diff;
        }
    }
    changeTree(root->left);
    changeTree(root->right);
    root->data=((root->left)?root->left->data:0) + ((root->right)?root->right->data:0);
} 
