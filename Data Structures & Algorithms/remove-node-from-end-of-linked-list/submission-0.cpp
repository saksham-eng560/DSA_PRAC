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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(n==0){
            return head;
        }
        int cnt=0;
        ListNode* temp = head;
        while(temp != NULL){
            cnt++;
            temp=temp->next;
        }
        if(cnt == n){
            ListNode* del = head;
            head = head->next;
            delete del;
            return head;
        }
        int act = cnt-n;
        temp = head;
        while(act != 1){
            act--;
            temp = temp->next;
        }
        ListNode* prev = temp->next;
        temp->next = temp->next->next;;
        delete prev;

        return head;
    }
};