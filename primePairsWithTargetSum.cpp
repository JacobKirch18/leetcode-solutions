//You are given an integer n.We say that two integers x and y form a prime number pair if:
//
//1 <= x <= y <= n
//x + y == n
//x and y are prime numbers
//Return the 2D sorted list of prime number pairs[xi, yi].The list should be sorted in increasing order of xi.If there are no prime number pairs at all, return an empty array.
//
//Note : A prime number is a natural number greater than 1 with only two factors, itself and 1.
//
//
//
//Example 1 :
//
//    Input : n = 10
//    Output : [[3, 7], [5, 5]]
//    Explanation : In this example, there are two prime pairs that satisfy the criteria.
//    These pairs are[3, 7] and [5, 5], and we return them in the sorted order as described in the problem statement.
//    Example 2 :
//
//    Input : n = 2
//    Output : []
//    Explanation : We can show that there is no prime number pair that gives a sum of 2, so we return an empty array.
//
//
//    Constraints :
//
//    1 <= n <= 106

#include <iostream>
#include <vector>

using std::cout;
using std::vector;

class Solution {
public:

    vector<vector<int>> findPrimePairs(int n) {

        vector<vector<int>> primePairs;

        for (int i = 2; i <= n / 2; i++) {

            if (isPrime(i) && isPrime(n - i)) {

                primePairs.push_back({ i, n - i });
            }
        }

        return primePairs;

    }

private:
    bool isPrime(int n) {

       
        if (n <= 1) {
            return false;
        }

        if (n == 2) {
            return true;
        }

        if (n % 2 == 0) {
            return false;
        }

        for (int i = 3; i <= sqrt(n); i += 2) {
            if (n % i == 0) {
                return false;
            }
        }

        return true;

    }

};

void main() {

    Solution solution;
    int n = 10;
    vector<vector<int>> primePairs = solution.findPrimePairs(n);

    for (const auto& pair : primePairs) {
        cout << "[" << pair[0] << ", " << pair[1] << "] ";
    }

    cout << std::endl;

    n = 5;
    primePairs = solution.findPrimePairs(n);

    for (const auto& pair : primePairs) {
        cout << "[" << pair[0] << ", " << pair[1] << "] ";
    }

}
