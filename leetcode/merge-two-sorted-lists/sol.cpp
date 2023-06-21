#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;
        
        ListNode* tail = new ListNode(0);
        ListNode* start = tail;
        
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            }
            else {
                tail->next = list2;
                list2 = list2->next;
            }
            
            tail = tail->next;
        }
        
        if (list1 != nullptr)
            tail->next = list1;
        if (list2 != nullptr)
            tail->next = list2;
        
        ListNode* toDelete = start;
        start = start->next;
        delete toDelete;
        return start;
    }
};

int main() {
    Solution s;
    
    ListNode x1 = ListNode(4, nullptr);
    ListNode x2 = ListNode(2, &x1);
    ListNode x3 = ListNode(1, &x2);

    ListNode x4 = ListNode(4, nullptr);
    ListNode x5 = ListNode(3, &x4);
    ListNode x6 = ListNode(1, &x5);

    ListNode* res = s.mergeTwoLists(&x3, &x6);
    while (res != nullptr) {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
}
