class Solution {
private:
    ListNode* left;
    ListNode* right;
    stack<ListNode*> ptrStack;
    void reorderListHelper(ListNode* head)
    {
        ptrStack.push(head);
        right = head;
        if(head->next != nullptr)
        {
            reorderListHelper(head->next);
        }
        if(left->next != right && left != right)
        {
            right->next = left->next;
            left->next = right;
            left = left->next->next;
            ptrStack.pop();
            right = ptrStack.top();
        }
    }
public:
    void reorderList(ListNode* head) {
        left = head;
        right = head;
        reorderListHelper(head);
        right->next = nullptr;
        {
            int stackSize = ptrStack.size();
            for(;stackSize > 0; stackSize--)
            {
                ptrStack.pop();
            }
        }
    }
};