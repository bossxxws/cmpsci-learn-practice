#include <iostream>
using namespace std;
#include<vector>
#include<queue>


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
    int maxDepth(TreeNode* root)
    {
        if (!root) return 0;
        int leftd = maxDepth(root->left);
        int righd = maxDepth(root->right);
        return max(leftd, righd) + 1;
    }
};
int main()
{

	system("pause");
	return 0;
}