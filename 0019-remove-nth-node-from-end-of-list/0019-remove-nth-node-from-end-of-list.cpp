class Solution {
public:
    int LengthofLL(ListNode* head) {
        ListNode* temp = head;
        int count = 0;

        while (temp) {
            count++;
            temp = temp->next;
        }

        return count;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int length = LengthofLL(head);

        // If we need to delete the head
        if (n == length) {
            return head->next;
        }

        int toDelete = length - n;

        ListNode* temp = head;
        int count = 1;

        while (count < toDelete) {
            count++;
            temp = temp->next;
        }

        temp->next = temp->next->next;

        return head;
    }
};