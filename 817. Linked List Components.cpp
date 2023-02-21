class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> seen;
        for(auto x : nums) seen.insert(x);

        int answer = 0, cnt = 0;
        while(head) {
            if(seen.count(head->val)) cnt++;
            else {
                if(cnt) answer++;
                cnt = 0;
            }
            head = head -> next;
        }
        if(cnt) answer++;
        return answer;
    }
};

// solution from editorial with time O(N) and space O(N)

// my solution
/*
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_map<int,int> mpp ;
        // int n=0;
        int ans = 0 ;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]] = i ;
            // i++ ;
        }
        while(head && head->next){
            while(mpp.find(head->val) == mpp.end()) head = head->next ;
            if(head && mpp.find(head->val) != mpp.end()){
                if(head->next && mpp.find(head->next->val) != mpp.end()){
                    if(mpp[head->val] < mpp[head->next->val]) ans++ ;
                }
            }
            if(head->next && !head->next->next){
                return ans ;
            }
            else if(head->next) head = head->next->next ;
        }
        if(head && (mpp.find(head->val) != mpp.end())) ans++ ;
        return ans ;
    }
};
*/