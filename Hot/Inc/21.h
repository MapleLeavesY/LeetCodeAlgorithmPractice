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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;
        ListNode* rear1 = list1;
        ListNode* rear2 = list2;
        ListNode* current;
        ListNode* result = nullptr;
        if(rear1->val <= rear2->val)
        {
            result = rear1;
            rear1 = rear1->next;
        }
        else
        {
            result = rear2;
            rear2 = rear2->next;
        }
        current = result;
        while(rear1 && rear2)
        {
            if(rear1->val <= rear2->val)
            {
                current->next = rear1;
                current = current->next;
                rear1 = rear1->next;
            }
            else
            {
                current->next = rear2;
                current = current->next;
                rear2 = rear2->next;
            }
        }
        if(rear1)
            current->next = rear1;
        else
            current->next = rear2;
        return result;
    }
};