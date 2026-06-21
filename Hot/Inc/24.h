#include <iostream>

#pragma region 链表相邻交换
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode* swapPairs(ListNode* head)
    {
        ListNode result(0, head);
        ListNode* temp = &result;

        while(temp->next != nullptr && temp->next->next != nullptr)
        {
            ListNode* left = temp->next;
            ListNode* right = temp->next->next;

            left->next = right->next;
            right->next = left;
            temp->next = right;

            temp = left;
        }
        return result.next;
    }
};
#pragma endregion