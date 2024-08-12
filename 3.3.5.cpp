#include<iostream>
using namespace std;
#include<deque>

void printDeque(const deque<int> &d){
    for(deque<int>::const_iterator it = d.begin(); it != d.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}

void test01(){

    deque<int> d1;
    
    //尾插
    d1.push_back(10);
    d1.push_back(11);

    //头插
    d1.push_front(4);

    printDeque(d1);

    //尾删
    d1.pop_back();
    printDeque(d1);

    //头删
    d1.pop_front();
    printDeque(d1);

}

void test02(){
    
    deque<int> d;
    d.push_back(10);
    d.push_back(20);
    d.push_front(100);
    d.push_front(200);

    //200 100 10 20
    printDeque(d);

    //insert
    d.insert(d.begin(), 1000);
    printDeque(d);

    d.insert(d.begin(),3,99);
    printDeque(d);

    //按照区间插入
    deque<int> d2;
    d2.push_back(1);
    d2.push_back(2);
    d2.push_back(3);

    //1 2 3 99 99 99 1000 200 100 10 20
    d.insert(d.begin(),d2.begin(),d2.end());
    printDeque(d);


    //删除
    deque<int>::iterator it = d.begin();
    it++;
    d.erase(it);
    printDeque(d);

    //按区间方式删除
    it++;
    d.erase(d.begin(), it);
    printDeque(d);

    d.clear();
    printDeque(d);
}

int main(){

    test01();

    test02();

    return 0;
}