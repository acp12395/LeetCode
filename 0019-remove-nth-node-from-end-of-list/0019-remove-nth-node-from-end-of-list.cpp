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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode nodeBeforeList(0, head);
        ListNode* follower = &nodeBeforeList;
        ListNode* guidance = &nodeBeforeList;
        for(int advance = n; advance > 0; advance--)
        {
            guidance = guidance->next;
        }
        while(guidance->next != nullptr)
        {
            follower = follower->next;
            guidance = guidance->next;
        }
        follower->next = follower->next->next;
        return nodeBeforeList.next;
    }
};