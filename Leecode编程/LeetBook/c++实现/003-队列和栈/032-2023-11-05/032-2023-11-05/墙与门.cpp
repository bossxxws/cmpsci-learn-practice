#include <iostream>
using namespace std;
#include<vector>
#include<queue>
class Step {
public:
    int x;
    int y;
    int step;
    Step(int x, int y, int step) {
        this->x = x;
        this->y = y;
        this->step = step;
    }
};
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size();
        int n = rooms[0].size();

        queue<Step> q;
        //put every gate into queue
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rooms[i][j] == 0) {
                    //i and j are gate's position
                    Step temp(i, j, 0);
                    q.push(temp);
                }
            }
        }

        while (!q.empty()) {
            //handle the earliest door
            Step current = q.front();
            q.pop();
            int i = current.x;
            int j = current.y;
            if (i - 1 >= 0 && current.step + 1 < rooms[i - 1][j]) {
                rooms[i - 1][j] = current.step + 1;
                Step s(i - 1, j, rooms[i - 1][j]);
                q.push(s);
                //q.push(new Step(i-1, j, rooms[i-1][j]));
            }
            if (i + 1 < m && current.step + 1 < rooms[i + 1][j]) {
                rooms[i + 1][j] = current.step + 1;
                Step s(i + 1, j, rooms[i + 1][j]);
                q.push(s);
                //q.push(new Step(i+1, j, rooms[i+1][j]));
            }
            if (j - 1 >= 0 && current.step + 1 < rooms[i][j - 1]) {
                rooms[i][j - 1] = current.step + 1;
                Step s(i, j - 1, rooms[i][j - 1]);
                q.push(s);
                //q.push(new Step(i, j-1, rooms[i][j-1]));
            }
            if (j + 1 < n && current.step + 1 < rooms[i][j + 1]) {
                rooms[i][j + 1] = current.step + 1;
                Step s(i, j + 1, rooms[i][j + 1]);
                q.push(s);
                //q.push(new Step(i, j+1, rooms[i][j+1]));
            }
        }
    }
};
int main()
{

	system("pause");

	return 0;
}