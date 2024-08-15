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
    s1.insert(2);
    s1.insert(30);
    s1.insert(40);
    s1.insert(2);

    //traverse set
    printSet(s1);

    //copy constructor
    set<int> s2(s1);
    printSet(s2);


    //operator=
    set<int> s3;
    s3 = s2;
    printSet(s3);
    
}

int main(){

    test01();

    return 0;
}