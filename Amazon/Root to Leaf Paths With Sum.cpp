/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int>> sum(TreeNode* root,int B,int sum1){
      vector<vector<int>>v;
    if(root==NULL){
        return v;
    }
    sum1=(sum1+root->val);
    if(root->left==NULL && root->right==NULL){
        if(sum1==B){
            vector<int>vec;
            vec.push_back(root->val);
            v.push_back(vec);
            return v;
        }
        else{
            return v;
        }
    }
    vector<vector<int>>v1=sum(root->left,B,sum1);
   for(int i=0;i<v1.size();i++){
       v1[i].push_back(root->val);
   }
    vector<vector<int>>v2=sum(root->right,B,sum1);
      for(int i=0;i<v2.size();i++){
       v2[i].push_back(root->val);
   }
    for(int i=0;i<v2.size();i++){
        v1.push_back(v2[i]);
    }
    return v1;
}
vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    vector<vector<int>>v=sum(A,B,0);
    for(int i=0;i<v.size();i++){
        reverse(v[i].begin(),v[i].end());
    }
    return v;
}
