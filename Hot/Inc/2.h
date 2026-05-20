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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* result(new ListNode(0));
        ListNode* temp0 = result;
        int next = 0;
        int temp1 = 0, temp2 = 0;
        int sum = 0;
        while(l1 != nullptr || l2 != nullptr || next != 0)
        {
            temp1 = 0;
            temp2 = 0;
            if(l1 != nullptr)
            {
                temp1 = l1->val;
                l1 = l1->next;
            } 
            if(l2 != nullptr) 
            {
                temp2 = l2->val;
                l2 = l2->next;
            }
            sum = temp1 + temp2 + next;
            if(sum > 9) 
            {
                sum %= 10;
                next = 1;
            }
            else
            {
                next = 0;
            }
            temp0->next = new ListNode(sum, nullptr);
            temp0 = temp0->next;
        }   
        return result->next;
    }
};