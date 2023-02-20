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

// done without help, performance wasn't up to the mark but still

// two pointer approach, fast and low memory
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                slow = head;
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};