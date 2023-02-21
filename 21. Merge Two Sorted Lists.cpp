#include <utility>
#include <vector>
#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2 ;
        if(!list2) return list1 ;
        vector<int> v ;
        for(auto temp = list1;temp;temp=temp->next){
            v.push_back(temp->val) ;
        }
        for(auto temp = list2;temp;temp=temp->next){
            v.push_back(temp->val) ;
        }
        sort(v.begin(),v.end()) ;
        auto temp = list1 ;
        int n ;
        for(int i=0;temp && i<v.size();i++){
            temp->val = v[i] ;
            if(!temp->next){
                temp->next = list2 ;
                temp = list2 ;
                n = i+1 ;
                break ;
            }
            temp = temp->next ;
        }
        for(int i=n;i<v.size() && temp;i++){
            temp->val = v[i] ;
            temp = temp->next ;
        }
        return list1 ;
    }
};

// brute force approach, worst time and space