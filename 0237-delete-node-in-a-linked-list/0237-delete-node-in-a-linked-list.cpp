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
    void deleteNode(ListNode* node) {
        int valRemove = node->val;
        ListNode prevNode(0);
        prevNode.next = node;
        while(prevNode.next->next->next != nullptr)
        {
            prevNode.next->val = prevNode.next->next->val;
            prevNode.next = prevNode.next->next;
        }
        prevNode.next->val = prevNode.next->next->val;
        prevNode.next->next->val = valRemove;
        prevNode.next->next = nullptr;
    }
};