class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return NULL;
        }
        if(root==p || root==q){
            return root;
        }
        TreeNode* root2=lowestCommonAncestor(root->left,p,q);
        TreeNode* root1=lowestCommonAncestor(root->right,p,q);
        if(root2!=NULL && root1!=NULL){
            return root;
        }
        if(root2!=NULL){
            return root2;
        }
          if(root1!=NULL){
            return root1;
        }
        return NULL;
    }
};
