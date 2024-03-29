#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<unordered_map>

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
class Solution {
public:
    unordered_map<Node*, Node*> visit;
    Node* cloneGraph(Node* node) {
        if (node == nullptr)
            return nullptr;
        Node* newnode;
        if (visit.find(node) == visit.end())//字典中没找到对应的key则说明相应结点未建立，需要更新字典。
        {
            newnode = new Node(node->val);
            visit[node] = newnode;
        }
        else                             //字典中存在该结点则将其直接返回即可。
        {
            newnode = visit[node];
            return newnode;
        }
        for (int i = 0; i < node->neighbors.size(); i++)
        {
            newnode->neighbors.push_back(cloneGraph(node->neighbors[i]));//as it's name,clonegraph function complete the clone of graph
        }
        return newnode;
    }
};


//链接：https ://leetcode.cn/leetbook/read/queue-stack/gmcr6/?discussion=vErCNc
int main() 
{
	return 0;
}