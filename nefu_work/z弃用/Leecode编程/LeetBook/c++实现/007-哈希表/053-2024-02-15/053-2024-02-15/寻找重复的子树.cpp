#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<string>
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
      vector<TreeNode*>res;
      unordered_map<string, int>m;

      //用字符串记录子树，递归处理
      string dfs(TreeNode* root)
      {
          if (root == NULL)return "";
          //to_string 在 string 头文件里
          string subtreevalue = to_string(root->val) + "--" + dfs(root->left) + "--" + dfs(root->right);
          if (m[subtreevalue] == 1)res.push_back(root);//这里必须是==1，因为比如说第一个样例中4有三个相同结构
          //这时，会被push进去两个4的节点，但是再重复题目要求push进去一个就够了
          m[subtreevalue]++;


          return subtreevalue;
      }

      vector<TreeNode*> findDuplicateSubtrees(TreeNode* root)
      {
          dfs(root);
          return res;
      }
  };


int main() 
{
	return 0;
}