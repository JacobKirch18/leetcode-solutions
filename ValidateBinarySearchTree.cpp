//THIS IS AN AWFUL SOLUTION
//DO NOT USE THIS
//
//Given the root of a binary tree, determine if it is a valid binary search tree(BST).
//
//A valid BST is defined as follows :
//
//The left
//subtree
//of a node contains only nodes with keys less than the node's key.
//The right subtree of a node contains only nodes with keys greater than the node's key.
//Both the left and right subtrees must also be binary search trees.
//
//
//Example 1:
//
//
//Input: root = [2, 1, 3]
//Output : true
//Example 2 :
//
//
//	Input : root = [5, 1, 4, null, null, 3, 6]
//	Output : false
//	Explanation : The root node's value is 5 but its right child's value is 4.
//
//
//	Constraints :
//
//	The number of nodes in the tree is in the range[1, 104].
//	- 231 <= Node.val <= 231 - 1

#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using std::cout;
using std::vector;
using std::set;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    bool isValidBST(TreeNode* root) {

        InOrderTraversal(root);
        vector<int> treeTest = tree;
        sort(treeTest.begin(), treeTest.end());

        if (tree != treeTest || duplicateExists()) {
            return false;
        }
        return true;

    }
private:
    vector<int> tree;
    void InOrderTraversal(TreeNode* node) {
        if (node != nullptr) {
            InOrderTraversal(node->left);
            tree.push_back(node->val);
            InOrderTraversal(node->right);
        }
    }
    bool duplicateExists() {
        set<int> uniqueElements;
        for (int val : tree) {
            if (uniqueElements.find(val) != uniqueElements.end()) {
                return true;
            }
            uniqueElements.insert(val);
        }
        return false;
    }
};

void main() {

	TreeNode* root = new TreeNode(2);
	root->left = new TreeNode(1);
	root->right = new TreeNode(3);

	Solution solution;
	bool result = solution.isValidBST(root);

	cout << result;

}