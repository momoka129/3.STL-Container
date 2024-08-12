#include<iostream>
using namespace std;
#include<deque>

void test01(){
    deque<int> d1;
    for(int i = 0; i < 10; i++){
        d1.push_back(i);
    }

    cout<<d1[3]<<endl;
    cout<<d1.at(7)<<endl;

    cout<<"first: "<<d1.front()<<endl;
    cout<<"last: "<<d1.back()<<endl;

}

int main(){

    test01();

    return 0;
}