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
    int answer=0;
    void axu(TreeNode* root,int depth)
    {
        if (!root) return;//匿名函数什么都不返回
        if (!root->left && !root->right) 
        {
            answer= max(answer, depth);
        }
        axu(root->left,depth+1);
        axu(root->right,depth+1);
    }
    int maxDepth(TreeNode* root) 
    {
        if (!root) return 0;
        axu(root, 1);
        return answer;
    }
};
int main()
{

	system("pause");

	return 0;
}