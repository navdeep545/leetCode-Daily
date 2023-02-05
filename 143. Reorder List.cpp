struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return ;
        auto slow = head ;
        auto fast = head ;
        while(slow && fast && fast->next){
            slow = slow->next ;
            fast = fast->next->next ;
        }
        fast = slow->next ;
        slow->next = nullptr ;
        slow = fast ;
        fast = fast->next ;
        slow->next = nullptr ;
        while(slow && fast){
            auto temp = fast->next ;
            fast->next = slow ;
            slow = fast ;
            fast = temp ;
        }
        fast = head ;
        while(slow && fast){
            auto temp = fast->next ;
            fast->next = slow ;
            auto temp1 = slow->next ;
            slow->next = temp ;
            slow = temp1 ;
            fast = temp ;
        }
        return  ;
    }
};