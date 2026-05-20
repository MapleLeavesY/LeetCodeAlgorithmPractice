#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) 
    {
        ListNode* temp = head;
        ListNode* current = temp;
        ListNode* rear = temp;
        while(temp != nullptr)
        {
            rear = current->next;
            
            
        }
    }
};