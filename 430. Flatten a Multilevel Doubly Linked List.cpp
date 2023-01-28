class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
class Solution {
public:
    Node* flatten(Node* head) {
        if(head && !head->next && !head->child) return head ;
        Node *temp1 = head ;
        while(temp1){
            if(temp1->child){
                Node *temp2 = temp1->next ;
                temp1->next = temp1->child ;
                temp1->next->prev = temp1 ;
                temp1->child = nullptr ;
                Node *temp3 = temp1->next ;
                while(temp3 && temp3->next)
                temp3 = temp3->next ;
                temp3->next = temp2 ;
                if(temp3->next)temp3->next->prev = temp3 ;
            }
            else             temp1 = temp1->next ;
        }
        return head ;
    }
};