class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prevGroupEnd = &dummy;

        while (true) {
            ListNode* kth = prevGroupEnd;
            for (int i = 0; i < k && kth; i++) {
                kth = kth->next;
            }
            if (!kth) break;
            ListNode* groupStart = prevGroupEnd->next;
            ListNode* nextGroupStart = kth->next;
            kth->next = nullptr;
            ListNode* prev = nullptr;
            ListNode* curr = groupStart;
            while (curr) {
                ListNode* nxt = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nxt;
            }

            prevGroupEnd->next = prev;
            groupStart->next = nextGroupStart;

            prevGroupEnd = groupStart;
        }

        return dummy.next;
    }
};
