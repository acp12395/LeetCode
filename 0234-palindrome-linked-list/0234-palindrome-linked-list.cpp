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
private:
    stack<int> storageStack;
public:
    bool isPalindrome(ListNode* head) {
        bool retVal = true;
        ListNode* itNode = head;
        do
        {
            storageStack.push(itNode->val);
            itNode = itNode->next;
        }while(itNode != nullptr);
        itNode = head;
        do
        {
            retVal &= (storageStack.top() == itNode->val);
            storageStack.pop();
            itNode = itNode->next;
        }while(itNode != nullptr);
        return retVal;
    }
};