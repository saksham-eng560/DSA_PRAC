class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1 = l1;
        ListNode* t2 = l2;

        ListNode* dummy = new ListNode(-1);
        ListNode* rev = dummy;

        int carry = 0;

        while (t1 != NULL && t2 != NULL) {
            int sum = t1->val + t2->val + carry;

            int digit = sum % 10;
            carry = sum / 10;

            ListNode* temp = new ListNode(digit);

            rev->next = temp;
            rev = temp;

            t1 = t1->next;
            t2 = t2->next;
        }

        while (t1 != NULL) {
            int sum = t1->val + carry;

            int digit = sum % 10;
            carry = sum / 10;

            ListNode* temp = new ListNode(digit);

            rev->next = temp;
            rev = temp;

            t1 = t1->next;
        }

        while (t2 != NULL) {
            int sum = t2->val + carry;

            int digit = sum % 10;
            carry = sum / 10;

            ListNode* temp = new ListNode(digit);

            rev->next = temp;
            rev = temp;

            t2 = t2->next;
        }

        if (carry > 0) {
            rev->next = new ListNode(carry);
        }

        return dummy->next;
    }
};