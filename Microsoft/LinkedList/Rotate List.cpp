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
 * @input B : Integer
 * 
 * @Output head pointer of list.
 */
listnode* rotateRight(listnode* A, int H) {
    listnode* B=A;
     listnode* D=A;
    int count=0;
    while(B!=NULL){
        B=B->next;
        count++;
    }
    if(count==1){
        return A;
    }
    int p=count;
    count=H%count;
    p=p-count;
     listnode* C=A;
     B=A;
    while(B->next!=NULL){
       B=B->next ;
    } 
    while(p>1){
       C=C->next ;
       p--;
    }
    D=C->next;
    B->next=A;
    C->next=NULL;
    return D;
}
