//m1 dfs
long getMaxProfit(vector<int> pnl,int k){
     long long sum=0,best;
     for(int i=0;i<k;i++){
          sum+=pnl[i];
     }
     best=sum;
     int l=0;
     for(int i=k;i<pnl.size();i++){
          sum-=pnl[l++];
          sum+=pnl[i];
          best=max(sum,best);
     }
     return best;
}
//m2
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL)return 0;
        queue<TreeNode*> q;
        q.push(root);
        int depth=0;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto it=q.front();q.pop();
                if(it->left)q.push(it->left);
                if(it->right)q.push(it->right);
            }
            depth++;
        }
        return depth;
    }
};
//m3
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        return max(maxDepth(root->left),maxDepth(root->right))+1;
    }
};

//codestudio 
//m1 TLE
#include<bits/stdc++.h>
int searchidx(vector<int> &in,int start,int end,int val){
    for(int i=start;i<=end;i++){
        if(in[i]==val)return i;
    }
    return -1;
}
int height(vector<int> &in,vector<int> &lev,int start,int end,int ht,int n){
    if(start>end)return 0;
    int idx=searchidx(in,start,end,lev[0]);
    if(idx==-1)return 0;
    int n1=idx-start;//left subtree
    int n2=end-idx;//right subtree
    vector<int> left(n1),right(n2);//new level orders for left and right
    int lht=0,rht=0,k=0;
    for(int i=0;i<n;i++){
        for(int j=start;j<idx;j++){
            if(lev[i]==in[j]){
                left[k++]=lev[i];
                break;
            }
        }
    }
    k=0;
    for(int i=0;i<n;i++){
        for(int j=idx+1;j<=end;j++){
            if(lev[i]==in[j]){
                right[k++]=lev[i];
                break;
            }
        }
    }
    if(n1>0)lht=height(in,left,start,idx-1,ht,n1);
    if(n2>0)rht=height(in,right,idx+1,end,ht,n2);
    ht=max(lht+1,rht+1);
    return ht;
}
int heightOfTheTree(vector<int>& in, vector<int>& lev, int n){
	//see gfg
    return height(in,lev,0,n-1,0,n)-1;
}

//m2
#include <bits/stdc++.h> 
int heightOfTheTree(vector<int>& inorder, vector<int>& levelOrder, int N){
    unordered_map<int, int> mp; // Inorder Node value -> index in inorder array
    queue<vector<int>> q; // {start, end, height}
    
    for(int i = 0; i < inorder.size(); i++){
        mp[inorder[i]] = i;
    }
    
    if(mp.find(levelOrder[0]) != mp.end()){
        // root is the last element in inorder traversal then it has no right subtree
        if(mp[levelOrder[0]] == inorder.size()-1) 
            q.push({0, (int)inorder.size()-2, 1});
        // root is the first element in inorder traversal then it has no left subtree
        else if(mp[levelOrder[0]] == 0)
            q.push({1, (int)inorder.size()-1, 1});
        else
        {
            q.push({0, mp[levelOrder[0]]-1, 1});    // left subtree
            q.push({mp[levelOrder[0]]+1, (int)inorder.size()-1, 1});    // right subtree
        }
    }
    int k = 1;
    int ans = 0;
   while(!q.empty())
   {  
    auto temp = q.front();
    q.pop();
    ans = max(ans, temp[2]);
    if(mp.find(levelOrder[k]) != mp.end()){  
        // if it is the leaf node i.e. no left subtree and no right subtree 
        if(temp[0] == temp[1]) 
            ans = max(ans, temp[2] + 1);
        // root is the last element in inorder traversal then it has no right subtree
        else if(mp[levelOrder[k]] == temp[1])
            q.push({temp[0], temp[1]-1, temp[2]+1});
        // root is the first element in inorder traversal then it has no left subtree
        else if(mp[levelOrder[k]] == temp[0])
            q.push({temp[0]+1, temp[1], temp[2]+1});
        else
        {
            q.push({temp[0], mp[levelOrder[k]]-1, temp[2]+1}); // left subtree
            q.push({mp[levelOrder[k]]+1, temp[1], temp[2]+1});    // right subtree
        }
    }
    k++;
   }
   return ans-1;
}
