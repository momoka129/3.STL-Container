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

    //append to the end
    l.push_back(10);
    l.push_back(20);
    l.push_back(20);
    l.push_back(40);

    //prepend
    l.push_front(100);
    l.push_front(200);
    l.push_front(300);

    printList(l);

    //remove from the end
    l.pop_back();
    printList(l);

    //remove from the front
    l.pop_front();
    printList(l);

    //insert
    list<int>::iterator it = l.begin();
    l.insert(++it, 1000);
    printList(l);

    //delete
    l.erase(it);        //it is still point to 100
    printList(l);

    //remove
    l.remove(20);
    printList(l);

    //clear
    l.clear();
    printList(l);
}

int main(){

    test01();

    return 0;
}