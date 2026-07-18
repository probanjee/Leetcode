class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode dummy(0);
        dummy.next = head;
        
        ListNode* prev = &dummy;
        ListNode* curr = head;
        
        while (curr != nullptr && curr->next != nullptr) {
            ListNode* second = curr->next;
            ListNode* nextPair = curr->next->next;
            second->next = curr;       
            curr->next = nextPair;     
            prev->next = second;       

            prev = curr;               
            curr = nextPair;           
        }
        
        return dummy.next;
    }
};