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
class Solution {
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        //�������������һ��ֵһ���Ǹ��ڵ�
        //������������������root��λ�÷ָ���������
        if (inorder.empty()) return NULL;

	}
};
int main()
{

	system("pause");

	return 0;
}