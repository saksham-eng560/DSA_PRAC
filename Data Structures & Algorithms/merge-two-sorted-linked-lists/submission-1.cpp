class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode* dummy = new ListNode(-1);
        ListNode* t1 = list1;
        ListNode* t2 = list2;
        ListNode* rev = dummy;

        if(t1 == NULL) return t2;
        if(t2 == NULL) return t1;

        while(t1 != NULL && t2 != NULL) {
            if(t1->val < t2->val) {
                rev->next = t1;
                t1 = t1->next;
                rev = rev->next;
            }
            else {
                rev->next = t2;
                t2 = t2->next;
                rev = rev->next;
            }
        }

        while(t1 != NULL) {
            rev->next = t1;
            t1 = t1->next;
            rev = rev->next;       // missing
        }

        while(t2 != NULL) {
            rev->next = t2;
            t2 = t2->next;
            rev = rev->next;       // missing
        }

        return dummy->next;
    }
};