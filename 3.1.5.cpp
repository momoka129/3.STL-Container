#include<iostream>
using namespace std;

//find,rfind
void test01(){
    string str1 = "abcdefgde";

    int pos = str1.find("df");
    
    if(pos == -1){
        cout<<"not found!"<<endl;
    }
    cout<<"pos = "<<pos<<endl;

    pos = str1.rfind("de");
    cout<<"pos = "<<pos<<endl;
}

//replace
void test02(){
    string str1 = "abcdefg";

    //从一号位置起 三个字符替换为1111
    str1.replace(1,3,"1111");

    cout<<str1<<endl;
}

int main(){

    test01();
    test02();

    return 0;
}