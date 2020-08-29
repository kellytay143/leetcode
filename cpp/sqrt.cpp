// Source: https://leetcode.com/problems/sqrtx/
// Author: Kelly Tay
// Date: 08/26/2020

/**
Implement int sqrt(int x).

Compute and return the square root of x, where x is guaranteed to be a non-negative integer.

Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.
**/

class Solution {
public:
    int mySqrt(int x) {
        int left = 1;
        int right = x/2;
        if(x == 1) {
            return x;
        }
        while(left <= right) {
            int mid = (left + right) / 2;
            if (mid == x/mid) {
                return mid;
            }
            if(mid > x/mid) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return right;
    }
};
