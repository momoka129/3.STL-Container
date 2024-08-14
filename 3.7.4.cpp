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
    
    if(l.empty()){
        cout<<"The list is empty."<<endl;
    }
    else{
        cout<<"The list is occupied."<<endl;
        cout<<"The number of the elements of the list: "<<l.size()<<endl;
    }

    //resize
    l.resize(10, 555);
    printList(l);

    l.resize(2);
    printList(l);

}

int main(){
    
    test01();

    return 0;
}