#include<algorithm>
#include<iostream>
#include<stack>
#include<vector>
#include<stdio.h>
using namespace std;
int main()
{
    int item = 10;
    stack<int> s;
    stack<int, vector<int>> stk; //覆盖默认，使用vector实现stk 
    s.empty();  //判断stack是否为空，为空返回true，否则返回false 
    s.size(); // !返回stack中元素的个数 
    s.pop(); // !删除栈顶元素，但不返回其值 
    s.top(); // !返回栈顶元素的值，但不删除此元素 
    s.push(item); // !在栈顶压入新元素item
}