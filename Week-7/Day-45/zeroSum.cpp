/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        if(!head || (head->next == NULL && head->val == 0))
            return NULL;
        ListNode* t = head;
        vector<int> v;
        while(t){
            v.push_back(t->val);
            t = t->next;
        }
        int i, j, k, sum;
        for(i = 0;i < v.size(); i++){
            sum = 0;
            for(j = i; j < v.size(); j++)
            {
                sum += v[j];
                if(sum == 0)
                    break;
            }
            if(sum == 0){
                v.erase(v.begin() + i, v.begin() + j + 1);
                i--;
            }
        }
        if(!v.size())
            return NULL;
        ListNode* cur = head;
        for(i = 0;i < v.size(); i++){
            cur->val = v[i];
            if(i != v.size() - 1)
                cur = cur->next;
            else
                cur->next = NULL;
        }
        return head;
    }
};