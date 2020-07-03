/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::solve(ListNode* A, int B1) {
    ListNode* B=A;
    int count=0;
    while(B!=NULL){
        count++;
        B=B->next;
    }
    count=(count/2)+1;
    count=count-B1;
    if(count<=0){
        return -1;
    }
    int p=1;
    while(p<count){
        A=A->next;
        p++;
    }
    return A->val;
}
