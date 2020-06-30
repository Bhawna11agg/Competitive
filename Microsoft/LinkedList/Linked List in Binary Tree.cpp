/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool check(TreeNode* root,ListNode* head){
        if(head->next==NULL || head==NULL){
            return true;
        }
        if(root->left && root->left->val==head->next->val){
           if(check(root->left,head->next)){
               return true;
           }
        }
        if(root->right && root->right->val==head->next->val){
           return check(root->right,head->next);
        }
        return false;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(root==NULL){
            return false;
        }
           if(root->val==head->val){
              if(check(root,head)){
                  return true;
              }
           }
        if(isSubPath(head,root->left)){
            return 1;
        }
        if(isSubPath(head,root->right)){
            return 1;
        }
        return 0;
    }
};
