/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::flatten(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A==NULL){
        return NULL;
    }
    TreeNode* root=new TreeNode(A->val);
    TreeNode*root1=root;
     root->right=flatten(A->left);
     while(root1->right!=NULL){
         root1=root1->right;
     }
    root1->right=flatten(A->right);
    delete A;
    return root;
}
