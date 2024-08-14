#include<iostream>
#include<set>
using namespace std;

class myCompare{
public:
    bool operator()(int v1, int v2){
        return v1 > v2;
    }
};

void printSet(set<int, myCompare> &s){
    for(set<int, myCompare>::iterator it = s.begin(); it != s.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}

void test01(){

    //before insert
    set<int, myCompare> s1;

    s1.insert(10);
    s1.insert(20);
    s1.insert(30);
    s1.insert(40);
    s1.insert(50);

    printSet(s1);

}

int main(){

    test01();

    return 0;
}