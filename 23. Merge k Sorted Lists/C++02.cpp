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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size() - 1);
    }

    ListNode* merge(vector<ListNode*> &lists, int l, int r) {
        if (l == r) return lists[l];
        if (l > r) return nullptr;    // 该情况貌似不会出现？错！这是递归退出条件，只是什么条件下会出现这种情况呢。
        int mid = (l + r) >> 1; // 比特操作，相当于除以2
        return mergeTwoLists(merge(lists, l, mid), merge(lists, mid + 1, r));
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* preHead = new ListNode(-1);

        ListNode* prev = preHead;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                prev->next = l1;
                l1 = l1->next;
            } else {
                prev->next = l2;
                l2 = l2->next;
            }
            prev = prev->next;
        }

        // 合并后 l1 和 l2 最多只有一个还未被合并完，我们直接将链表末尾指向未合并完的链表即可
        prev->next = l1 == nullptr ? l2 : l1;

        return preHead->next;
    }
};

int main() {
    vector<ListNode*> lists;

    vector<int> nums1{1, 4, 5};
    ListNode* l1 = createList(nums1);
    printList(l1);
    lists.push_back(l1);

    vector<int> nums2{1, 3, 4};
    ListNode* l2 = createList(nums2);
    printList(l2);
    lists.push_back(l2);

    vector<int> nums3{2, 6};
    ListNode* l3 = createList(nums3);
    printList(l3);
    lists.push_back(l3);

    Solution s;
    printList(s.mergeKLists(lists));

    destroyList(l1);
    destroyList(l2);
    destroyList(l3);

    return 0;
}

