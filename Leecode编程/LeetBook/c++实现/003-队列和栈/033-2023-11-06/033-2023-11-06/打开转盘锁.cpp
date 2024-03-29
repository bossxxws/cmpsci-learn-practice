#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<unordered_set>
#include<algorithm>
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        if (target == "0000") {
            return 0;
        }//if the target is 0000,just return step '0'

        unordered_set<string> dead(deadends.begin(), deadends.end());
        if (dead.count("0000")) {
            //method count() return  times the element appears in unordered_set(无序集合) 
            //but for unordered set,it can only be 0(do not exist) or 1(exist)
            return -1;
        }//if the dead number is 0000,it fails

        auto num_prev = [](char x) -> char {
            return (x == '0' ? '9' : x - 1);
            };
        auto num_succ = [](char x) -> char {
            return (x == '9' ? '0' : x + 1);
            };

        // 枚举 status 通过一次旋转得到的数字 (all)
        auto get = [&](string& status) -> vector<string>
            {
                vector<string> ret;
                for (int i = 0; i < 4; ++i)//for each digit in 4 digits
                {
                    char num = status[i];//record num
                    status[i] = num_prev(num);//the i-1 digit go back
                    ret.push_back(status);
                    status[i] = num_succ(num);//the i-1 digit go forward
                    ret.push_back(status);
                    status[i] = num;//reset status[i] as num
                }
                return ret;
            };

        queue<pair<string, int>> q;
        q.emplace("0000", 0);
        unordered_set<string> seen = { "0000" };

        while (!q.empty())
        {
            auto [status, step] = q.front();
            q.pop();
            for (auto&& next_status : get(status))
            {
                if (!seen.count(next_status) && !dead.count(next_status))
                {
                    if (next_status == target)
                    {
                        return step + 1;
                    }
                    q.emplace(next_status, step + 1);//put the new status in queue,go on spinning
                    seen.insert(move(next_status));
                }
            }
        }
        return -1;
    }
};


int main() 
{
	return 0;
}