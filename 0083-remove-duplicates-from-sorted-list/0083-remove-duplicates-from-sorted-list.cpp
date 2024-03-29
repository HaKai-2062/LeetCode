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
class Solution
{
public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        ListNode* left = head;
        if (!left)  return nullptr;

        // One after left
        ListNode* right = left->next;

        while (right)
        {
            if (left->val == right->val)
            {
                // Delete right
                ListNode* toDelete = right;
                right = right->next;
                left->next = right;
                delete toDelete;
            }
            else
            {
                // Move left and right one step ahead
                left = left->next;
                // Because of an edge case where right is the last element
                if (right)
                    right = right->next;
            }
        }

        return head;
    }

};