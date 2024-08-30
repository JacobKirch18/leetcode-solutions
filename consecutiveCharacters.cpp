#include <iostream>
#include <string>

using std::cout;
using std::string;

//The power of the string is the maximum length of a non - empty substring that contains only one unique character.
//
//Given a string s, return the power of s.
//
//
//
//Example 1:
//
//Input: s = "leetcode"
//Output : 2
//Explanation : The substring "ee" is of length 2 with the character 'e' only.
//Example 2 :
//
//    Input : s = "abbcccddddeeeeedcba"
//    Output : 5
//    Explanation : The substring "eeeee" is of length 5 with the character 'e' only.
//
//
//    Constraints :
//
//    1 <= s.length <= 500
//    s consists of only lowercase English letters.

class Solution {
public:
    int maxPower(string s) {

        int currentLength = 1;
        int maxLength = 1;

        for (int i = 0; i < s.length(); i++) {

            if (i != s.length() - 1) {
                if (s[i] == s[i + 1]) {
                    currentLength++;
                }
                else {
                    currentLength = 1;
                }
                if (currentLength > maxLength) {
                    maxLength = currentLength;
                }
            }

        }

        return maxLength;

    }
};

void main() {

	Solution solution;
	string s = "leetcode";
	cout << solution.maxPower(s) << "\n";

	s = "abbcccddddeeeeedcba";
	cout << solution.maxPower(s) << "\n";

}