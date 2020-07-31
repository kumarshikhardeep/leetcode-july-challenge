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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head)
            return head;
        ListNode* l = head;
        while(l->next){
            ListNode* t = l;
            if(t->next->val == val){
                t = t->next;
                while(t && t->val == val){
                    t = t->next;
                }
                l->next = t;
                continue;
            }
            l = l->next;
        }
        if(head->val == val)
            return head->next;
        return head;
    }
};
