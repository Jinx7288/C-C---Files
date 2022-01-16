#include <bitset>
#include <iostream>
#include <set>
using namespace std;
//假如是结构体的话，需要给结构体设置友元重载<，实现结构体的比较，因为c++结构体本身没有比较大小功能，但是可以设置运算符重载
struct student
{
    int height;
    int weight;
    //排序
    bool friend operator<(const struct student &a, const struct student &b)
    {
        return a.height > b.height; //降序排序
    }
};
int main(int argc, char *argv[])
{
    struct student a = {180, 60};
    struct student b = {170, 55};
    set<struct student> s;
    s.insert(a);
    s.insert(b);
    set<struct student>::iterator it;
    for (it = s.begin(); it != s.end(); it++)
    {
        struct student stu = (struct student)(*it);
        cout << stu.height << " " << stu.weight << endl;
    }
    return 0;
}
    
// std::set_intersection()
// : 这个函数是求两个集合的交集。

// std::set_union() : 求两个集合的并集

// std::set_difference（）：差集

// std::set_symmetric_difference（）：得到的结果是 第一个迭代器相对于第二个的差集 并上第二个相对于第一个的差集 