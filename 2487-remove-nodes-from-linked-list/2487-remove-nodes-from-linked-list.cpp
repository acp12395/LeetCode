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
    ListNode* removeNodes(ListNode* head) {
        vector<ListNode*> modifiedList;
        modifiedList.push_back(head);
        while(head->next != nullptr)
        {
            head = head->next;
            while(!modifiedList.empty() && modifiedList.back()->val < head->val)
            {
                modifiedList.pop_back();
            }
            if(!modifiedList.empty())
            {
                modifiedList.back()->next = head;
            }
            modifiedList.push_back(head);
        }
        return modifiedList[0];
    }
};