#include<iostream>
using namespace std;
#include<list>

class Person{
public:
    Person(string name, int age, int height){
        this->m_age = age;
        this->m_height = height;
        this->m_name = name;
    }

    string m_name;
    int m_age;
    int m_height;
};

void printList(list<Person> &l){
    for(list<Person>::const_iterator it = l.begin(); it != l.end(); it++){
        cout<<"Name: "<<(*it).m_name<<"\tAge: "<<it->m_age<<"\tHeight: "<<it->m_height<<endl;
    }
}

//make sorting rule
bool comparePerson(Person &p1, Person &p2){

    if(p1.m_age == p2.m_age){
        return p1.m_height > p2.m_height;
    }
    //age ascending
    return p1.m_age < p2.m_age;

}

void test01(){

    list<Person> l;

    Person p1("liubei", 35, 175);
    Person p2("caocao", 45, 180);
    Person p3("sunquan", 40, 170);
    Person p4("zhanyun", 25, 190);
    Person p5("zhangfei", 35, 160);
    Person p6("guanyu", 35, 200);

    l.push_back(p1);
    l.push_back(p2);
    l.push_back(p3);
    l.push_back(p4);
    l.push_back(p5);
    l.push_back(p6);

    cout<<"Before sorting: "<<endl;
    printList(l);

    cout<<"------------------------------------"<<endl;

    l.sort(comparePerson);
    cout<<"After sorting: "<<endl;
    printList(l);
}



int main(){

    test01();
    
    return 0;
}