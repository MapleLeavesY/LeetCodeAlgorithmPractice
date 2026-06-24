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

//暴力解法--操作数组--空间复杂度O(n)
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

// 排序链表--排序(归并算法)--空间复杂度O(logn)
class Solution
{
public:
    ListNode* sortList(ListNode* head)
    {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* rightHead = slow->next;
        slow->next = nullptr;

        ListNode* left = sortList(head);
        ListNode* right = sortList(rightHead);

        return N_Sort(left, right);
    }
    ListNode* N_Sort(ListNode* left, ListNode* right)
    {   
        ListNode result(0);
        ListNode* current = &result;

        while(left != nullptr && right != nullptr)
        {
            if(left->val < right->val)
            {//第一链表值小于第二链表值
                current->next = left;
                left = left->next;
            }
            else
            {//第一链表值大于或等于第二链表值
                current->next = right;
                right = right->next;
            }
            current = current->next;
        }
        if(left == nullptr) { current->next = right; }
        else { current->next = left; }
        return result.next;
    }
};
#pragma endregion