#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    // ! 向量
    vector<int> vec1;
    vector<int> vec2(vec1);  
    vector<int> vec3(vec1.begin(),vec1.end());
    vector<int> vec4(10);
    vector<int> vec5(10,4);

    vec1.push_back(100); // ! 尾部添加元素
    int size = vec1.size();   // ! 元素个数
    bool isEmpty = vec1.empty(); // ! 判断是否为空
    cout<<vec1[0]<<endl;
    vec1.insert(vec1.end(),5,3);    // ! 从vec1.back位置插入5个值为3的元素
    vec1.pop_back();  // ! 删除末尾元素
    vec1.erase(vec1.begin(),vec1.begin()+2);// ! 删除vec1[0]-vec1[2]之间的元素，不包括vec1[2],其他元素前移!!
    cout<<(vec1==vec2)?true:false;  // ! 判断两个数组是否相等
    vector<int>::iterator iter = vec1.begin();    // ! 获取迭代器首地址，可读可写
    vector<int>::const_iterator c_iter = vec1.begin();   // !获取const类型迭代器，只读
    vec1.clear();// !清空元素

    sort(vec1.begin(), vec1.end());
    reverse(vec1.begin(), vec1.end());
    find(vec1.begin(), vec2.end(), 10); // ! 找10返回下标

    int length = vec1.size();
    for(int i=0;i<length;i++)
    {
        cout<<vec1[i];
    }
    cout<<endl<<endl;
    // ! 迭代器法
    vector<int>::iterator iter = vec1.begin();
    for(;iter != vec1.end();iter++)
    {
    cout<<*iter;
    cout<<*iter<<endl;
    }
}
