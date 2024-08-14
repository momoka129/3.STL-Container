#include<iostream>
using namespace std;
#include<list>

void printList(list<int> &l){
    for(list<int>::const_iterator it = l.begin(); it != l.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}

void test01(){

    list<int> l;

    l.push_back(10);
    l.push_back(20);
    l.push_back(20);
    l.push_back(40);

    printList(l);

    list<int> l2;
    l2 = l;
    printList(l2);

    list<int> l3;
    l3.assign(l2.begin(), l2.end());
    printList(l3);

    list<int> l4;
    l4.assign(10, 100);
    printList(l4);
}

void test02(){

    list<int> l1;

    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(20);
    l1.push_back(40);

    list<int> l2;
    l2.assign(8, 9);

    cout<<"Before swaping: "<<endl;
    printList(l1);
    printList(l2);

    l1.swap(l2);

    cout<<"After swaping: "<<endl;
    printList(l1);
    printList(l2);
}

int main(){

    test01();

    test02();

    return 0;
}