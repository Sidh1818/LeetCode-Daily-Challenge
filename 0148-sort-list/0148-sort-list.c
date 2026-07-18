/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* getmiddle(struct ListNode* head){
    struct ListNode* slow=head;
    struct ListNode* fast=head->next;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

struct ListNode* merge(struct ListNode*l1,struct ListNode*l2){
    struct ListNode temp;
    struct ListNode* tail=&temp;
    temp.next=NULL;

    while(l1!=NULL && l2!=NULL){
        if(l1->val<l2->val){
            tail->next=l1;
            l1=l1->next;
        }
        else{
            tail->next=l2;
            l2=l2->next;
        }
        tail=tail->next;
    }
    tail->next=(l1!=NULL)?l1:l2;
    return temp.next;
}

struct ListNode* sortList(struct ListNode* head) {
    if(head==NULL || head->next==NULL)
        return head;
    struct ListNode* middle=getmiddle(head);
    struct ListNode* righthalf=middle->next;
    middle->next=NULL;

    struct ListNode* leftsort=sortList(head);
    struct ListNode* rightsort=sortList(righthalf);

    return merge(leftsort,rightsort);
}