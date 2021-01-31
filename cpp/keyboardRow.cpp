// Source: https://leetcode.com/problems/keyboard-row/
// Author: Kelly Tay

/**
Given an array of strings words, return the words that can be typed using letters of the alphabet on only one row of American keyboard like the image below.

In the American keyboard:

the first row consists of the characters "qwertyuiop",
the second row consists of the characters "asdfghjkl", and
the third row consists of the characters "zxcvbnm".
**/

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_set<char> firstRow {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};
        unordered_set<char> secondRow {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
        unordered_set<char> thirdRow {'z', 'x', 'c', 'v', 'b', 'n', 'm'};
        
        vector<string> result;
        
        //lower the first index of the word
        //check if that first index exits in first row, second row, or third row
        //for whatever row it exists in, iterate through the rest of the word and make sure they all exist in the same set
        //if they all do, push the word into the result vector
        
        for(int i = 0; i < words.size(); i++) {
            bool checkFirstRow = false;
            bool checkSecondRow = false;
            bool checkThirdRow = false;
            
            if(firstRow.find(tolower(words[i][0])) != firstRow.end()) {
                checkFirstRow = true;
            }
            else if(secondRow.find(tolower(words[i][0])) != secondRow.end()) {
                checkSecondRow = true;
            }
            else if(thirdRow.find(tolower(words[i][0])) != thirdRow.end()) {
                checkThirdRow = true;
            }
            
            for(int j = 1; j < words[i].size(); j++) {
                if(checkFirstRow) {
                    if(firstRow.find(tolower(words[i][j])) == firstRow.end()) {
                        checkFirstRow = false;
                    }
                }
                else if(checkSecondRow) {
                    if(secondRow.find(tolower(words[i][j])) == secondRow.end()) {
                        checkSecondRow = false;
                    }
                }
                else if(checkThirdRow) {
                    if(thirdRow.find(tolower(words[i][j])) == thirdRow.end()) {
                        checkThirdRow = false;
                    }                    
                }
            }
            
            if(checkFirstRow || checkSecondRow || checkThirdRow) {
                result.push_back(words[i]);
            }
        }
        return result;
    }
};