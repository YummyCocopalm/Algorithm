/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int &val) {
        if (!head) return nullptr;
        ListNode* front = head;
        ListNode* prev = head;
        while (head) {
            if (head->val == val) {
                if (head == front) {
                    front = head->next;
                } else {
                    prev->next = head->next;
                }
            } else {
                prev = head;
            }            
            head = head->next;
        }
        return front;
    }
};