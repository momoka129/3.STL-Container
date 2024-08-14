#include<iostream>
#include<list>
using namespace std;
#include<algorithm>

void printList(list<int> &l){
    for(list<int>::const_iterator it = l.begin(); it != l.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}

bool myCompare(int v1, int v2){
    //descending order
    return v1 > v2;
}

void test01(){

    list<int> l1;

    l1.push_back(94);
    l1.push_back(31);
    l1.push_back(6);
    l1.push_back(22);

    cout<<"Before reversing: "<<endl;
    printList(l1);

    l1.reverse();
    
    cout<<"After reversing: "<<endl;
    printList(l1);
}

void test02(){

    list<int> l;

    l.push_back(20);
    l.push_back(10);
    l.push_back(50);
    l.push_back(40);
    l.push_back(30);

    //all container which do not support random access iterators is cannot use standard algorithm
    //They provide corresponding algorithm internally
    //sort(l.begin(), l.end());

    printList(l);

    //default ascending order
    l.sort();
    printList(l);

    //custom descending order
    l.sort(myCompare);
    printList(l);
}

int main(){

    test01();

    test02();

    return 0;
}