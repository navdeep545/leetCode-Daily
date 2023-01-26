struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1) return l2 ;
        if(!l2) return l1 ;
        ListNode *temp1 = l1 ;
        ListNode *temp2 = l2 ;
        int i=0;
        int j=0;
        while(temp1 || temp2){
            if(temp1){
                temp1=temp1->next ;
                i++ ;
            }
            if(temp2){
                temp2=temp2->next ;
                j++ ;
            }
        }
        if(i>j){
            temp1 = l1 ;
            temp2 = l2 ;
            while(temp1){
                if(temp2){
                    temp1->val = temp1->val + temp2->val ;
                    temp2 = temp2->next ;
                }
                if(temp1->val > 9 && temp1->next){
                    temp1->next->val++ ;
                    temp1->val = temp1->val % 10 ;
                }
                if(!temp1->next) break ;
                else temp1 = temp1->next ;
            }
            if(temp1 && temp1->val > 9) {
                temp1->next = new ListNode(1) ;
                temp1->val = temp1->val%10 ;
            }
            return  l1 ;
        }
        temp1 = l1 ;
        temp2 = l2 ;
        while(temp2){
                if(temp1){
                    temp2->val = temp2->val + temp1->val ;
                    temp1 = temp1->next ;
                }
                if(temp2->val > 9 && temp2->next){
                    temp2->next->val++ ;
                    temp2->val = temp2->val % 10 ;
                }
                if(!temp2->next) break ;
                else temp2 = temp2->next ;
            }
            if(temp2 && temp2->val > 9) {
                temp2->next = new ListNode(1) ;
                temp2->val = temp2->val%10 ;
            }
            return  l2 ;
    }
};