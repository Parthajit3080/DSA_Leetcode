/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {
    int c=0;
    struct ListNode *temp=head;
    while(temp!=NULL){
        c++;
        temp=temp->next;
    }
    c=c/2+1;
    struct ListNode *temp2=head;
    while(c){
        if(c==1)
            return temp2;
        temp2=temp2->next;
        c--;
    }
    return NULL;
}