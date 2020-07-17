/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    if(!A.size())
        return NULL;
    if(A.size() == 1)
        return A[0];
    int i, j;
    priority_queue<int> pq;
    for(i = 0;i < A.size(); i++){
        ListNode* t = A[i];
        while(t){
            pq.push(-(t->val));
            t = t->next;
        }
    }
    ListNode* head = A[0];
    for(i = 0;i < A.size(); i++){
        ListNode* t = A[i];
        while(t->next)
            t = t->next;
        if(i != A.size() - 1)
            t->next = A[i + 1];
    }
    ListNode* temp = head;
    while(temp){
        int a = -(pq.top());
        pq.pop();
        temp->val = a;
        temp = temp->next;
    }
    return head;
}
