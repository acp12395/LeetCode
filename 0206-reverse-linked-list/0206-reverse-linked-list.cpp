class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        stack<int> valStack;
        ListNode start(0,head);
        ListNode* currHead = &start;
        while(currHead->next != nullptr)
        {
            currHead = currHead->next;
            valStack.push(currHead->val);
        }
        currHead = &start;
        while(currHead->next != nullptr)
        {
            currHead = currHead->next;
            currHead->val = valStack.top();
            valStack.pop();
        }
        return head;
    }
};