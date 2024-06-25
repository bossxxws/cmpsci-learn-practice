#include<iostream>
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
    vector<int>vec;
    vector<int> inorderTraversal(TreeNode* root)
    {
        
        if (root == nullptr)
            return vector<int>(0);
        // 访问优先级：左子树 -> 根节点 -> 右子树
        inorderTraversal(root->left);
        vec.push_back(root->val);
        inorderTraversal(root->right);
        return vec;
    }
};
int main() 
{
	return 0;
}