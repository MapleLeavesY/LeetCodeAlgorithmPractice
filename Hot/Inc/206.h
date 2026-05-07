#include <iostream>

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
        ListNode* current = head;
        ListNode* rear;
        ListNode* prev = nullptr;
        while(current != nullptr)
        {
            rear = current->next;
            current->next = prev;
            prev = current;
            current = rear;
        }
        return prev;
    }
};