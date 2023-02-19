struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        auto temp = head;
        while (temp) {
            n++;
            temp = temp->next;
        }
        int base = n / k; // the minimum size of each part
        int extra = n % k; // the number of parts that have one extra node
        vector<ListNode*> v(k);
        temp = head;
        for (int i = 0; i < k && temp; i++) {
            v[i] = temp; // store the head of each part
            int size = base + (i < extra); // the size of this part
            for (int j = 1; j < size; j++) {
                temp = temp->next; // move to the end of this part
            }
            auto next = temp->next; // save the next node
            temp->next = nullptr; // cut off this part
            temp = next; // move to the next node
        }
        return v;
    }
};