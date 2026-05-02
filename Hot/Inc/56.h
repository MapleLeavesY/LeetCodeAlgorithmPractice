#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end());
        vector<int> start = intervals[0], end = {};
        
        for(int i = 1; i < intervals.size(); i++)
        {
            end = intervals[i];
            if(start[1] >= end[0])
            {
                start[1] = max(start[1], end[1]);
            }
            else
            {
                result.push_back(start);
                start = end;
            }
        }
        result.push_back(start);
        return result;
    }
};
