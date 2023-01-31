struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || !head->next) return head;

        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *pre = dummy;

        // Find the node before the start of the reverse range
        for (int i = 1; i < left; i++) {
            pre = pre->next;
        }

        // Reverse the linked list between left and right
        ListNode *start = pre->next;
        ListNode *then = start->next;
        for (int i = 0; i < right - left; i++) {
            start->next = then->next;
            then->next = pre->next;
            pre->next = then;
            then = start->next;
        }

        return dummy->next;
    }
};
