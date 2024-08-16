#include<iostream>
using namespace std;
#include<map>

void printMap(map<int,int> &m){
    for(map<int,int>::iterator it = m.begin(); it != m.end(); it++){
        cout<<"key = "<<it->first<<"\tvalue: "<<it->second<<endl;
    }
    cout<<endl;
}

void test01(){
    map<int, int> m;

    m.insert(pair<int,int>(1,10));
    m.insert(pair<int,int>(2,10));
    m.insert(pair<int,int>(3,10));

    if(m.empty()){
        cout<<"empty."<<endl;
    }
    else{
        cout<<"not empty."<<endl;
        cout<<"size: "<<m.size()<<endl;
    }

    map<int, int> m2;

    m2.insert(pair<int,int>(6,190));
    m2.insert(pair<int,int>(5,106));
    m2.insert(pair<int,int>(4,101));

    cout<<"before: "<<endl;
    printMap(m);
    printMap(m2);

    m.swap(m2);

    cout<<"after: "<<endl;
    printMap(m);
    printMap(m2);
}

int main(){

    test01();

    return 0;
}