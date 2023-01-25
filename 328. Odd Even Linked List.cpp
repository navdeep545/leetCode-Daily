
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head ;
        ListNode *temp1 = head ;
        ListNode *temp3 = head->next ;
        while(temp1 && temp1->next){
            ListNode *temp2 = temp1->next ;
            temp1->next = temp1->next->next ;
            if(temp2->next) temp2->next = temp2->next->next ;
            // temp1 = temp1->next ;
            if(!temp1->next) break ;
            else temp1 = temp1->next ;
        }
        if(temp1) temp1->next = temp3 ;
        return head ;
    }
};