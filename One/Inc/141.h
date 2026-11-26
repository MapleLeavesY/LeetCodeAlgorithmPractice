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
    bool hasCycle(ListNode *head) 
    {
        std::unordered_set<ListNode*> st;
        bool result = false;
        ListNode* temp = head;
        while(temp != nullptr)
        {
            if(st.count(temp))
            {
                result = true;
                break;
            }
            st.insert(temp);
            temp = temp->next;
        }
        return result;
    }
};