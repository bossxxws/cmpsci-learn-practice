#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<stack>
class Solution
{
private:
    struct pos
    {
        int x;
        int y;
        pos(int a, int b) 
        {
            this->x = a;
            this->y = b;
        }
    };
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        
        //consider the bride first research
        //from the initial position to around
        queue<pos>qu;
        //size of r
        int r = image.size();
        //size of c
        int c = image[0].size();
        pos p(sr, sc);
        qu.push(p);
        int aim = image[sr][sc];
        if (aim == color) return image;
        while (!qu.empty()) 
        {
            pos k = qu.front();
            qu.pop();
            int pr = k.x;
            int pc = k.y;
            //if is aim,modify color
            if (image[pr][pc] == aim)
            {
                image[pr][pc] = color;
            }
            //upward
            if (pr - 1 >= 0 && image[pr - 1][pc] == aim) 
            {
                pos tem(pr - 1, pc);
                qu.push(tem);
            }
            //downward
            if (pr + 1 < r && image[pr + 1][pc] == aim)
            {
                pos tem(pr +1, pc);
                qu.push(tem);
            }
            //towards the right
            if (pc+1 <c && image[pr][pc+1] == aim)
            {
                pos tem(pr, pc+1);
                qu.push(tem);
            }
            //towards the left
            if (pc -1 >= 0 && image[pr ][pc-1] == aim)
            {
                pos tem(pr , pc-1);
                qu.push(tem);
            }
        }
        return image;

    }
};
int main() 
{
    vector<vector<int>>image;
    image = { {0,0,0,},{0,0,0,},{0,0,0,} };
    int sr = 0;
    int sc = 0;
    int newColor = 0;
    Solution s;
    cout << s.floodFill(image, sr, sc, newColor).capacity() << endl;
	return 0;
}