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
    ListNode* swapPairs(ListNode* head)
    {
        
    }
private:
    ListNode* GetKGround(ListNode* start, int k)
    {
        ListNode* temp = start;
        while(temp != nullptr && k > 0)
        {
            temp = temp->next;
            k--;
        }
    }
};
#pragma endregion