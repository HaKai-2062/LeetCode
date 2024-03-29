/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode* head)
    {
        // Storing index, memory address
        std::unordered_map<ListNode*, int> hashMap;

        int index = 0;
        while (head)
        {
            if (hashMap.find(head) != hashMap.end())
                return true;

            hashMap.insert({head, index});
            
            head = head->next;
            index++;
        }
        return false;
    }
};