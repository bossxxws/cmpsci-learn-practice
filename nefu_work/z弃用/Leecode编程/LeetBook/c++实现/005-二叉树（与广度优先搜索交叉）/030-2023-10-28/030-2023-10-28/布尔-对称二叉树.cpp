#include <iostream>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution 
{
public:
	bool isSymmetric(TreeNode* root)
    {
        return ismirror(root,root);
	}
    bool ismirror(TreeNode* left, TreeNode* right) 
    {
        if (left == NULL && right == NULL) return true;
        if (left == NULL || right == NULL) return false;
        if (left->val != right->val)
        {
            return false;
        }
        else return ismirror(left->right,right->left)&&ismirror(right->right,left->left);
    }
};
int main()
{

	system("pause");

	return 0;
}