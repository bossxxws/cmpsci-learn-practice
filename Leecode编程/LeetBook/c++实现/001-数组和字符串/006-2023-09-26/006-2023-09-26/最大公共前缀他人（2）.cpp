//#include <iostream>
//using namespace std;
//#include<vector>
//class Solution {
//public:
//    string longestCommonPrefix(vector<string>& strs) {
//        string out;
//        if (strs.empty()) return out;
//        // ��С���ȣ���strs[0]�Ƚ�j
//        for (int j = 0; j < strs[0].length(); j++) {
//            for (int i = 1; i < strs.size(); i++) {
//                if (j > strs[i].length() - 1 || strs[i][j] != strs[0][j]) {
//                    return out;
//                }
//            }
//            out.append(1, strs[0][j]);
//        }
//        return out;
//    }
//};
//
//
//int main()
//{
//
//	system("pause");
//
//	return 0;
//}