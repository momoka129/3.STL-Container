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
    for(int i = 0; i < 10; i++){
        d1.push_back(i);
    }

    printDeque(d1);

    if(d1.empty()){
        cout<<"deque is empty."<<endl;
    }
    else{
        cout<<"deque is not empty."<<endl;
        cout<<"size: "<<d1.size()<<endl;
        //deque没有容量概念
    }

    //重新指定大小
    d1.resize(15,1);
    printDeque(d1);

    d1.resize(5);
    printDeque(d1);
}

int main(){

    test01();

    return 0;
}