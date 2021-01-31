// Source: https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/
// Author: Kelly Tay

/**
Given an integer number n, return the difference between the product of its digits and the sum of its digits.
**/

class Solution {
public:
    int subtractProductAndSum(int n) {
        int product = 1;
        int sum = 0;
        while(n > 0) {
            int digit = n % 10;
            product *= digit;
            sum += digit;
            n /= 10;
        }
        return product - sum;
    }
};