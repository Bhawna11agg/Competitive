/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 int pp=0;
 int lca1(TreeNode* root, int p, int q){
      if(root==NULL){
            return -1;
        }
        if(root->val==p || root->val==q){
             pp=pp+1;
            return root->val;
        }
        int root2=lca1(root->left,p,q);
        int root1=lca1(root->right,p,q);
        if(root2!=-1 && root1!=-1){
            return root->val;
        }
        if(root2!=-1){
            return root2;
        }
        if(root1!=-1){
            return root1;
        }
       return -1; 
 }
int Solution::lca(TreeNode* root, int p, int q) {
  
    int x=lca1(root,p,q);
    if(pp==2 || p==q){
        return x;
    }
    else{
        return -1;
    }
}
