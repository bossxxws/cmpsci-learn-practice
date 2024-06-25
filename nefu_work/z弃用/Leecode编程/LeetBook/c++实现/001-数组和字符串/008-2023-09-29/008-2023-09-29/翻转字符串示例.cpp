//#include <iostream>
//using namespace std;
//
//class Solution
//{
//public:
//    string reverseWords(string s)
//    {
//        int N = s.length();
//        int i = 0, j = 0;
//        while (i < N)
//        {
//            while (i < N && s[i] == ' ')
//            {
//                i++;
//            }
//            while (i < N && s[i] != ' ')
//            {
//                swap(s[j++], s[i++]);
//            }
//            j = j + 1;
//        }
//        N = s.length() - 1;
//        while (s[N] == ' ')
//        {
//            N--;
//        }
//        //  È¥³ý¶àÓà¿Õ¸ñ
//        s = s.substr(0, N + 1);
//        reverse(s.begin(), s.end());
//
//        int start = 0, end = 0, tmp;
//        while (start < N)
//        {
//            while (end < N && s[end] != ' ')
//            {
//                end++;
//            }
//            tmp = s[end] == ' ' ? end - 1 : end;
//            while (start < tmp)
//            {
//                swap(s[start++], s[tmp--]);
//            }
//            start = end + 1;
//            end = start;
//        }
//
//        return s;
//    }
//};
//
//
//
//
//
//int main()
//{
//    string s = "The sky           is blue";
//    Solution s1;
//    s=s1.reverseWords(s);
//    cout << s << endl;
//	system("pause");
//
//	return 0;
//}