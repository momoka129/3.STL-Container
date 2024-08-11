#include<iostream>
using namespace std;

void test01(){
    string str1 = "I";
    str1 += " am good";
    cout<<str1<<endl;

    str1 += '\0';
    cout<<str1<<endl;

    string str2 = " at sleeping.";
    str1 += str2;
    cout<<str1<<endl;

    string str3 = "I";
    str3.append(" love ");

    cout<<str3<<endl;

    str3.append("game foewgfw",4);
    cout<<str3<<endl;

    str3.append(str2);
    cout<<str3<<endl;

    str3.append(str1,1,2);
    cout<<str3<<endl;
}

int main(){
    test01();
    return 0;
}