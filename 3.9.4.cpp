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

    map<int,int> m;

    //4 insert ways 
    m.insert(pair<int,int>(1,10));

    m.insert(make_pair(2,20));

    m.insert(map<int,int>::value_type(3,30));

    m[4] = 40;      //[]not suggest     can use to access correponding value

    printMap(m);

    //delete
    m.erase(m.begin());
    printMap(m);

    m.erase(3);     //based on key 
    printMap(m);

    m.erase(m.begin(), m.end());
    m.clear();
    printMap(m);

}

int main(){

    test01();

    return 0;
}