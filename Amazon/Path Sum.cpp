/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 bool sum(TreeNode* root,int B,int sum1){
    if(root==NULL){
        return false;
    }
    sum1=(sum1+root->val);
    if(root->left==NULL && root->right==NULL){
        if(sum1==B){
            return true;
        }
        else{
            return false;
        }
    }
   bool v1=sum(root->left,B,sum1);
   bool v2=sum(root->right,B,sum1);
    if(v1 || v2){
        return true;
    } 
    return false;
}
int Solution::hasPathSum(TreeNode* A, int B) {
     return sum(A,B,0);
}
