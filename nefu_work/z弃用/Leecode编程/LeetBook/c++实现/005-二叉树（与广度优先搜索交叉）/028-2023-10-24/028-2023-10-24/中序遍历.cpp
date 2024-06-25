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


    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> ret;
        dzs(root, ret); 
        return ret;
    }

    void dzs(TreeNode* root, vector<int>& ret)
    {
        if (root == nullptr)
        {
            return;
        }   
        dzs(root->left, ret);
        ret.push_back(root->val);
        dzs(root->right, ret);
    }
};
int main()
{

	system("pause");

	return 0;
}