#include<iostream>
using namespace std;

void test01(){
    string str = "hello";

    //cout<<str<<endl;

    //[]
    for(int i = 0; i < str.size(); i++){
        cout<<str[i]<<endl;
    }

    //at
    for(int i = 0; i < str.size(); i++){
        cout<<str.at(i)<<endl;
    }

    //modify
    str[2] = 'x';
    cout<<str<<endl;        //hexlo

    str.at(1) = '8';
    cout<<str<<endl;        //h8xlo
}

int main(){
    test01();
    return 0;
}