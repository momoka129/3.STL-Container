#include<iostream>
#include<set>
using namespace std;

class Person{
public:
    Person(string name, int age){
        this->m_age = age;
        this->m_name = name;
    }

    string m_name;
    int m_age;
};

class comparePerson{
public:
    bool operator()(const Person &p1, const Person &p2){
        return p1.m_age > p2.m_age;
        
    }

};

void test01(){

    set<Person, comparePerson> s;

    Person p1("liubei", 24);
    Person p2("guanyu", 28);
    Person p3("zhangfei", 25);

    s.insert(p1);
    s.insert(p2);
    s.insert(p3);

    for(set<Person>::iterator it = s.begin(); it != s.end(); it++){
        cout<<"Name: "<<it->m_name<<"\tage: "<<it->m_age<<endl;
    }
}

int main(){

    test01();

    return 0;
}
