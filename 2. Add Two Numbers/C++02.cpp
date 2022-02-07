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
        ListNode* dummy = new ListNode(-1), * cur = dummy;
        int carry = 0;
        while (l1 || l2) 
        {
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;
            int sum = val1 + val2 + carry;
            carry = sum / 10;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (carry) cur->next = new ListNode(1);
        return dummy->next;
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