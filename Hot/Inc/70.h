#include <stack>
#include <queue>

class Solution {//栈
public:
    int climbStairs(int n) 
    {
        if(n < 3) return n;
        std::stack<int> stack;
        stack.push(1);
        stack.push(2);
        for(int i = 2; i < n; i++)
        {
            int tep0 = stack.top(); stack.pop();
            int tep1 = stack.top(); stack.pop();
            int tep2 = tep0 + tep1;
            stack.push(tep0);
            stack.push(tep2);
        }
        return stack.top();
    }
};

class Solution {//队列
public:
    int climbStairs(int n) 
    {
        if(n < 3) return n;
        std::queue<int> queue;
        queue.push(1);
        queue.push(2);
        for(int i = 2; i < n; i++)
        {
            int que1 = queue.front(); queue.pop();
            int que2 = queue.front(); queue.pop();
            int que3 = que1 + que2;
            queue.push(que2);
            queue.push(que3);
        }
        return queue.back();
    }
};

class Solution {//迭代
public:
    int climbStairs(int n) 
    {
        if(n < 3) return n;
        int current = 1;
        int l0 = 1, l1 = 2;
        for(int i = 2; i < n; i++)
        {
            current = l0 + l1;
            
            l0 = l1;
            l1 = current;
        }
        return current;
    }
};