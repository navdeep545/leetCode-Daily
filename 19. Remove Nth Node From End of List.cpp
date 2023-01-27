 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head->next) return nullptr ;
        if(n==1){ListNode *temp = head ;
        int i=1;
        while(temp && temp->next){
            if(!temp->next->next){
                i++ ;
                break ;
            }
            temp = temp->next ;
            i++ ;
        }
        if(n==1){
            temp->next = nullptr ;
        }
        
        return head;}
        ListNode *temp1 = head ;
        while(temp1){
            ListNode *temp2 = temp1 ;
            for(int i=1;temp2,i<n;i++){
                temp2=temp2->next ;
            }
            if(temp1->next && !temp2->next){
                temp1->val = temp1->next->val ;
                temp1->next = temp1->next->next ;
                break ;
            }
            temp1 = temp1->next ;
        }
        return head ;
    }
};