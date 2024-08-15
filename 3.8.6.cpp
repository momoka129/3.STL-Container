#include<iostream>
#include<set>
using namespace std;

void printSet(set<int> &s){
    for(set<int>::iterator it = s.begin(); it != s.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}

void printMultiset(multiset<int> &s){
    for(multiset<int>::iterator it = s.begin(); it != s.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}


void test01(){

    set<int> s1;

    s1.insert(10);
    s1.insert(10);

    printSet(s1);
    
    multiset<int> s;
    s.insert(10);
    s.insert(10);

    printMultiset(s);

}

int main(){

    test01();

    return 0;

}