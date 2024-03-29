#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<stack>
#include<list>
class MyHashSet 
{
private:
    static const int hashnumber = 769;
    vector<list<int>>data;
    static int hash(int key) 
    {
        return key % hashnumber;
    }

public:
    MyHashSet() :data(hashnumber) {}//function body is empty,when it's initial,data has been initialized

    void add(int key) 
    {
        int h = hash(key);
        for (list<int>::iterator it = data[h].begin(); it != data[h].end(); it++)
        {
            if ((*it) == key) 
            {
                return;
            }
        }
        data[h].push_back(key);
    }

    void remove(int key) 
    {
        int h = hash(key);
        for (auto it = data[h].begin(); it != data[h].end(); it++) 
        {
            if ((*it) == key) 
            {
                data[h].erase(it);
                return;
            }
        }
    }

    bool contains(int key) 
    {
        int h = hash(key);
        for (auto it = data[h].begin(); it != data[h].end(); it++) 
        {
            if ((*it) == key) 
            {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
int main() 
{
	return 0;
}