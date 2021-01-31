// Source: https://leetcode.com/problems/fizz-buzz/
// Author: Kelly Tay

/**
Write a program that outputs the string representation of numbers from 1 to n.

But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.
**/

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result;
        string temp = "";
        
        int i = 1;
        while(i <= n) {
            if(i % 3 == 0) {
                temp += "Fizz";
            }
            if(i % 5 == 0) {
                temp += "Buzz";
            }
            if(i % 3 != 0 && i % 5 != 0) {
                temp += to_string(i);
            }
            result.push_back(temp);
            temp = "";
            i++;
        }
        return result;
    }
};

//Notes: '' - single character, "" - string