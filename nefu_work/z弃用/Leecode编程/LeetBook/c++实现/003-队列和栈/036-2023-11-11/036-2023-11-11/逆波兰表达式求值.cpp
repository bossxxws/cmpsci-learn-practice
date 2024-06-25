#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<stack>
#include<string>
class Solution {
public:
    int evalRPN(vector<string>& tokens)
    {
        stack<int>s;
        //push elements in vector in stack,and if it's operator,calculate two numbers and push the value in stack
        while (!tokens.empty()) 
        {
            if (isNumber(tokens[0]))
            {
                int va;
                int n1 = s.top();
                s.pop();
                int n2 = s.top();
                s.pop();
                if (tokens[0] == "+") 
                {
                    va = n1 + n2;
                }
                else if (tokens[0] == "-") 
                {
                    va = n2 - n1;
                }
                else if (tokens[0] == "*") 
                {
                    va = n1 * n2;
                }
                else 
                {
                    va = n2 / n1;
                }
                s.push(va);
            }
                
            else 
            {
                s.push(stoi(tokens[0]));
            }
            tokens.erase(tokens.begin());
        }
        int res = s.top();
        return res;
    }
    bool isNumber(string& token) {
        return !(token == "+" || token == "-" || token == "*" || token == "/");
    }
};
int main() 
{
	return 0;
}