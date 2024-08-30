//Given an integer x, return true if x is a
//palindrome
//, and false otherwise.
//
//
//
//Example 1:
//
//Input: x = 121
//Output : true
//Explanation : 121 reads as 121 from left to right and from right to left.
//Example 2 :
//
//	Input : x = -121
//	Output : false
//	Explanation : From left to right, it reads - 121. From right to left, it becomes 121 - .Therefore it is not a palindrome.
//	Example 3 :
//
//	Input : x = 10
//	Output : false
//	Explanation : Reads 01 from right to left.Therefore it is not a palindrome.
//
//
//	Constraints :
//
//	-231 <= x <= 231 - 1

#include <iostream>
#include <string>

using std::string;
using std::to_string;

class Solution {
public:
    bool isPalindrome(int x) {

        if (x < 0) {
            return false;
        }

        string s = to_string(x);
        string t = s;
        reverse(t.begin(), t.end());
        if (s == t) {
            return true;
        }
        return false;

    }
};

void main() {
	Solution s;
	std::cout << s.isPalindrome(121) << std::endl;
	std::cout << s.isPalindrome(-121) << std::endl;
    std::cout << s.isPalindrome(10) << std::endl;
}