struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* dummyhead = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummyhead->next=head;
    struct ListNode* fast=dummyhead;
    struct ListNode* slow=dummyhead;
    for(int i=0 ;i<n;i++){
        fast=fast->next;
    }
    while(fast->next){
        fast=fast->next;
        slow=slow->next;
    }
    struct ListNode* temp=slow->next;
    slow->next=slow->next->next;
    free(temp);
    return dummyhead->next;
}