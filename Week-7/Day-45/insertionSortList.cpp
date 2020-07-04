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
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* ans = head, *rem = head->next;
        ans->next = NULL;
        while(rem)
        {
            if(ans->val > rem->val){                        
                ListNode* prev = NULL;
                ListNode* t;
                if(head->val > rem->val){                   //If current element is less than the first element,i.e, the smallest
                    t = rem->next;
                    rem->next = head;
                    head = rem;
                    rem = t;
                }
                else{                                      //if the current element needs to be inserted somewhere in the middle
                    t = head->next;
                    prev = head;
                    while(t && t->val < rem->val){
                        prev = t;
                        t = t->next;
                    }
                    prev->next = rem;
                    rem = rem->next;
                    prev = prev->next;
                    prev->next = t;
                }
            }
            else{                               //if current element os bigger than the last element of the currently sorted part
                ans->next = rem;
                rem = rem->next;
                ans = ans->next;
                ans->next = NULL;
            }
        }
        return head;
    }
};