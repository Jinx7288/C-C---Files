#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include<stdio.h>
using namespace std;
int main()
{
    int item = 10;
    priority_queue<int> q;
    priority_queue<int, vector<int>> stk; //覆盖默认，使用vector实现队列
    priority_queue<int, vector<int>, greater<int>> q2; // ! 设置实现容器，及优先级比较方式，此处越大优先级越高
    priority_queue<int, vector<int>, less<int>> q3; // ! 设置实现容器，及优先级比较方式，此处越小优先级越高
    q.empty();  //判断队列是否为空，为空返回true，否则返回false 
    q.size(); // !返回队列中元素的个数
    q.top(); // ! 返回优先级最高的元素
    q.push(item); // !在队尾加入新元素item
    q.pop(); // !删除队首元素，但不返回其值
    // q.emplace(q.back(),20);
}