/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    if(!A)
        return B;
    if(!B)
        return A;
    ListNode* l1 = A, *l2 = B, *head = new ListNode(0);
    ListNode* cur = head;
    while(l1 && l2){
        if(l1->val < l2->val){
            cur->next = l1;
            l1 = l1->next;
            cur = cur->next;
        }
        else{
            cur->next = l2;
            l2 = l2->next;
            cur = cur->next;
        }
    }
    if(l1)
        cur->next = l1;
    if(l2)
        cur->next = l2;

    return head->next;
}
