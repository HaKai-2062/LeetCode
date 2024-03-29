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
	ListNode* reverseList(ListNode* head)
	{
        if (!head)
            return nullptr;
        ListNode* temp = head->next;
        ListNode* temp2 = head->next;
        head->next = nullptr;

        while (temp)
        {
            // Right pointer
            temp2 = temp->next;
            // Reverse the direction
            temp->next = head;
            // Bring head to right
            head = temp;
            // Bring temp to right
            temp = temp2;
        }
        return head;
    }
};