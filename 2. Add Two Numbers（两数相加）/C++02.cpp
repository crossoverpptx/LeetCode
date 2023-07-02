#include <iostream>
#include <vector>

//定义链表节点
struct ListNode {
    int val;    //节点值
    ListNode *next; //节点存储的next节点地址
    ListNode() : val(0), next(nullptr) {}   //无参构造函数：节点值为0，next节点地址为空
    ListNode(int x) : val(x), next(nullptr) {}  //有参构造函数：节点值为x，next节点地址为空
    ListNode(int x, ListNode *next) : val(x), next(next) {} //有参构造函数：节点值为x，next节点地址为next
};

ListNode* createList(const std::vector<int>& nums) { //使用&：因为无需拷贝nums；使用const：因为无需改变nums中元素的值
    ListNode dummy(0); //定义哑结点（方式一）：在栈上开辟空间，由系统自动分配内存并销毁
    //ListNode* dummy = new ListNode(); //定义哑结点（方式二）：在堆上开辟空间，手动分配内存并需要手动销毁
    //为什么在这里要采用方式一：因为后面在销毁链表时，并没有处理哑结点。如果采用方式二，需要在后面处理哑结点。
    ListNode* node = &dummy;

    for (const int& n: nums) {
        node->next = new ListNode(n);
        node = node->next;
    }

    return dummy.next;
}

void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

void destroyList(ListNode* head) {
    while (head) {
        ListNode* delNode = head;
        head = head->next;
        delete delNode;
    }
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1), * cur = dummy;
        int carry = 0;
        while (l1 || l2) {
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

int main() {
    std::vector<int> nums1{2, 4, 3};
    std::vector<int> nums2{5, 6, 4};
    ListNode* l1 = createList(nums1);
    ListNode* l2 = createList(nums2);
    printList(l1);
    printList(l2);

    Solution s;
    printList(s.addTwoNumbers(l1, l2));

    destroyList(l1);
    destroyList(l2);
    return 0;
}
