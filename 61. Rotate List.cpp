struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head ;
        auto end = head ;
        auto join = head ;
        int n=1 ;
        while(end && end->next){
            end = end->next ;
            n++ ;
        }
        // if(n == k) return head ;
        if(k >= n) k = k % n ;
        if(k == 0) return head ;
        end = head ;
        while(end && join){
            if(k > 0 && join->next){
                join = join->next ;
                k-- ;
            }
            else if(join->next){
                end = end->next ;
                join = join->next ;
            }
            else if(!join->next){
                join->next = head ;
                head = end->next ;
                end->next = nullptr ;
                break ;
            }
        }
        return head ;
    }
};