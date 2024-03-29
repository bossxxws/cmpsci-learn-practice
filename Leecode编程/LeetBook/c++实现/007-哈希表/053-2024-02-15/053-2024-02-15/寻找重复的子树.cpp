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

      //���ַ�����¼�������ݹ鴦��
      string dfs(TreeNode* root)
      {
          if (root == NULL)return "";
          //to_string �� string ͷ�ļ���
          string subtreevalue = to_string(root->val) + "--" + dfs(root->left) + "--" + dfs(root->right);
          if (m[subtreevalue] == 1)res.push_back(root);//���������==1����Ϊ����˵��һ��������4��������ͬ�ṹ
          //��ʱ���ᱻpush��ȥ����4�Ľڵ㣬�������ظ���ĿҪ��push��ȥһ���͹���
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