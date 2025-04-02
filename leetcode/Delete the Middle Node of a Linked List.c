/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 int middlenode(struct ListNode* head){
    int count=0;
    struct ListNode* temp= head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    int mid = count/2;
    return mid;
 }
struct ListNode* deleteMiddle(struct ListNode* head) {
    if(head==NULL)
    return 0;
    else{
        int mid=middlenode(head);
        struct ListNode* temp=head;
        if(mid==0)
            return NULL;
       else {
                struct ListNode* temp = head;
                int i=0;
                while(i<mid-1){
                    i++;
                    temp = temp->next;
                }
                struct ListNode* nodeToDelete = temp->next;
                temp->next = temp->next->next;
                free(nodeToDelete);
                return head;
                }
                
                
            }

    }
