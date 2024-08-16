#include<iostream>
#include<map>
using namespace std;

void test01(){

    map<int,int> m;
    
    m.insert(make_pair(1,10));
    m.insert(make_pair(2,20));
    m.insert(make_pair(3,30));
    
    //find
    //reminder: find() function returns iterator
    map<int,int>::iterator pos = m.find(3);

    if(pos != m.end()){
        cout<<"found. value = "<<pos->second<<endl;
    }
    else{
        cout<<"not found"<<endl;
    }

    //count
    int num = m.count(3);
    cout<<"number of k3y: "<<num<<endl;
}

int main(){

    test01();

    return 0;
}