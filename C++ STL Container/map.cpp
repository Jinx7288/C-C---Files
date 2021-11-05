#include <iostream>
#include <map>
using namespace std;
int main()
{
    map<char, int> mymap;
    // 插入单个值
    mymap.insert(pair<char, int>('a', 100));
    mymap.insert(pair<char, int>('z', 200));
    //返回插入位置以及是否插入成功
    pair<map<char, int>::iterator, bool> ret;
    ret = mymap.insert(pair<char, int>('z', 500));
    if (ret.second == false)
    {
        cout << "element 'z' already existed";
        cout << " with a value of " << ret.first->second << '\n';
    }
    //指定位置插入
    map<char, int>::iterator it = mymap.begin();
    mymap.insert(it, pair<char, int>('b', 300)); //效率更高
    mymap.insert(it, pair<char, int>('c', 400)); //效率非最高
    //范围多值插入
    map<char, int> anothermap;
    anothermap.insert(mymap.begin(), mymap.find('c'));
    // 列表形式插入
    anothermap.insert({{'d', 100}, {'e', 200}});
    return 0;
}