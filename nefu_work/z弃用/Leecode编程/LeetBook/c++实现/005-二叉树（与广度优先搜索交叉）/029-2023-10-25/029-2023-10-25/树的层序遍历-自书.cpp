#include <iostream>
using namespace std;
#include<vector>
#include<queue>
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
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        if (!root) return vector<vector<int>>();
        vector<vector<int>>res;
        queue<TreeNode*>qu;
        qu.push(root);
        while (!qu.empty()) 
        {
            res.push_back(vector<int>());
            int siz = qu.size();
            for (int i = 0; i < siz; i++) 
            {
                TreeNode* cur = qu.front();
                qu.pop();
                res.back().push_back(cur->val);
                if (cur->left) qu.push(cur->left);
                if (cur->right) qu.push(cur->right);
            }
        }
        return res;
    }
};
int main()
{

	system("pause");

	return 0;
}