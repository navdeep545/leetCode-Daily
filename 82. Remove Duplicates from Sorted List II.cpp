

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head ;
        ListNode *num = new ListNode(head->val - 1) ;
        num->next = head ;
        auto main = num ;
        auto mover = num->next ;
        while(main && mover){
            if(mover->next && mover->val == mover->next->val){
                while(mover && mover->next && mover->val == mover->next->val){
                    mover=mover->next ;
                }
                main->next = mover->next ;
                mover = mover->next ;
            }
            else {
                main=main->next ;
                mover=mover->next ;
            }
        }
        return num->next ;
    }
};