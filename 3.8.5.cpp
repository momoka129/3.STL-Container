#include<iostream>
#include<set>
using namespace std;

void test01(){

    set<int> s1;

    s1.insert(10);
    s1.insert(20);
    s1.insert(30);
    s1.insert(40);
    s1.insert(50);

    int f = 300;
    set<int>::iterator pos = s1.find(f);
    if(pos != s1.end()){
        cout<<*pos<<" is found."<<endl;
    }
    else{
        cout<<"not found."<<endl;
    }
    
}

void test02(){
    set<int> s1;

    s1.insert(10);
    s1.insert(20);
    s1.insert(30);
    s1.insert(40);
    s1.insert(50);

    int num = s1.count(30);
    cout<<num<<endl;

}

int main(){

    test01();

    test02();

    return 0;
}