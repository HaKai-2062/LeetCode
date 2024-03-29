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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
	{
        if (list1 == nullptr)
            return list2;
        
        if (list2 == nullptr)
            return list1;

        ListNode* head = list1->val <= list2->val? list1 : list2;

        while (list1 && list2)
        {
            // Greater than current and next value
            if (list2->val > list1->val && list1->next != nullptr && list2->val > list1->next->val)
            {
                list1 = list1->next;
                continue;
            }
            else if (list1->val > list2->val && list2->next != nullptr && list1->val > list2->next->val)
            {
                list2 = list2->next;
                continue;
            }

            // if l2 is between l1 and l1->next
            if (list2->val >= list1->val && (list1->next == nullptr || list2->val <= list1->next->val))
            {
                ListNode* temp = list2->next;

                list2->next = list1->next;
                list1->next = list2;

                list2 = temp;
            }
            else if (list1->val >= list2->val && (list2->next == nullptr || list1->val <= list2->next->val))
            {
                ListNode* temp = list1->next;

                list1->next = list2->next;
                list2->next = list1;

                list1 = temp;
            }
        }

        return head;
    }
};