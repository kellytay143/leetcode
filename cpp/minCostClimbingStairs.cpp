// Source: https://leetcode.com/problems/min-cost-climbing-stairs/
// Author: Kelly Tay

/**
On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).

Once you pay the cost, you can either climb one or two steps. You need to find minimum cost to reach the top of the floor, and you can either start from the step with index 0, or the step with index 1.
**/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int first = cost[0];
        int second = cost[1];
        for(int i = 2; i < cost.size(); i++) {
            cost[i] = cost[i] + min(first, second);
            first = second;
            second = cost[i];
        }
        return min(first, second);
    }
};

//cost of n-1 step and n - 2 step
//T(N) = T(N) + min(T(N - 1), T(N - 2))