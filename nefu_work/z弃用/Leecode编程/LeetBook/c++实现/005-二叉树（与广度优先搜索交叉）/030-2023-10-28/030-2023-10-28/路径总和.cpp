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
    //�ҿ���������������������
    //1.���ײ����жϣ��ü���������tar����root.val�����
    //2.from top to the bottom,add the val to sum=0,when reach bottom,judge that whether sum==tar

	bool hasPathSum(TreeNode* root, int targetSum)
    {
        if (root == NULL) return false;
        if (root->left == NULL && root->right == NULL) 
        {
            if (targetSum == root->val) return true;
            else return false;
        }
        targetSum = targetSum - root->val;
        return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
        
	}
};
int main()
{

	system("pause");

	return 0;
}