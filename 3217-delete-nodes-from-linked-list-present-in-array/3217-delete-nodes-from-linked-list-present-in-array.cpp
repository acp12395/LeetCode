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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> numsSet;
        numsSet.insert(nums.begin(), nums.end());
        ListNode* retHead = head;
        ListNode prevNode(0, head);
        ListNode* prevHead = &prevNode;
        while(prevHead->next != nullptr)
        {
            if(numsSet.count(head->val) > 0)
            {
                if(retHead->val == head->val)
                {
                    retHead = retHead->next;
                }
                head = head->next;
                delete prevHead->next;
                prevHead->next = head;
            }
            else
            {
                head = head->next;
                prevHead = prevHead->next;
            }
        }
        return retHead;
    }
};