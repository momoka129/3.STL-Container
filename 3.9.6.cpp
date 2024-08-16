#include<iostream>
using namespace std;
#include<map>

class myCompare{
public:
    bool operator()(int v1, int v2){
        //descending order
        return v1 > v2;
    }
};

void printMap(map<int,int,myCompare> &m){
    for(map<int,int,myCompare>::iterator it = m.begin(); it != m.end(); it++){
        cout<<"key = "<<it->first<<"\tvalue: "<<it->second<<endl;
    }
    cout<<endl;
}

void test01(){

    map<int,int,myCompare> m;

    m.insert(pair<int,int>(1,10));
    m.insert(pair<int,int>(2,20));
    m.insert(pair<int,int>(3,30));
    m.insert(pair<int,int>(4,40));

    printMap(m);
}

int main(){

    test01();

    return 0;
}