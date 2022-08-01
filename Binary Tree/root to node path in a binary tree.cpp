/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
			left = NULL;
			right = NULL;
		}

		~TreeNode()
		{
			if (left != NULL)
			{
		  		delete left;
			}
			if (right != NULL)
			{
			 	delete right;
			}
		}
	};
*/

;
void dfs(TreeNode<int> *root,int x,vector<int> &ans){
    if(root==NULL)return;
    ans.push_back(root->data);
    dfs(root->left,x,ans);
    if(ans[ans.size()-1]==x)return;
    dfs(root->right,x,ans);
    if(ans[ans.size()-1]==x)return;
    ans.pop_back();
}
vector<int> pathInATree(TreeNode<int> *root, int x)
{    
    vector<int> ans;
    dfs(root,x,ans);
    return ans;
}
