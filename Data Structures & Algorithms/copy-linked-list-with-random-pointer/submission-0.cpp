class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;

        // Step 1: Insert copied nodes after every original node
        Node* temp = head;

        while(temp != NULL){
            Node* copy = new Node(temp->val);

            copy->next = temp->next;
            temp->next = copy;

            temp = copy->next;
        }

        // Step 2: Set random pointers
        temp = head;

        while(temp != NULL){
            if(temp->random != NULL)
                temp->next->random = temp->random->next;

            temp = temp->next->next;
        }

        // Step 3: Separate original and copied lists
        Node* dum = head->next;
        temp = head;

        while(temp != NULL){
            Node* copy = temp->next;

            temp->next = copy->next;

            if(copy->next != NULL)
                copy->next = copy->next->next;

            temp = temp->next;
        }

        return dum;
    }
};