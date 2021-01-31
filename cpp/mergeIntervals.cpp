// Source: https://leetcode.com/problems/merge-intervals/
// Author: Kelly Tay

/**
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
**/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //sort it
        //subtract the next start with the current end
            //negative or equal to- subtract the next start with the current start
            //positve - end range of current and start range of next is good
        vector<vector<int>> result;
        
        sort(intervals.begin(), intervals.end(), [](vector<int>& interval1, vector<int>& interval2) {
            return interval1[0] < interval2[0];
        });
        
        result.push_back(intervals[0]);
        
        for(int row = 1; row < intervals.size(); row++) {
            if(intervals[row][0] - result[result.size() - 1][1] <= 0) {
                if(intervals[row][1] > result[result.size() - 1][1]) {
                    result[result.size() - 1][1] = intervals[row][1];
                }
            }
            else {
                result.push_back(intervals[row]);
            }
        }
        
        return result;
    }
};