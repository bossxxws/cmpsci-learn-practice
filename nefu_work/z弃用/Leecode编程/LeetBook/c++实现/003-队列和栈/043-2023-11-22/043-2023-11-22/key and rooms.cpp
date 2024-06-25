#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<stack>
class Solution
{
public:
    queue<int>roomn;
    bool canVisitAllRooms(vector<vector<int>>& rooms)
    {
        int res = 0;
        int n = rooms.size();
        roomn.push(0);//deal with rooms
        vector<int>seen(n);//visit rooms
        seen[0] = 1;
        while (!roomn.empty())
        {
            int f = roomn.front();
            roomn.pop();
            res++;
            for (int i = 0; i < rooms[f].size(); i++) 
            {
                if (!seen[rooms[f][i]]) 
                {
                    roomn.push(rooms[f][i]);
                    seen[rooms[f][i]] = 1;
                }
            }
        }
        return res==n ;
    }

};
int main() 
{
	return 0;
}