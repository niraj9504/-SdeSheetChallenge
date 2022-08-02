/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
bool isLeaf(TreeNode<int>* root){
    return !root->left && !root->right;
}
void leftV(TreeNode<int>* root,vector<int> &ans){
    TreeNode<int> *curr=root->left;
    while(curr){
        if(!isLeaf(curr))ans.push_back(curr->data);
        if(curr->left)curr=curr->left;
        else curr=curr->right;
    }
}
//inorder
void leaf(TreeNode<int> * root,vector<int> &ans){
    if(isLeaf(root)){
        ans.push_back(root->data);
    }
    if(root->left)leaf(root->left,ans);
    if(root->right)leaf(root->right,ans);
}
void rightV(TreeNode<int> *root,vector<int> &ans){
    vector<int> temp;
    TreeNode<int> *curr=root->right;
    while(curr){
        if(!isLeaf(curr))temp.push_back(curr->data);
        if(curr->right)curr=curr->right;
        else curr=curr->left;
    }
    for(int i=temp.size()-1;i>=0;i--){
        ans.push_back(temp[i]);
    }
}
vector<int> traverseBoundary(TreeNode<int>* root){
    if(root==NULL)return {};
    vector<int> ans;
    if(!isLeaf(root))ans.push_back(root->data);
    leftV(root,ans);
    leaf(root,ans);//add leaves
    rightV(root,ans);
    return ans;
}
