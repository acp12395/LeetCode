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
    ListNode* middleNode(ListNode* head) {
        ListNode* turtle = head;
        ListNode* hare = head;
        while(hare->next != nullptr)
        {
            turtle = turtle->next;
            for(int twiceCtr = 0; twiceCtr <= 1; twiceCtr++)
            {
                if(hare->next != nullptr)
                {
                    hare = hare->next;
                }
                else
                {
                    break;
                }
            }
        }
        return turtle;
    }
};