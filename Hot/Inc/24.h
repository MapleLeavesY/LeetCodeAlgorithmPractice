#include <iostream>

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
        ListNode dummy(0, head);
        ListNode* temp = &dummy;

        while (temp->next != nullptr &&
               temp->next->next != nullptr)
        {
            ListNode* left = temp->next;
            ListNode* right = left->next;

            // 交换前：
            // temp -> left -> right -> 下一组

            left->next = right->next;
            right->next = left;
            temp->next = right;

            // 交换后：
            // temp -> right -> left -> 下一组

            temp = left;
        }

        return dummy.next;
    }
};
/*
class Solution {
public:
    ListNode* swapPairs(ListNode* head) 
    {
        ListNode* current = head;
        ListNode* left = current;
        ListNode* right;
        ListNode* temp = head;

        ListNode* result = head;
        int select = 0;
        while(current != nullptr)
        {
            if(select == 1)
            {
                select = 0;
                right = current->next;
                if(right->next == nullptr) return result;
                left->next = right->next;
                current->next = left;
                right->next = current;
                if(temp == head) temp = right;
                temp->next = right;

                temp = right;
                left = current;
            }
            current = current->next;
            if(current == nullptr || current->next == nullptr) return result;
            right = current->next;
            select++;
        }
        return result;
    }
};
*/