#include <iostream>
using namespace std;

/* Problem link - https://leetcode.com/problems/delete-node-in-a-linked-list/ */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        node->val = node->next->val;
        ListNode *del = node->next;
        node->next = del->next;
        delete del;
    }
};

int main()
{
    return 0;
}
