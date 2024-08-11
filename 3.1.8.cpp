#include<iostream>
using namespace std;

void test01(){
    string str = "hello";

    //insert
    str.insert(1,"111");
    cout<<str<<endl;    //h111ello   

    //delete
    str.erase(1,3);
    cout<<str<<endl;
}

int main(){
    test01();
    return 0;
}