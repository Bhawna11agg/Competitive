class Solution {
public:
    int sum(TreeNode* root,int sum1){
        if(root==NULL){
            return 0;
        }
         int p=(sum1*10)+(root->val);
        if(root->left==NULL && root->right==NULL){
            return p;
        }
        int x=sum(root->left,p);
        int y=sum(root->right,p);
        int p1=x+y;
        return p1;
          
    }
    int sumNumbers(TreeNode* root) {
      return (sum(root,0));    
    }
};
