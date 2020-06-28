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
class Solution {
public:
    stack<int>stack;
    vector<int> LargeNode(ListNode* head){
        if(head==NULL){
            vector<int>vect;
            return vect;
        }
       vector<int>vect=LargeNode(head->next);
       if(stack.size()==0){
           vect.push_back(0);
           stack.push(head->val);
           return vect;
       }
       while(stack.size()>0){
           if(stack.top()<=head->val){
               stack.pop();  
           }
           else{
               vect.push_back(stack.top());
               stack.push(head->val);
               break;
           }
       }
       if(stack.size()==0){
           vect.push_back(0);
           stack.push(head->val);
       }
        return vect; 
    }
    vector<int> nextLargerNodes(ListNode* head) {
       vector<int>vec= LargeNode(head);
        reverse(vec.begin(),vec.end());
        return vec;
    }
};
