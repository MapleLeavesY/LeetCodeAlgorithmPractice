#include <iostream>
#include <vector>
#include <algorithm>

#pragma region 排序链表
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//暴力解法-操作数组 空间复杂度O(n)
class Solution
{
public:
    ListNode* sortList(ListNode* head)
    {
        if(head == nullptr) return nullptr;
        std::vector<int> _channel;
        ListNode* temp = head;

        while(temp != nullptr)
        {
            _channel.push_back(temp->val);
            temp = temp->next;
        }

        int Count = _channel.size();
        std::sort(_channel.begin(), _channel.end());

        ListNode* result = new ListNode(_channel[0], nullptr);
        ListNode* current = result;
        for(int x = 1; x < Count; x++)
        {
            ListNode* next = new ListNode(_channel[x], nullptr);
            current->next = next;
            current = next;
        }
        return result;
    }
};
#pragma endregion