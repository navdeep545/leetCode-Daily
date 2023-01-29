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
        vector<int> v ;
        for(ListNode *temp1 = head ;temp1;temp1 = temp1->next)
        v.push_back(temp1->val) ;
        sort(v.begin(),v.end()) ;
        ListNode *temp1 = head ;
        for(int i=0;i<v.size();i++){
            temp1->val = v[i] ;
            temp1 = temp1->next ;
        }
        return head ;
    }
};