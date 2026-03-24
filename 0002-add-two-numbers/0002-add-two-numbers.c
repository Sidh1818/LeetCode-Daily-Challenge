/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 
 struct Listnode *createnode(int val){
    struct Listnode *temp=(struct Listnode*)malloc(sizeof(struct Listnode));
    temp->val=val;
    temp->next = NULL;
    return temp;
 }

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct Listnode *p1=(struct Listnode*)malloc(sizeof(struct Listnode));
    p1->val=0;
    p1->next=NULL;
    struct Listnode *current=p1;
    int carry=0;
    while(l1!=NULL||l2!=NULL||carry!=0){
        int sum=carry;
        if(l1!=NULL){
            sum+=l1->val;
            l1=l1->next;
        }
        if(l2!=NULL){
            sum+=l2->val;
            l2=l2->next;
        }
        carry=sum/10;
        current->next=(struct Listnode*)malloc(sizeof(struct Listnode));
        current=current->next;
        current->val=sum%10;
        current->next=NULL;
    }
    struct Listnode *result=p1->next;
    free(current);
    return result;

    
}
*/
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* dummyHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummyHead->val = 0;
    dummyHead->next = NULL;
    struct ListNode* current = dummyHead;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0) {
        int sum = carry;
        
        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }
        
        carry = sum / 10;
        current->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        current = current->next;
        current->val = sum % 10;
        current->next = NULL;
    }

    struct ListNode* result = dummyHead->next;
    free(dummyHead);
    return result;
}
