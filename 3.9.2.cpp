#include<iostream>
#include<map>
using namespace std;

void printMap(map<int, int> &m){
    for(map<int, int>::iterator it = m.begin(); it != m.end(); it++){
        cout<<it->first<<"\t"<<it->second<<endl;
    }
    cout<<endl;
}

void test01(){

    map<int, int> m;

    m.insert(pair<int, int>(1,10));
    m.insert(pair<int, int>(11,6));
    m.insert(pair<int, int>(1,30));

    printMap(m);
    //1     10
    //11    6

    map<int, int> m2(m);
    printMap(m2);

    map<int, int> m3;
    m3 = m2;
    printMap(m3);

}

int main(){

    test01();

    return 0;
    
}