/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>v;
         vector<int>vec;
        if(root==NULL){
            return v;
        }
        queue<TreeNode*>q;
        q.push(root);
        TreeNode* node1=new TreeNode(-1);
        q.push(node1);
        
        while(q.size()>0){
            TreeNode* x=q.front();
            q.pop();
            if(x!=node1)
            vec.push_back(x->val);
            if(x->left){
                q.push(x->left);  
            }
            if(x->right){
                q.push(x->right);  
            }
            if(x==node1){
               if(q.size()>0){
                   q.push(node1);
               }
                v.push_back(vec);
                vec.clear();
            }
        }
        reverse(v.begin(),v.end());
        return v;
    }
};
