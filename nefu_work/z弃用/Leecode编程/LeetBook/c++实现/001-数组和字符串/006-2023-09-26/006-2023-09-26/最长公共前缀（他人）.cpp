//#include <iostream>
//using namespace std;
//#include<vector>
//class Solution {
//public:
//    string longestCommonPrefix(vector<string>& strs)
//    {
//        string same;
//        same = strs[0];
//        for (int i = 1; i < strs.size(); i++)
//            for (int j = 0; j < same.size(); j++)
//                if (same[j] != strs[i][j])
//                    same.erase(j);
//        return same;
//    }
//};
////可以求出所有前缀，不只是公共的
//
//
//int main()
//{
//
//    vector<string>v2;
//    string strs[3] = { "flower", "flow", "flight" };
//    v2.push_back(strs[0]);
//    v2.push_back(strs[1]);
//    v2.push_back(strs[2]);
//    Solution s;
//    cout << s.longestCommonPrefix(v2) << endl;;
//	system("pause");
//
//	return 0;
//}