class Solution {
public:
    bool hasCycle(ListNode* head)
    {
        ListNode* slow = head;

        if (!slow)
            return false;

        ListNode* fast = head->next;

        while (slow != fast)
        {
            if (!fast)
                return false;
            
            slow = slow->next;
            fast = fast->next;

            if (!fast)
                return false;

            // To ensure we are not accessing nullptr
            fast = fast->next;
        }

        return true;
    }
};