#include <iostream>
#include <unordered_set>


struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) 
    {
        std::unordered_set<ListNode*> st;
        ListNode* result = nullptr;
        ListNode* temp = head;
        while(temp != nullptr)
        {
            if(st.count(temp))
            {
                result = temp;
                break;
            }
            st.insert(temp);
            temp = temp->next;
        }
        return result;
    }
};