#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
#pragma region 相交链表 160
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        unordered_set<ListNode*> st;
        ListNode* temp;

        temp = headA;
        while(temp != nullptr)
        {
            st.insert(temp);
            temp = temp->next;
        }
        temp = headB;
        while(temp != nullptr)
        {
            if(st.count(temp))
            {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        ListNode* pA = headA;
        ListNode* pB = headB;
        while(pA != pB)
        {
            pA = (pA == nullptr) ? headB : pA->next;
            pB = (pB == nullptr) ? headA : pB->next;
        }
        return pA;
    }
};
#pragma endregion