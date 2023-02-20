#include<iostream>
#include <map>
#include <utility>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*,ListNode*> mpp ;
        for(auto temp = head ;temp;temp = temp->next){
            if(mpp.find(temp) != mpp.end()) return temp ;
            else mpp[temp] = temp ;
        }
        return NULL ;
    }
};