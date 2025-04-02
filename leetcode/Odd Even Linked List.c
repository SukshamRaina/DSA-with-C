/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 int totalnode(struct ListNode* head){
    int count=0;
    struct ListNode* temp= head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;}
struct ListNode* oddEvenList(struct ListNode* head) {
    if(head==NULL || head->next == NULL)
        return head;
    else{
        struct ListNode* prev =  head;
        struct ListNode* current=  head->next;
        struct ListNode* head1=current;
        while(current!=NULL  && current->next!=NULL){
            prev->next=current->next;
            prev=prev->next;

            current->next=prev->next;
            current=current->next;
        }
        prev->next = head1;
        return head;
    }
}
