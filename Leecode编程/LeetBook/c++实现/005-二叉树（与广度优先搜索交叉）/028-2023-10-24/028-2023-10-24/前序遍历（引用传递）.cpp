#include <iostream>
using namespace std;
#include<vector>


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


     vector<int> preorderTraversal(TreeNode* root)
     {
         vector<int> ret;
         dfs(root, ret);  // 先序遍历递归函数
         return ret;
     }

     void dfs(TreeNode* root, vector<int>& ret)
     {
         if (root == nullptr)
         {
             return;
         }
         ret.push_back(root->val);   // 记录 先序遍历 的顺序
         dfs(root->left, ret);
         dfs(root->right, ret);
     }
 };


int main()
{

	system("pause");

	return 0;
}