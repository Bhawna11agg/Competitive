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
    int getPosition(ListNode* head,long int count){
        if(head==NULL){
            return 0;
        }
        int p=getPosition(head->next,count-1);
        if(head->val==1){
            p+=pow(2,count);
        }
        return p;
    }
    int getDecimalValue(ListNode* head) {
       long int count=0;
        ListNode* head1=head;
        while(head1!=NULL){
            head1=head1->next;
            count++;
        }
        return getPosition(head,count-1);  
    }
};
