// my second hard question , wasnt actually a hard one

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<int, vector<int>, greater<int>> pqq;
        for (int i = 0; i < lists.size(); i++)
        {
            for (auto temp = lists[i]; temp; temp = temp = temp->next)
            {
                if (temp)
                    pqq.push(temp->val);
            }
        }
        ListNode *head = new ListNode();
        if (!pqq.empty())
        {
            head->val = pqq.top();
            pqq.pop();
        }
        else
            return NULL;
        // pqq.pop() ;
        ListNode *temp = head;
        while (!pqq.empty())
        {
            temp->next = new ListNode(pqq.top());
            temp = temp->next;
            pqq.pop();
        }
        return head;
    }
};