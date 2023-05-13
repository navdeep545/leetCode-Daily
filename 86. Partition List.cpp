struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *low = new ListNode(x - 1);
        ListNode *high = new ListNode(x + 1);
        auto lower = low;
        auto higher = high;
        // auto temp = head ;
        while (head)
        {
            if (head->val < x)
            {
                lower->next = head;
                lower = lower->next;
            }
            else
            {
                higher->next = head;
                higher = higher->next;
            }
            head = head->next;
        }
        lower->next = high->next;
        higher->next = nullptr;
        return low->next;
    }
};
