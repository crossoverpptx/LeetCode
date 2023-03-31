#include <iostream>

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* l = new ListNode(-1), *cur = l;
        int res1 = 0, res2 = 0, res, i = 1, j = 1;
        while (l1)
        {
            res1 += l1->val * i;
            l1 = l1->next;
            i *= 10;
        }
        while (l2)
        {
            res2 += l2->val * j;
            l2 = l2->next;
            j *= 10;
        }
        res = res1 + res2;

        while (res / 10)
        {
            cur->next = new ListNode(res % 10);
            cur = cur->next;
            res /= 10;
        }
        cur->next = new ListNode(res);
        return l->next;
    }
};

int main()
{
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    Solution s;
    ListNode* res = s.addTwoNumbers(l1, l2);
    while (res)
    {
        std::cout << res->val << " ";
        res = res->next;
    }
    return 0;
}