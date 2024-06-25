#include <iostream>
using namespace std;
#include<vector>
#include<queue>
struct TreeNode {
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
	//initialize a vector to storage result
	vector<vector<int>>res;
	//initial a queue to storage tree leaves
	queue<TreeNode*>q;
	vector<vector<int>> levelOrder(TreeNode* root) 
	{
		if (!root) { return vector<vector<int>>(); }
		//put root in queue
		q.push(root);
		//if queue is not empty,do it
		while (!q.empty()) 
		{
			//push a  array to res
			res.push_back(vector<int>());
			int size = q.size();
			for (int i = 0; i < size; i++) 
			{
				//tem is the earliest root
				TreeNode* tem = q.front();
				//pop the  value
				q.pop();
				//push the earliest root's value value to res
				res.back().push_back(tem->val);
				if (tem->left) { q.push(tem->left); }
				if (tem->right) { q.push(tem->right); }
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