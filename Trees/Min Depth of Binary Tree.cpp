int Solution::minDepth(TreeNode* A) {
    if(A==NULL){
        return 0;
    }
    int x=-1,y=-1;
   x=minDepth(A->left);
   y=minDepth(A->right);
   if(x==0 && y!=0){
       return y+1;
   }
    if(x!=0 && y==0){
       return x+1;
   }
   return min(x,y)+1;
}
