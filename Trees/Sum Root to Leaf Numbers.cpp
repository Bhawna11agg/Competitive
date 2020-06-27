/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
   int sum(TreeNode* root,int sum1){
        if(root==NULL){
            return 0;
        }
         int p=((sum1*10)+(root->val))%1003;
        if(root->left==NULL && root->right==NULL){
            return (p);
        }
        int x=sum(root->left,p);
        int y=sum(root->right,p);
        int p1=((x+y)%1003);
        return p1;
    }
int Solution::sumNumbers(TreeNode* root) {
      return (sum(root,0));    
}
