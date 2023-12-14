// Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* temp = new ListNode(0);
        temp->next = head;

        ListNode* prev = temp;

        while (head && head->next) {
            ListNode* first = head;
            ListNode* second = head->next;

            prev->next = second;
            first->next = second->next;
            second->next = first;

            prev = first;
            head = first->next;
        }
        return temp->next;
    }
};
int main() {
    Solution solution;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    ListNode* result = solution.swapPairs(head);
    ListNode* current = head;
    current = result;
    cout << "Modified List: ";
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}
