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
    ListNode* doubleIt(ListNode* head) {
        ListNode currNodeSelector(0,head);
        ListNode* doubleHead;
        if(head->val >= 5)
        {
            ListNode* prevNode = new(ListNode);
            prevNode->val = 1;
            prevNode->next = head;
            doubleHead = prevNode;
        }
        else
        {
            doubleHead = head;
        }
        while(currNodeSelector.next != nullptr)
        {
            currNodeSelector.next->val = (currNodeSelector.next->val*2)%10;
            if(currNodeSelector.next->next != nullptr && currNodeSelector.next->next->val >= 5)
            {
                currNodeSelector.next->val++;
            }
            currNodeSelector = *currNodeSelector.next;
        }
        return doubleHead;
    }
};