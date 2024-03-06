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
    bool hasCycle(ListNode *head) {
        unordered_set<long unsigned int> nodeSet;
        if(head != nullptr)
        {
            while(head->next != nullptr)
            {
                if(nodeSet.insert(reinterpret_cast<long unsigned int>(head)).second == false)
                {
                    return true;
                }
                head = head->next;
            }
        }
        return false;
    }
};