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
    priority_queue<pair<int, ListNode*>> pq;
    for(i = 0;i < A.size(); i++)
        pq.push({-(A[i]->val), A[i]});
    ListNode* t = new ListNode(0);
    ListNode* cur = t;
    
    while(!pq.empty()){
        auto a = pq.top();
        pq.pop();
        ListNode* temp = new ListNode(-(a.first));
        cur->next = temp;
        cur = cur->next;
        if(a.second->next)
            pq.push({-(a.second->next->val), a.second->next});
    }
    return t->next;
}
