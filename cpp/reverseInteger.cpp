// Source: https://leetcode.com/problems/reverse-integer/
// Author: Kelly Tay
// Date: 12/20/2020

/**
Given a 32-bit signed integer, reverse digits of an integer.

Note:
Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
**/

class Solution {
public:
    int reverse(long long x) {
        bool isNegative = false;
        if(x < 0) {
            isNegative = true;
            x *= (-1);
        }
        
        long long result = 0;
        
        while(x > 0) {
            result *= 10;
            result += x % 10;
            x /= 10;
        }
        
        if(isNegative) {
            result *= (-1);
        }
        
        if(result < INT32_MIN || result > INT32_MAX) {
            return 0;
        }
        
        return (int)result;
    }
};