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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0) {
            return head;
        }
        ListNode* dummy = head;
        int nodes = 2;
        while (dummy->next->next != NULL) {
            dummy = dummy->next;
            nodes++;
        }

        for (int i = 1; i <= k % nodes; i++) {
            dummy = head;
            while (dummy->next->next != NULL) {
                dummy = dummy->next;
            }
            ListNode* last = dummy->next;
            ListNode* seclast = dummy;
            last->next = head;
            seclast->next = NULL;
            head = last;
        }
        return head;
    }
};