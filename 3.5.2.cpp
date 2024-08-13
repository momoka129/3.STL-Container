#include<iostream>
using namespace std;
#include<stack>

//栈stack容器
void test01(){

    //fifo
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    while(!s.empty()){

        //查看栈顶元素
        cout<<"top element of the stack: "<<s.top()<<endl;

        //pop
        s.pop();

        cout<<"size of the stack rn: "<<s.size()<<endl;

        cout<<endl;
    }
}

int main(){

    test01();

    return 0;

}