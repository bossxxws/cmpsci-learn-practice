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
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return vector<vector<int>>();
        queue<TreeNode*> que;
        vector<vector<int>> res;
        que.push(root);
        while (!que.empty())
        {
            res.push_back(vector<int>());
            int size = que.size();
            for (int i = 0; i < size; ++i) 
            {
                TreeNode* cur = que.front();
                que.pop();
                res.back().push_back(cur->val);
                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right);
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