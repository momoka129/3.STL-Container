#include<iostream>
using namespace std;

void test01(){

    pair<string, int> p("Tom", 20);

    cout<<"Name: "<<p.first<<"\tAge: "<<p.second<<endl;

    pair<string, int> p2 = make_pair("Jerry", 30);
    cout<<"Name: "<<p2.first<<"\tAge: "<<p2.second<<endl;

}

int main(){

    test01();

    return 0;

}