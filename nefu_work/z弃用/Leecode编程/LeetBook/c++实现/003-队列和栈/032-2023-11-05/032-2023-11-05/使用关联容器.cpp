#include <iostream>
using namespace std;
#include<map>
#include<set>
#include<unordered_map>
map<string, size_t> word_count;
string word;
int main()
{
	//version 1
	//while (cin >> word)
	//{
	//	++word_count[word];
	//}
	//for (const auto& w : word_count)//for each element in map
	//{
	//	cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times " : " time ") << endl;
	//}
	//version 2
	while (cin >> word) 
	{
		//if word has been already in word_count,do nothing
		pair<map<string,size_t>::iterator,bool> ret = word_count.insert({ word,1 });
		//if insert successfully ,it will return a pair
		//or it will return null(false)
		if (!ret.second)//check the return value whether insert operation is success or not ,if false,then word has been in word_count,then second++
		{
			ret.first->second++;
		}
	}
	for (const auto& w : word_count)//for each element in map
	{
		cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times " : " time ") << endl;
	}
	pair<int, int>v;
	v.first = 1;
	v.second = 2;
	cout << v.second << endl;
	cout << word_count.size() << endl;
	system("pause");
	return 0;
}