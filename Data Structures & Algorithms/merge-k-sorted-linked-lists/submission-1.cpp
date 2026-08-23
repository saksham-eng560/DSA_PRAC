class Solution {
public:

    ListNode* mergeTwo(ListNode* t1, ListNode* t2) {

        if(t1 == NULL) return t2;
        if(t2 == NULL) return t1;

        ListNode* dum = new ListNode(-1);
        ListNode* rev = dum;

        while(t1 != NULL && t2 != NULL) {

            if(t1->val < t2->val) {
                rev->next = t1;
                t1 = t1->next;
            }
            else {
                rev->next = t2;
                t2 = t2->next;
            }

            rev = rev->next;
        }

        if(t1 != NULL)
            rev->next = t1;

        if(t2 != NULL)
            rev->next = t2;

        return dum->next;
    }


    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if(lists.empty())
            return NULL;

        int n = lists.size();

        while(n > 1) {

            int j = 0;

            for(int i = 0; i < n / 2; i++) {

                lists[j] = mergeTwo(
                    lists[2 * i],
                    lists[2 * i + 1]
                );

                j++;
            }

            if(n % 2 == 1) {
                lists[j] = lists[n - 1];
                j++;
            }

            n = j;
        }

        return lists[0];
    }
};