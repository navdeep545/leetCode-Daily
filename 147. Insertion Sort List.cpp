struct ListNode {
        int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next) return head ;
        ListNode *temp1 = head ;
        while(temp1 && temp1->next)
        {
            ListNode *temp2 = head ;
            ListNode *temp3 = temp1->next ;
            int curr = temp3->val ;
            while(curr > temp2->val)
                temp2 = temp2->next ;
                if(temp2 != temp3){
                    temp1->next = temp1->next->next ;
                    temp3->next = temp2->next ;
                    temp2->next = temp3 ;
                    temp3->val = temp2->val ;
                    temp2->val = curr ;
                }
            if(temp1->next && temp1->next->val >= temp1->val)
            // {
                temp1 = temp1->next ;
            // }
        }
        return head ;
    }
};