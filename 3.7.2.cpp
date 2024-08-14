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

    //create list default constructor
    list<int> l;

    //add data
    l.push_back(10);
    l.push_back(20);
    l.push_back(20);
    l.push_back(40);

    //traverse list container
    printList(l);

    //Interval mode construction
    list<int> l2(l.begin(), l.end());
    printList(l2);

    //Copy constructor
    list<int> l3(l2);
    printList(l3);

    //n elements
    list<int> l4(10, 1000);
    printList(l4);
}

int main(){

    test01();

    return 0;
}