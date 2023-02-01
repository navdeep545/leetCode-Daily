struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {

        vector<vector<int>> v(m,vector<int>(n,-1)) ;
        ListNode *temp = head ;
        int dir = 0 ;
        int top = 0 ;
        int down = m-1 ;
        int left = 0 ;
        int right = n-1 ;
        while(top <= down || left <= right){
            if(dir == 0){
                for(int i=left;temp && i<=right;i++){
                    v[top][i] = temp->val ;
                    temp = temp->next ;
                }
                top++ ;
            }
            else if(dir == 1){
                for(int i=top;temp && i<=down;i++){
                    v[i][right] = temp->val ;
                    temp = temp->next ;
                }
                right-- ;
            }
            else if(dir == 2){
                for(int i=right;temp && i>=left;i--){
                    v[down][i] = temp->val ;
                    temp = temp->next ;
                }
                down-- ;
            }
            else if(dir == 3){
                for(int i=down;temp && i>=top;i--){
                    v[i][left] = temp->val ;
                    temp = temp->next ;
                }
                left++ ;
            }
            dir = (dir+1) % 4 ;
        }
        return v;
    }
};