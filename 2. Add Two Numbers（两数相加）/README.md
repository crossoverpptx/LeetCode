# 2. Add Two Numbers（两数相加）

## 方法1：转换求和再转换法

### 算法与思路

首先想到的方法是：先求出两个链表对应的整数，得出两数之和，再将结果转成新链表。但是该算法有一个明显的问题：每个链表中的节点数在范围 [1, 100] 内，很可能会溢出。

### C++ 解法一

```c++
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
```
## 方法2：依次转换法

### 算法与思路

更好的方案是依次将两个链表的节点值相加直接存入新的链表，这样就不存在溢出的问题。

首先定义一个新的链表dummy，节点值设为-1，同时定义一个指针指向链表的最后一个节点。当两个输入节点不同时为空则执行循环操作，因为是依次将两个节点值相加，所以对于可能出现的进位值要设一个变量carry；当两个输入链表都为空时退出循环，此时需要判断有没有进位值，若有则需将该值存入链表的下一个节点。返回的是dummy的下一个节点开始的链表。

### C++ 解法二

```c++
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
```

