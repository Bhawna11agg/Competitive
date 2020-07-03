/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* A) {
    ListNode* B=A;
    int count=0,zer=0;
    while(B!=NULL){
        count++;
        if(B->val==0){
            zer++;
        }
        B=B->next;
    }
    B=A;
    while(B!=NULL){
        if(zer>0){
            B->val=0;
            B=B->next;
            zer--;
            continue;
        }
        B->val=1;
         B=B->next; 
    }
    return A;
}
