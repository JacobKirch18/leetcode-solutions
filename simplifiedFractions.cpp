#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::string;
using std::vector;

//Given an integer n, return a list of all simplified fractions between 0 and 1 (exclusive)such that the denominator is less - than - or -equal - to n.You can return the answer in any order.
//
//
//
//Example 1:
//
//Input: n = 2
//Output : ["1/2"]
//Explanation : "1/2" is the only unique fraction with a denominator less - than - or -equal - to 2.
//Example 2 :
//
//	Input : n = 3
//	Output : ["1/2", "1/3", "2/3"]
//	Example 3 :
//
//	Input : n = 4
//	Output : ["1/2", "1/3", "1/4", "2/3", "3/4"]
//	Explanation : "2/4" is not a simplified fraction because it can be simplified to "1/2".
//
//
//	Constraints :
//
//	1 <= n <= 100

class Solution {
public:
	vector<string> simplifiedFractions(int n) {
		vector<string> result;
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j < i; j++) {
				if (gcd(i, j) == 1) {
					result.push_back(std::to_string(j) + "/" + std::to_string(i));
				}
			}
		}
		return result;
	}

	int gcd(int a, int b) {
		if (b == 0) {
			return a;
		}
		return gcd(b, a % b);
	}
};

void main() {
	Solution sol;
	vector<string> result = sol.simplifiedFractions(4);
	for (string s : result) {
		cout << s << " ";
	}
}