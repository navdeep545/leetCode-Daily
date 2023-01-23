struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}     ListNode(int x, ListNode *next) : val(x), next(next) {} 
};



class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        ListNode *temp = head ;
        while(temp && temp->next){
            if(temp->next->val > temp->val ) {
                head = temp->next ;
                break ;
            }
            temp = temp->next ;
        }
        temp = head ;
        while(temp && temp->next){
            
                if(temp->next->val > temp->val && temp->next->val<head->val) head->next = temp->next ;
                temp = temp->next ;
                if(!temp) break ;
        }
        return head ;
    }
};