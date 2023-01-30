struct ListNode {
    ListNode *next;
    int val;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head ;
        ListNode *temp1 = head ;
        ListNode *temp2 = head->next ;
        temp1->next = nullptr ;
        while(temp1 && temp2)
        {
            ListNode *temp3 = temp2->next ;
            temp2->next = temp1 ;
            temp1 = temp2 ;
            temp2 = temp3 ;
        }
        return temp1 ;
    }
};