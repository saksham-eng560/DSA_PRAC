class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL) return;

        // 1. Find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. Reverse second half
        ListNode* prev = NULL;
        ListNode* curr = slow;

        while (curr != NULL) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // prev = head of reversed second half

        // 3. Merge two halves
        ListNode* t1 = head;
        ListNode* t2 = prev;

        while (t2->next != NULL) {
            ListNode* next1 = t1->next;
            ListNode* next2 = t2->next;

            t1->next = t2;
            t2->next = next1;

            t1 = next1;
            t2 = next2;
        }
    }
};