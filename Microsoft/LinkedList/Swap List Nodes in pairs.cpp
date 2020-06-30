/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 * 
 * typedef struct ListNode listnode;
 * 
 * listnode* listnode_new(int val) {
 *     listnode* node = (listnode *) malloc(sizeof(listnode));
 *     node->val = val;
 *     node->next = NULL;
 *     return node;
 * }
 */
/**
 * @input A : Head pointer of linked list 
 * 
 * @Output head pointer of list.
 */
listnode* swapPairs(listnode* A) {
    listnode*B=A;
    listnode*C=NULL;
    if(A!=NULL)
    C=A->next;
    while(C){
        int t=B->val;
        B->val=C->val;
        C->val=t;
        if(C->next!=NULL){
            B=C->next;
            C=B->next;
        }
        else{
            break;
        }
    }
    return A;
}
