//Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non - overlapping intervals that cover all the intervals in the input.
//
//
//
//Example 1:
//
//Input: intervals = [[1, 3], [2, 6], [8, 10], [15, 18]]
//Output : [[1, 6], [8, 10], [15, 18]]
//Explanation : Since intervals[1, 3] and [2, 6] overlap, merge them into[1, 6].
//Example 2 :
//
//	Input : intervals = [[1, 4], [4, 5]]
//	Output : [[1, 5]]
//	Explanation : Intervals[1, 4] and [4, 5] are considered overlapping.
//
//
//		Constraints :
//
//		1 <= intervals.length <= 104
//		intervals[i].length == 2
//		0 <= starti <= endi <= 104

#include <algorithm>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::max;
using std::vector;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ret;
        for (int i = 0; i < intervals.size(); i++) {
            if (ret.empty() || ret.back()[1] < intervals[i][0]) {
                ret.push_back(intervals[i]);
            }
            else {
                ret.back()[1] = max(ret.back()[1], intervals[i][1]);
            }
        }
        return ret;
    }
};

void main() {
	vector<vector<int>> intervals = { {1, 3}, {2, 6}, {8, 10}, {15, 18} };
	Solution s;
	vector<vector<int>> ret = s.merge(intervals);
	for (int i = 0; i < ret.size(); i++) {
		cout << "[" << ret[i][0] << ", " << ret[i][1] << "]" << endl;
	}
}