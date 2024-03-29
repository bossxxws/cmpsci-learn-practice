//#include <iostream>
//using namespace std;
//#include<vector>
//
//class Solution 
//{
//public:
//	void reverseString(vector<char> &s) 
//	{
//		int j = s.size()-1;
//		int i = 0;
//		char temp;
//		for (int n = 0; n < s.size()/2; n++) 
//		{
//			temp = s[j];
//			s[j] = s[i];
//			s[i] = temp;
//			i++;
//			j--;
//		}
//	}
//};
//
//int main()
//{
//	vector<char> v = { 'h', 'e', 'l', 'l', 'o' };
//	Solution s1;
//	cout << v.size() << endl;
//	s1.reverseString(v);
//	int m = v.size();
//	for (vector<char>::iterator it = v.begin(); it != v.end(); it++) 
//	{
//		cout << *it << endl;
//	}
//	
//
//	system("pause");
//
//	return 0;
//}


//      别人更短时间的
//class Solution {
//public:
//    void reverseString(vector<char>& s) {
//        int i = 0;
//        int len = s.size();
//
//        while (i <= (len - 1) / 2) {
//            char tmp = s[i];
//
//            s[i] = s[len - i - 1];
//            s[len - i - 1] = tmp;
//            i++;
//        }
//    }
//};