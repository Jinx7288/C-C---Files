#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include<stdio.h>
using namespace std;
int main()
{
    int item = 10;
    queue<int> q;
    queue<int, vector<int>> stk; //覆盖默认，使用vector实现队列
    q.empty();  //判断队列是否为空，为空返回true，否则返回false 
    q.size(); // !返回队列中元素的个数 
    q.front(); // !返回队首元素的值，但不删除
    q.back(); // !返回队尾元素的值，但不删除
    q.push(item); // !在队尾加入新元素item
    q.pop(); // !删除队首元素，但不返回其值
    // q.emplace(q.back(),20);
}