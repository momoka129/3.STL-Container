#include<iostream>
using namespace std;

//string的赋值操作
void test01(){
    string str1;
    str1 = "hello";

    string str2;
    str2 = str1;

    string str3;
    str3 = 'a';

    string str4;
    str4.assign("hi");

    string str5;
    str5.assign("avoiewhogvh",5);

    string str6;
    str6.assign(str1);

    string str7;
    str7.assign(7,'a');

    cout<<"str1: "<<str1<<endl;
    cout<<"str2: "<<str2<<endl;
    cout<<"str3: "<<str3<<endl;
    cout<<"str4: "<<str4<<endl;
    cout<<"str5: "<<str5<<endl;
    cout<<"str6: "<<str6<<endl;
    cout<<"str7: "<<str7<<endl;
}

int main(){
    test01();
    return 0;
}