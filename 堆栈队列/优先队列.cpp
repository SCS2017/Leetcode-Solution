// #include <iostream>
// #include <queue>
// #include <ctime>
// #include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;

bool myCmp(int a, int b){
    return a % 10 < b % 10;
}

// 自定义比较函数有两种方式，一种是自定义cmp结构体
// 重载operator()
struct cmp{
    bool operator() (int a, int b ){
        return a < b;
    }
};

// 第二种是自定义函数，初始化pq时按照如下方式定义
// priority_queue<int, vector<int>, function<bool(int, int)> > pq3(myCmp);

int main()
{
    ios::sync_with_stdio(false);
    srand(time(NULL));
    //优先队列的底层实现为最大、最小堆
    //默认为最大优先队列
    priority_queue<int> pq1;
    //最小优先队列
    priority_queue<int, vector<int>, greater<int> > pq2;

    //自定义比较
    // priority_queue<int, vector<int>, function<bool(int, int)> > pq3(myCmp);
    for(int i = 0; i < 10; ++i){
        int num = rand() % 100;
        pq2.push(num);
        cout << "insert " << num << " in priority queue." << endl;
    }
    while(! pq2.empty()){
        cout << pq2.top() << " ";
        pq2.pop();
    }
    cout << endl;
    return 0;
}