#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<stack>
#include<unordered_set>
#include<string>
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> A;
        unordered_set<string> D = { "+","-","*","/" };
        int num = tokens.size();
        for (int i = 0; i < num; i++) {
            if (D.count(tokens[i])) {
                int B = A.top(); A.pop();
                int C = A.top(); A.pop();
                if (tokens[i] == "+")  A.push(C + B);
                else if (tokens[i] == "-")  A.push(C - B);
                else if (tokens[i] == "*")  A.push(C * B);
                else A.push(C / B);
            }
            else A.push(stoi(tokens[i]));
        }
        return A.top();
    }
};

int main() 
{
	return 0;
}