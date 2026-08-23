class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* temp = head;

        ListNode* dum = new ListNode(-1);
        ListNode* rev = dum;

        int cnt = 1;

        // Move rev and temp until temp reaches left
        while (cnt < left) {
            rev->next = temp;
            temp = temp->next;
            rev = rev->next;
            cnt++;
        }

        // temp == left
        ListNode* prev = nullptr;

        while (temp != NULL && cnt <= right) {
            ListNode* succ = temp->next;  // save next node

            temp->next = prev;
            prev = temp;
            temp = succ;

            cnt++;
        }

        // Connect node before left to reversed section
        rev->next = prev;

        // Move rev to the end of reversed section
        while (rev->next != NULL)
            rev = rev->next;

        // Attach remaining nodes
        while (temp != NULL) {
            rev->next = temp;
            temp = temp->next;
            rev = rev->next;
        }

        return dum->next;
    }
};