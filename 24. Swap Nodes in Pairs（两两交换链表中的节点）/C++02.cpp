#include <iostream>
#include <vector>
using namespace std;

// 定义链表节点
struct ListNode {
    int val;    // 节点值
    ListNode *next; // 节点存储的next节点地址
    ListNode() : val(0), next(nullptr) {}   // 无参构造函数：节点值为0，next节点地址为空
    ListNode(int x) : val(x), next(nullptr) {}  // 有参构造函数：节点值为x，next节点地址为空
    ListNode(int x, ListNode *next) : val(x), next(next) {} // 有参构造函数：节点值为x，next节点地址为next
};

ListNode* createList(const vector<int>& nums) { // 使用&：因为无需拷贝nums；使用const：因为无需改变nums中元素的值
    ListNode dummy(0); // 定义哑结点（方式一）：在栈上开辟空间，由系统自动分配内存并销毁
    //ListNode* dummy = new ListNode(); // 定义哑结点（方式二）：在堆上开辟空间，手动分配内存并需要手动销毁
    // 为什么在这里要采用方式一：因为后面在销毁链表时，并没有处理哑结点。如果采用方式二，需要在后面处理哑结点。
    ListNode* node = &dummy;

    for (const int& n: nums) {
        node->next = new ListNode(n);
        node = node->next;
    }

    return dummy.next;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* temp = dummyHead;
        while (temp->next != nullptr && temp->next->next != nullptr) {
            ListNode* node1 = temp->next;
            ListNode* node2 = temp->next->next;
            temp->next = node2;
            node1->next = node2->next;
            node2->next = node1;
            temp = node1;
        }
        return dummyHead->next;
    }
};

int main() {

    vector<int> nums{1, 2, 4, 5};
    ListNode* l = createList(nums);
    printList(l);

    Solution s;
    printList(s.swapPairs(l));

    destroyList(l);

    return 0;
}

