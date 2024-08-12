#include<iostream>
#include<deque>
using namespace std;
#include<algorithm>

void printDeque(const deque<int> &d){
    for(deque<int>::const_iterator it = d.begin(); it != d.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}

void test01(){

    deque<int> d;
    d.push_back(16);
    d.push_back(414);
    d.push_back(7);
    d.push_front(555);

    printDeque(d);

    //默认ascending order
    //对于支持随机访问迭代器的容器 都可以使用sort函数
    sort(d.begin(), d.end());
    printDeque(d);
}

int main(){

    test01();

    return 0;
}