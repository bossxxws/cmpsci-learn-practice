#include <iostream>
using namespace std;
#include<vector>
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
class Solution 
{
public:
    void dls(TreeNode* root,vector<int>*res)
    {
        if (root == NULL) 
        {
            return;
        }
        dls(root->left, res);
        dls(root->right, res);
        (*res).push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int>*res  = new vector<int>;
        dls(root, res);
        return *res;
    }
};
int main()
{

	system("pause");

	return 0;
}