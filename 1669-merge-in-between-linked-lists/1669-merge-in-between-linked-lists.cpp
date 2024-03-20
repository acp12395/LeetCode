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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* prevNode = list1;
        ListNode* currNode = list1->next;
        int nodeIndex = 1;
        while(nodeIndex <= b)
        {
            if(nodeIndex == a)
            {
                prevNode->next = list2;
            }
            if(nodeIndex == b)
            {
                while(prevNode->next != nullptr)
                {
                    prevNode = prevNode->next;
                }
                prevNode->next = currNode->next;
                break;
            }
            if(prevNode->next != nullptr)
            {
                prevNode = prevNode->next;
            }
            if(currNode->next != nullptr)
            {
                currNode = currNode->next;
            }
            nodeIndex++;
        }
        return list1;
    }
};