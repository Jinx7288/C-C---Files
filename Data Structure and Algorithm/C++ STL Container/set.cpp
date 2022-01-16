#include <iostream>
#include <set>
#include <string>
using namespace std;
/* 仿函数CompareSet，在test02使用 */
class CompareSet
{
public:
    //从大到小排序
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
    }
    //从小到大排序
    // bool operator()(int v1, int v2)
    //{
    // return v1 < v2;
    //}
};
/* Person类，用于test03 */
class Person
{
    friend ostream &operator<<(ostream &out, const Person &person);

public:
    Person(string name, int age)
    {
        mName = name;
        mAge = age;
    }

public:
    string mName;
    int mAge;
};
ostream &operator<<(ostream &out, const Person &person)
{
    out << "name:" << person.mName << " age:" << person.mAge << endl;
    return out;
}
/* 仿函数ComparePerson,用于test03 */
class ComparePerson
{
public:
    //名字大的在前面，如果名字相同，年龄大的排前面
    bool operator()(const Person &p1, const Person &p2)
    {
        if (p1.mName == p2.mName)
        {
            return p1.mAge > p2.mAge;
        }
        return p1.mName > p2.mName;
    }
};
/* 打印set类型的函数模板 */
template <typename T>
void PrintSet(T &s)
{
    for (T::iterator iter = s.begin(); iter != s.end(); ++iter)
        cout << *iter << " ";
    cout << endl;
}
void test01()
{
    // set容器默认从小到大排序
    set<int> s;
    s.insert(10);
    s.insert(20);
    s.insert(30);
    //输出set
    PrintSet(s);
    //结果为:10 20 30
    /* set的insert函数返回值为一个对组(pair)。
    对组的第一个值first为set类型的迭代器：
    1、若插入成功，迭代器指向该元素。
    2、若插入失败，迭代器指向之前已经存在的元素
    对组的第二个值seconde为bool类型：
    1、若插入成功，bool值为true
    2、若插入失败，bool值为false
    */
    pair<set<int>::iterator, bool> ret = s.insert(40);
    if (true == ret.second)
        cout << *ret.first << " 插入成功" << endl;
    else
        cout << *ret.first << " 插入失败" << endl;
}
void test02()
{
    /* 如果想让set容器从大到小排序，需要给set容
    器提供一个仿函数,本例的仿函数为CompareSet
    */
    set<int, CompareSet> s;
    s.insert(10);
    s.insert(20);
    s.insert(30);
    //打印set
    PrintSet(s);
    //结果为:30,20,10
}
void test03()
{
    /* set元素类型为Person，当set元素类型为自定义类型的时候
    必须给set提供一个仿函数，用于比较自定义类型的大小，
    否则无法通过编译
    */
    set<Person, ComparePerson> s;
    s.insert(Person("John", 22));
    s.insert(Person("Peter", 25));
    s.insert(Person("Marry", 18));
    s.insert(Person("Peter", 36));
    //打印set
    PrintSet(s);
}
int main(void)
{
    // test01();
    // test02();
    // test03();
    return 0;
}