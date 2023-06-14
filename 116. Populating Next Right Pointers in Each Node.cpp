/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (!root)
            return NULL;
        queue<Node *> bus;
        bus.push(root);
        while (!bus.empty())
        {
            int n = bus.size();
            queue<Node *> newBus;
            while (n--)
            {
                auto front = bus.front();
                bus.pop();
                newBus.push(front);
                if (front->left)
                    bus.push(front->left);
                if (front->right)
                    bus.push(front->right);
            }
            if (!newBus.empty())
            {
                Node *newNode = newBus.front();
                newBus.pop();
                while (!newBus.empty())
                {
                    auto front = newBus.front();
                    newBus.pop();
                    newNode->next = front;
                    newNode = front;
                }
                newNode->next = NULL;
            }
        }
        return root;
    }
};