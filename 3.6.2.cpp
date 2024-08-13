#include<iostream>
using namespace std;
#include<queue>

class Person{
public:
    Person(string name, int age){
        this->Age = age;
        this->Name = name;
    }

    string Name;
    int Age;
};

void test01(){

    //create queue
    queue<Person> q;

    //prepare data
    Person P1("TANGSENG", 30);
    Person p2("SUNWUKONG", 1000);
    Person p3("ZHUBAJIE", 900);
    Person p4("SHANSENG", 800);

    //入队
    q.push(P1);
    q.push(p2);
    q.push(p3);
    q.push(p4);

    while(!q.empty()){
        cout<<"First person name: "<<q.front().Name<<endl;
        cout<<"Last person age: "<<q.back().Age<<endl;
        cout<<endl;
        q.pop();
    }

    cout<<"Queue size: "<<q.size()<<endl;
}

int main(){

    test01();

    return 0;
}