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
    bool isPalindrome(ListNode* head) 
    {
        ListNode* slow = head;
        ListNode* fast = head;
        bool result = true;
        while((fast != nullptr && (fast->next != nullptr)))
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* prev = nullptr;
        ListNode* rear = slow;
        while(slow != nullptr)
        {
            rear = slow->next;
            slow->next = prev;
            prev = slow;
            if(rear == nullptr)
                break;
            slow = rear;
        }
        ListNode* left = head;
        ListNode* right = slow;
        while(right != nullptr)
        {
            if((left->val) != (right->val))
            {
                result = false;
                break;
            }
            left = left->next;
            right = right->next;
        }
        return result;
    }
};