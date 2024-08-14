#include<iostream>
using namespace std;
#include<list>

void test01(){

    list<int> l;
    
    l.push_back(4);
    l.push_back(5);
    l.push_back(6);

    //l[0] l.at(0) is not usable

    cout<<"Frist element: "<<l.front()<<endl;
    cout<<"Last element: "<<l.back()<<endl;

    list<int>::iterator it = l.begin();

    //不支持随机访问
    //it = it + 1;   

    //支持双向
    it++;
    it--;
}

int main(){

    test01();

    return 0;
}