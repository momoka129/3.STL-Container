#include<iostream>
using namespace std;
#include<set>

void printSet(set<int> &s){
    for(set<int>::iterator it = s.begin(); it != s.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}

void test01(){

    set<int> s1;

    //only insert one way to add data
    s1.insert(10);
    s1.insert(20);
    s1.insert(30);
    s1.insert(40);

    //traverse set
    printSet(s1);

    if(s1.empty()){
        cout<<"empty."<<endl;
    }
    else{
        cout<<"not empty."<<endl;
        cout<<"size: "<<s1.size()<<endl;
    }
    
}

void test02(){

     set<int> s1;

    //only insert one way to add data
    s1.insert(10);
    s1.insert(20);
    s1.insert(30);
    s1.insert(40);

    set<int> s2;

    s2.insert(4);
    s2.insert(28);
    s2.insert(61);
    s2.insert(89);

    cout<<"before: "<<endl;
    printSet(s1);
    printSet(s2);

    s1.swap(s2);
    cout<<"after: "<<endl;
    printSet(s1);
    printSet(s2);
}

int main(){

    test01();

    test02();

    return 0;
}