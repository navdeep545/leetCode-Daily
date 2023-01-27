struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next) return nullptr ;
        ListNode *slow = head ;
        ListNode *fast = head ;
        while(slow && fast && fast->next){
            if(!fast->next->next && slow->next){
                slow->next = slow->next->next ;
                return head ;
            }
                slow = slow->next ;
                fast = fast->next->next ;
        }
        if(slow && slow->next){
            slow->val = slow->next->val ;
            slow->next=slow->next->next ;
        }
        return head ;
    }
};