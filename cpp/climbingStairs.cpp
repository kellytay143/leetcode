// Source: https://leetcode.com/problems/climbing-stairs/
// Author: Kelly Tay

/**
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
**/

class Solution {
public:
    int climbStairs(int n) {
        int firstStep = 1;
        int secondStep = 2;
        
        if(n == 1) {
            return firstStep;
        }
        if(n == 2) {
            return secondStep;
        }
        
        int result = 0;
        for(int i = 3; i <= n; i++) {
            result = firstStep + secondStep;
            firstStep = secondStep;
            secondStep = result;
        }
        return result;
    }
};
