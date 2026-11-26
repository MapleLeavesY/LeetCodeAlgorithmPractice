#include <iostream>

#pragma region k值窗口内部交换链表
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
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        ListNode result(0, head);
        ListNode* prev = &result;

        while(1)
        {
            ListNode* right = GetRightListNode(prev, k);

            if(right == nullptr) break;
            ListNode* rear = right->next;
            ListNode* left = prev->next;

            ListNode* cur0 = left;
            ListNode* cur1 = cur0->next;
            while(cur1 != rear)
            {
                ListNode* cur2 = cur1->next;
                cur1->next = cur0;
                cur0 = cur1;
                cur1 = cur2;
            }
        
            prev->next = cur0;
            left->next = rear;

            prev = left;
        }
        return result.next;
    }
    ListNode* GetRightListNode(ListNode* start, int k)
    {
        ListNode* temp = start;
        while(temp != nullptr && k > 0)
        {
            temp = temp->next;
            k--;
        }
        return temp;
    }
};
#pragma endregion